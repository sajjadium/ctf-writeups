In `AsisCTF Quals 2018 - Fifty Dollars` challenge, we can leak `heap` base address using a `use after free` vulnerability, and leak `libc` base address using a `double free` vulnerability (by mounting `fastbin attack`).

This is a good challenge to understand how to exploit `x64_86` binaries with `Full RELRO`, `Canary`, `NX`, `PIE`, and `ASLR` enabled.