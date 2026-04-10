// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// encode_data.cpp contains the encoder test data.
// This file is part of the Decept library.

// C++ includes
#include <array>
#include <cstddef>

#include "defs.h"

extern const EncodeTestData kEncodeData[]{
    // https://github.com/stesla/base32/blob/master/test/base32_test.rb
    {
        "a"sv,
        "ME======"sv,
    },
    {
        "12345"sv,
        "GEZDGNBV"sv,
    },
    {
        "abcde"sv,
        "MFRGGZDF"sv,
    },
    {
        "      We the people of the United States, in order to form a more perfect union,\n      establish justice, insure domestic tranquility, provide for the common\n      defense, promote the general welfare, and secure the blessings of liberty\n      to ourselves and our posterity, do ordain and establish this Constitution\n      for the United States of America.\n"sv,
        "EAQCAIBAEBLWKIDUNBSSA4DFN5YGYZJAN5TCA5DIMUQFK3TJORSWIICTORQXIZLTFQQGS3RAN5ZGIZLSEB2G6IDGN5ZG2IDBEBWW64TFEBYGK4TGMVRXIIDVNZUW63RMBIQCAIBAEAQGK43UMFRGY2LTNAQGU5LTORUWGZJMEBUW443VOJSSAZDPNVSXG5DJMMQHI4TBNZYXK2LMNF2HSLBAOBZG65TJMRSSAZTPOIQHI2DFEBRW63LNN5XAUIBAEAQCAIDEMVTGK3TTMUWCA4DSN5WW65DFEB2GQZJAM5SW4ZLSMFWCA53FNRTGC4TFFQQGC3TEEBZWKY3VOJSSA5DIMUQGE3DFONZWS3THOMQG6ZRANRUWEZLSOR4QUIBAEAQCAIDUN4QG65LSONSWY5TFOMQGC3TEEBXXK4RAOBXXG5DFOJUXI6JMEBSG6IDPOJSGC2LOEBQW4ZBAMVZXIYLCNRUXG2BAORUGS4ZAINXW443UNF2HK5DJN5XAUIBAEAQCAIDGN5ZCA5DIMUQFK3TJORSWIICTORQXIZLTEBXWMICBNVSXE2LDMEXAU==="sv,
    },

    // RFC 4648 test vectors
    {
        ""sv,
        ""sv,
    },
    {
        "f"sv,
        "MY======"sv,
    },
    {
        "fo"sv,
        "MZXQ===="sv,
    },
    {
        "foo"sv,
        "MZXW6==="sv,
    },
    {
        "foob"sv,
        "MZXW6YQ="sv,
    },
    {
        "fooba"sv,
        "MZXW6YTB"sv,
    },
    {
        "foobar"sv,
        "MZXW6YTBOI======"sv,
    },
};

extern const size_t kEncodeData_size = std::size(kEncodeData);
