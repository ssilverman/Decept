[![Sponsor @ssilverman button](https://img.shields.io/badge/Sponsor-30363d.svg?logo=githubsponsors&logoColor=EA4AAA)](https://github.com/sponsors/ssilverman "Sponsor @ssilverman on GitHub")
or
[![Buy Me a Coffee donate button](https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00)](https://www.buymeacoffee.com/ssilverman "Donate to this project using Buy Me a Coffee")

# _Decept_, a hardware-based crypto library For Teensy 4

_Version: 0.1.0-snapshot_

## Table of contents

1. [Disclaimer](#disclaimer)
2. [Introduction](#introduction)
3. [Running the tests](#running-the-tests)
4. [Feature list](#feature-list)
5. [To do](#to-do)
6. [References](#references)

## Disclaimer

Security is hard, and this library was not written by a security expert. While
the included test suite demonstrates correctness, it doesn't mean that this
library is actually secure. It requires review from more security experts.

## Introduction

The _Decept_ library utilizes the on-board Data Co-Processor (DCP) to provide
hardware-accelerated cryptographic algorithms using modern C++.

This library is in its very early stages and it will likely change over time.

**Note: Please read the function docs in the relevant header files for
more information.**

## Running the tests

There's a full suite of tests to help inspire confidence in the correctness of
the calculations and algorithm executions. They use the PlatformIO-provided
Unity framework.

For testing, I use the "PlatformIO: New Terminal" command. It's likely a little
terminal-looking icon at the bottom of the VSCode window.

Here's how I run the full suite of tests:
```sh
pio test -v
```

To run specific tests, you can add them to the command line:
```sh
pio test -v -f test_aes128 -f test_hmac
```

## Feature list

This is a list of the library features:
* Utilizes the built-in DCP module
* Non-blocking API \[Planned]
* Encryption: AES-128
* Hashing: SHA-256, SHA-1
* CRC: CRC-32
* HMAC: HMAC, TOTP
* Codecs: base32

## To do

* Have a review done by security experts
* Tests for CRC-32
* Complete the non-blocking API
* Complete CTR DRBG
* Explore cache alignment for all the structures and parts
* Adapt DRBG classes to the
  [RandomNumberEngine](https://en.cppreference.com/w/cpp/named_req/RandomNumberEngine.html)
  C++ named requirement

## References

* [MCUXpresso SDK : mcuxsdk-core](https://github.com/nxp-mcuxpresso/mcuxsdk-core)

---

Copyright (c) 2023-2026 Shawn Silverman
