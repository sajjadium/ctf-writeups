`RCTF 2018 - stringer` challenge contains `Off-By-One` and `Double Free` vulnerabilities. Lesson learned is that if the chunk being allocated is `MMAPED`, the content will not be zero out when using `calloc`.

So, by using `Off-By-One` attack, we can set `IS_MMAPED` bit of the target chunk in order to leak a libc address, and then launch the `Fastbin Attack` (https://github.com/shellphish/how2heap/blob/master/fastbin_dup_into_stack.c) by using `Double Free` vulnerability in order to overwrite `__malloc_hook`.

This is a good challenge to understand how to exploit `x64_86` binaries with `Full RELRO`, `Canary`, `NX`, `PIE`, and `ASLR` enabled.
