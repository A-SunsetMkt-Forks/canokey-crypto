#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "sha3.h"

static void test_keccak256(void **state) {
  (void) state;
  uint8_t buf[32];
  uint8_t expected[] =
      {0xbc, 0x36, 0x78, 0x9e, 0x7a, 0x1e, 0x28, 0x14, 0x36, 0x46, 0x42, 0x29, 0x82, 0x8f, 0x81, 0x7d, 0x66, 0x12, 0xf7,
       0xb4, 0x77, 0xd6, 0x65, 0x91, 0xff, 0x96, 0xa9, 0xe0, 0x64, 0xbc, 0xc9, 0x8a};
  buf[0] = 0;
  SHA3_CTX ctx;
  keccak_256_Init(&ctx);
  keccak_Update(&ctx, buf, 1);
  keccak_Final(&ctx, buf);
  for (int i = 0; i != 32; ++i) {
    assert_int_equal(buf[i], expected[i]);
  }
}

static void test_sha3_256(void **state) {
  (void) state;
  uint8_t buf[32];
  uint8_t expected[] =
      {0x5d, 0x53, 0x46, 0x9f, 0x20, 0xfe, 0xf4, 0xf8, 0xea, 0xb5, 0x2b, 0x88, 0x04, 0x4e, 0xde, 0x69, 0xc7, 0x7a, 0x6a,
       0x68, 0xa6, 0x07, 0x28, 0x60, 0x9f, 0xc4, 0xa6, 0x5f, 0xf5, 0x31, 0xe7, 0xd0};
  buf[0] = 0;
  SHA3_CTX ctx;
  sha3_256_Init(&ctx);
  sha3_Update(&ctx, buf, 1);
  sha3_Final(&ctx, buf);
  for (int i = 0; i != 32; ++i) {
    assert_int_equal(buf[i], expected[i]);
  }
}

int main() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_keccak256),
      cmocka_unit_test(test_sha3_256),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}