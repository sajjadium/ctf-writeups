In `BSidesDelhi 2018 - data_bank` challenge, there is a `use after free (UAF)` vulnerability which leads to `tcache poisoning`. Using this, we leak a `libc` address to de-randomize `ASLR`, and then put our `fake chunk` address into the `tcache` bin using `tcache poisoning` attack. As a result, we can force `malloc` to return our `fake chunk` before `__malloc_hook`, so we can overwrite `__malloc_hook` with `one gadget`. This is an interesting `heap exploitation` challenge to learn bypassing protections like `NX`, `PIE`, `Canary`, `Full RELRO`, and `ASLR` in `x86_64` binaries in presence of `tcache`.