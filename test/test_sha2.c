#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "sha2.h"

static void test_sha256(void **state) {
  (void) state;
  uint8_t buf[32];
  uint8_t expected[] =
      {0x6e, 0x34, 0x0b, 0x9c, 0xff, 0xb3, 0x7a, 0x98, 0x9c, 0xa5, 0x44, 0xe6, 0xbb, 0x78, 0x0a, 0x2c, 0x78, 0x90, 0x1d,
       0x3f, 0xb3, 0x37, 0x38, 0x76, 0x85, 0x11, 0xa3, 0x06, 0x17, 0xaf, 0xa0, 0x1d};
  buf[0] = 0;
  SHA256_CTX ctx;
  sha256_Init(&ctx);
  sha256_Update(&ctx, buf, 1);
  sha256_Final(&ctx, buf);
  for (int i = 0; i != 32; ++i) {
    assert_int_equal(buf[i], expected[i]);
  }
}

static void test_sha512(void **state) {
  (void) state;
  uint8_t buf[64];
  uint8_t expected[] =
      {0xb8, 0x24, 0x4d, 0x02, 0x89, 0x81, 0xd6, 0x93, 0xaf, 0x7b, 0x45, 0x6a, 0xf8, 0xef, 0xa4, 0xca, 0xd6, 0x3d, 0x28,
       0x2e, 0x19, 0xff, 0x14, 0x94, 0x2c, 0x24, 0x6e, 0x50, 0xd9, 0x35, 0x1d, 0x22, 0x70, 0x4a, 0x80, 0x2a, 0x71, 0xc3,
       0x58, 0x0b, 0x63, 0x70, 0xde, 0x4c, 0xeb, 0x29, 0x3c, 0x32, 0x4a, 0x84, 0x23, 0x34, 0x25, 0x57, 0xd4, 0xe5, 0xc3,
       0x84, 0x38, 0xf0, 0xe3, 0x69, 0x10, 0xee};
  buf[0] = 0;
  SHA512_CTX ctx;
  sha512_Init(&ctx);
  sha512_Update(&ctx, buf, 1);
  sha512_Final(&ctx, buf);
  for (int i = 0; i != 64; ++i) {
    assert_int_equal(buf[i], expected[i]);
  }
}

int main() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_sha256),
      cmocka_unit_test(test_sha512),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}