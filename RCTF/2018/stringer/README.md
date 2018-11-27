`RCTF 2018 - stringer` challenge contains `off-by-one` and `double free` vulnerabilities. Lesson learned is that if the chunk being allocated is `MMAPED`, the content will not be zero out when using `calloc`.

So, by using `off-by-one` attack, we can set `IS_MMAPED` bit of the target chunk in order to leak a libc address, and then launch the `fastbin attack` (https://github.com/shellphish/how2heap/blob/master/fastbin_dup_into_stack.c) by using `double free` vulnerability in order to overwrite `__malloc_hook`.

This is a good challenge to understand how to exploit `x86_64` binaries with `Full RELRO`, `Canary`, `NX`, `PIE`, and `ASLR` enabled.
