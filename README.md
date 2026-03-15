[![Sponsor @ssilverman button](https://img.shields.io/badge/Sponsor-30363d.svg?logo=githubsponsors&logoColor=EA4AAA)](https://github.com/sponsors/ssilverman "Sponsor @ssilverman on GitHub")
or
[![Buy Me a Coffee donate button](https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00)](https://www.buymeacoffee.com/ssilverman "Donate to this project using Buy Me a Coffee")

# _Decept_, a hardware-based crypto library For Teensy 4

_Version: 0.1.0-snapshot_

## Table of contents

1. [Disclaimer](#disclaimer)
2. [Introduction](#introduction)
3. [To do](#to-do)
4. [References](#references)

## Disclaimer

Security is hard, and this library was not written by a security expert. While
the included test suite demonstrates correctness, it doesn't mean that this
library is actually secure. It requires review from more security experts.

## Introduction

The _Decept_ library utilizes the on-board Data Co-Processor (DCP) to provide
hardware-accelerated cryptographic algorithms using modern C++.

**Note: Please read the function docs in the relevant header files for
more information.**

## To do

* Tests for CRC-32
* Non-blocking API
* Complete CTR DRBG

## References

* [MCUXpresso SDK : mcuxsdk-core](https://github.com/nxp-mcuxpresso/mcuxsdk-core)

---

Copyright (c) 2023-2026 Shawn Silverman
