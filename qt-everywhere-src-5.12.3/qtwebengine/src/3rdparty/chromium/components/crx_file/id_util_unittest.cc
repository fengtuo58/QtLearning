// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/crx_file/id_util.h"

#include <stdint.h>

#include "base/macros.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace crx_file {
namespace id_util {

TEST(IDUtilTest, GenerateID) {
  const uint8_t public_key_info[] = {
      0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
      0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81,
      0x89, 0x02, 0x81, 0x81, 0x00, 0xb8, 0x7f, 0x2b, 0x20, 0xdc, 0x7c, 0x9b,
      0x0c, 0xdc, 0x51, 0x61, 0x99, 0x0d, 0x36, 0x0f, 0xd4, 0x66, 0x88, 0x08,
      0x55, 0x84, 0xd5, 0x3a, 0xbf, 0x2b, 0xa4, 0x64, 0x85, 0x7b, 0x0c, 0x04,
      0x13, 0x3f, 0x8d, 0xf4, 0xbc, 0x38, 0x0d, 0x49, 0xfe, 0x6b, 0xc4, 0x5a,
      0xb0, 0x40, 0x53, 0x3a, 0xd7, 0x66, 0x09, 0x0f, 0x9e, 0x36, 0x74, 0x30,
      0xda, 0x8a, 0x31, 0x4f, 0x1f, 0x14, 0x50, 0xd7, 0xc7, 0x20, 0x94, 0x17,
      0xde, 0x4e, 0xb9, 0x57, 0x5e, 0x7e, 0x0a, 0xe5, 0xb2, 0x65, 0x7a, 0x89,
      0x4e, 0xb6, 0x47, 0xff, 0x1c, 0xbd, 0xb7, 0x38, 0x13, 0xaf, 0x47, 0x85,
      0x84, 0x32, 0x33, 0xf3, 0x17, 0x49, 0xbf, 0xe9, 0x96, 0xd0, 0xd6, 0x14,
      0x6f, 0x13, 0x8d, 0xc5, 0xfc, 0x2c, 0x72, 0xba, 0xac, 0xea, 0x7e, 0x18,
      0x53, 0x56, 0xa6, 0x83, 0xa2, 0xce, 0x93, 0x93, 0xe7, 0x1f, 0x0f, 0xe6,
      0x0f, 0x02, 0x03, 0x01, 0x00, 0x01};
  std::string extension_id =
      GenerateId(std::string(reinterpret_cast<const char*>(&public_key_info[0]),
                             arraysize(public_key_info)));
  EXPECT_EQ("melddjfinppjdikinhbgehiennejpfhp", extension_id);

  EXPECT_EQ("daibjpdaanagajckigeiigphanababab",
            GenerateIdFromHash(public_key_info, sizeof(public_key_info)));

  EXPECT_EQ("jpignaibiiemhngfjkcpokkamffknabf", GenerateId("test"));

  EXPECT_EQ("ncocknphbhhlhkikpnnlmbcnbgdempcd", GenerateId("_"));

  EXPECT_EQ("a", GenerateIdFromHex("_"));

  EXPECT_EQ(
      "bjbdkfoakgmkndalgpadobhgbhhoanhongcmfnghaakjmggnkffgnhmdpfngkeho",
      GenerateIdFromHex(
          "1913a5e0a6cad30b6f03e176177e0d7ed62c5d6700a9c66da556d7c3f5d6a47e"));

  EXPECT_EQ(
      "jimneklojkjdibfkgiiophfhjhbdgcfi",
      GenerateId("this_string_is_longer_than_a_single_sha256_hash_digest"));
}

}  // namespace id_util
}  // namespace crx_file