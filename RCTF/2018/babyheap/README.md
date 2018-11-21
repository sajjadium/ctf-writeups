In this challenge, we are showing how we can leak libc base address and overwrite `__malloc_hook` using `null byte poisoning` aka `off-by-one overflow` aka `null byte overflow` vulnerability. Basically, by clearing `PREV_IN_USE` bit in a chunk, we can cause two chunks consolidate and the chunk between them being forgotten.

This is a good challenge for understanding how to exploit `x86_64` binaries with `Full RELRO`, `Canary`, `NX`, `PIE`, and `ASLR` enabled.
