In this challenge, we are showing how we can leak libc base address and overwrite `__free_hook` by exploiting `Uninitialized Stack Variables` and `Overlapping Heap Chunks`.

This is a good challenge for understanding how to exploit `x86_64` binaries with `Full RELRO`, `Canary`, `NX`, `PIE`, and `ASLR` enabled.
