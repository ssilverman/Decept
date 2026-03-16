// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// encode_data.cpp contains the decoder test data.
// This file is part of the Decept library.

#include <array>
#include <cstddef>

#include "defs.h"

extern const DecodeTestData kDecodeData[]{
    // Invalid encodings
    {
        "ME======="sv,  // 7 padding bytes, not multiple of 8
        std::nullopt,
    },
    {
        "ME====="sv,  // Not multiple of 8
        std::nullopt,
    },
    {
        "MEMEME=="sv,  // 2 padding bytes
        std::nullopt,
    },
    {
        "MEM====="sv,  // 5 padding bytes
        std::nullopt,
    },
    {
        "MF======"sv,  // 6 padding bytes, invalid last value (not div. by 4)
        std::nullopt,
    },
    {
        "MEMF===="sv,  // 4 padding bytes, invalid last value (not div. by 16)
        std::nullopt,
    },
    {
        "MEMEN==="sv,  // 3 padding bytes, invalid last value (not div. by 2)
        std::nullopt,
    },
    {
        "MEMEMEM="sv,  // 1 padding byte, invalid last value (not div. by 8)
        std::nullopt,
    },

    // https://github.com/stesla/base32/blob/master/test/base32_test.rb
    {
        "ME======"sv,
        "a"sv,
    },
    {
        "GEZDGNBV"sv,
        "12345"sv,
    },
    {
        "MFRGGZDF"sv,
        "abcde"sv,
    },
    {
        "EAQCAIBAEBLWKIDUNBSSA4DFN5YGYZJAN5TCA5DIMUQFK3TJORSWIICTORQXIZLTFQQGS3RAN5ZGIZLSEB2G6IDGN5ZG2IDBEBWW64TFEBYGK4TGMVRXIIDVNZUW63RMBIQCAIBAEAQGK43UMFRGY2LTNAQGU5LTORUWGZJMEBUW443VOJSSAZDPNVSXG5DJMMQHI4TBNZYXK2LMNF2HSLBAOBZG65TJMRSSAZTPOIQHI2DFEBRW63LNN5XAUIBAEAQCAIDEMVTGK3TTMUWCA4DSN5WW65DFEB2GQZJAM5SW4ZLSMFWCA53FNRTGC4TFFQQGC3TEEBZWKY3VOJSSA5DIMUQGE3DFONZWS3THOMQG6ZRANRUWEZLSOR4QUIBAEAQCAIDUN4QG65LSONSWY5TFOMQGC3TEEBXXK4RAOBXXG5DFOJUXI6JMEBSG6IDPOJSGC2LOEBQW4ZBAMVZXIYLCNRUXG2BAORUGS4ZAINXW443UNF2HK5DJN5XAUIBAEAQCAIDGN5ZCA5DIMUQFK3TJORSWIICTORQXIZLTEBXWMICBNVSXE2LDMEXAU==="sv,
        "      We the people of the United States, in order to form a more perfect union,\n      establish justice, insure domestic tranquility, provide for the common\n      defense, promote the general welfare, and secure the blessings of liberty\n      to ourselves and our posterity, do ordain and establish this Constitution\n      for the United States of America.\n"sv,
    },

    // https://github.com/apache/commons-codec/blob/master/src/test/java/org/apache/commons/codec/binary/Base32Test.java
    // "Valid characters but impossible combinations of trailing characters"
    {
        "MC======",
        std::nullopt,
    },
    {
        "MZXE====",
        std::nullopt,
    },
    {
        "MZXWB===",
        std::nullopt,
    },
    {
        "MZXW6YB=",
        std::nullopt,
    },
    {
        "MZXW6YTBOC======",
        std::nullopt,
    },
    {
        "AB======",
        std::nullopt,
    },

    // RFC 4648 test vectors
    {
        ""sv,
        ""sv,
    },
    {
        "MY======"sv,
        "f"sv,
    },
    {
        "MZXQ===="sv,
        "fo"sv,
    },
    {
        "MZXW6==="sv,
        "foo"sv,
    },
    {
        "MZXW6YQ="sv,
        "foob"sv,
    },
    {
        "MZXW6YTB"sv,
        "fooba"sv,
    },
    {
        "MZXW6YTBOI======"sv,
        "foobar"sv,
    },
};

extern const size_t kDecodeData_size = std::size(kDecodeData);
