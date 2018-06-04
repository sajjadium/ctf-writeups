In this challenge, we are showing how we can leak libc base address and overwrite `__free_hook` by exploiting `Uninitialized Stack Variables`.

This is a good challenge for understanding how to exploit `x64_86` binaries with `Full RELRO`, `Canary`, `NX`, `PIE`, and `ASLR` enabled.
