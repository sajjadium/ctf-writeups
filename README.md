| Event                    | Challenge | Info | Exploitation |
|--------------------------|-----------|------|--------------|
| [BSides Delhi (2018)](https://ctftime.org/event/700) | [data_bank](BSidesDelhi/2018/data_bank) | `x86_64`, `NX`, `Canary`, `ASLR`, `Full RELRO`, `PIE` | `heap`, `tcache`, `use after free (UAF)`, `tcache poisoning`, `__malloc_hook`, `one gadget` |
| [HITCON (2018)](https://ctftime.org/event/669) | [Children Tcache](HITCON/2018/children_tcache) | `x86_64`, `NX`, `Canary`, `ASLR`, `Full RELRO`, `PIE` | `heap`, `tcache`, `off-by-one`, `poison-null-byte`, `double free`, `overlapping chunks`, `tcache dup`, `tcache poisoning`, `__malloc_hook` |
| [Hack.lu (2018)](https://ctftime.org/event/699) | [BabyPHP](Hack.lu/2018/BabyPHP) | `Web`, `PHP` | `unsanitized user input`, `unintended behaviors`, `code injection`, `assert` |
| [InCTF (2018)](https://ctftime.org/event/662) | [YAWN](InCTF/2018/YAWN) | `x86_64`, `NX`, `Canary`, `ASLR`, `Full RELRO` | `heap`, `off-by-one`, `fastbin dup`, `__malloc_hook`, `one gadget`, `GOT` |
| [InCTF (2018)](https://ctftime.org/event/662) | [securepad](InCTF/2018/securepad) | `x86_64`, `NX`, `Canary`, `ASLR`, `Full RELRO`, `PIE` | `heap`, `uninitialized stack variable`, `arbitrary free`, `unsorted bin`, `fastbin dup`, `__free_hook` |
| [CSAW Quals (2018)](https://ctftime.org/event/633) | [alien_invasion](CSAWQuals/2018/alien_invasion) | `x86_64`, `NX`, `Canary`, `ASLR`, `Partial RELRO`, `PIE` | `heap`, `off-by-one`, `poison-null-byte`, `overlapping chunks`, `GOT` |
| [CSAW Quals (2018)](https://ctftime.org/event/633) | [bigboy](CSAWQuals/2018/bigboy) | `x86_64`, `NX`, `Canary`, `ASLR`, `Partial RELRO` | `stack overflow` |
| [CSAW Quals (2018)](https://ctftime.org/event/633) | [get_it](CSAWQuals/2018/get_it) | `x86_64`, `NX`, `ASLR`, `Partial RELRO` | `stack overflow` |
| [CSAW Quals (2018)](https://ctftime.org/event/633) | [shell_code](CSAWQuals/2018/shell_code) | `x86_64`, `ASLR`, `Full RELRO`, `PIE` | `stack overflow`, `shell code` |
| [WhiteHat Grand Prix Quals (2018)](https://ctftime.org/event/656) | [pwn02](WhiteHatGrandPrixQuals/2018/pwn02) | `x86_64`, `NX`, `Canary`, `ASLR`, `Full RELRO`, `FORTIFY` | `heap`, `off-by-one`, `poison-null-byte`, `overlapping chunks`, `glibc tcache` |
| [MeePwn Quals (2018)](https://ctftime.org/event/625) | [BabySandbox](MeePwnQuals/2018/BabySandbox) | `x86_32`, `Partial RELRO`, `ASLR`, `NX`, `PIE` | `shell code`, `syscall`, `openat`, `readv`, `writev` |
| [0CTF Final (2018)](https://ctftime.org/event/558) | [freenote2018](0CTFFinal/2018/freenote2018) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `heap`, `double free`, `overlapping chunks`, `heap metadata`, `__malloc_hook`, `fastbin dup` |
| [RCTF (2018)](https://ctftime.org/event/624) | [RNote3](RCTF/2018/RNote3) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `uninitialized stack variable`, `heap`, `overlapping chunks`, `__free_hook` |
| [RCTF (2018)](https://ctftime.org/event/624) | [babyheap](RCTF/2018/babyheap) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `heap`, `off-by-one`, `poison-null-byte`, `__malloc_hook`, `PREV_IN_USE bit` |
| [RCTF (2018)](https://ctftime.org/event/624) | [stringer](RCTF/2018/stringer) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `heap`, `off-by-one`, `IS_MMAPED bit`, `calloc`, `double free`, `fastbin dup`, `__malloc_hook` |
| [PlaidCTF (2018)](https://ctftime.org/event/617) | [shop](PlaidCTF/2018/shop) | `x86_64`, `NX`, `Canary`, `Partial RELRO`, `ASLR` | `heap`, `buffer overflow`, `one gadget`, `GOT` |
| [AsisCTF Quals (2018)](https://ctftime.org/event/568) | [Cat](AsisCTFQuals/2018/Cat) | `x86_64`, `NX`, `Canary`, `Partial RELRO`, `ASLR` | `heap`, `fastbin`, `GOT` |
| [AsisCTF Quals (2018)](https://ctftime.org/event/568) | [Fifty Dollars](AsisCTFQuals/2018/Fifty_Dollars) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `heap`, `use after free (UAF)`, `double free`, `fastbin` |
| [AsisCTF Quals (2018)](https://ctftime.org/event/568) | [Just Sort](AsisCTFQuals/2018/Just_Sort) | `x86_64`, `NX`, `Canary`, `Partial RELRO`, `ASLR` | `heap overflow`, `GOT`, `one gadget` |
| [AsisCTF Quals (2018)](https://ctftime.org/event/568) | [Message Me](AsisCTFQuals/2018/Message_Me) | `x86_64`, `NX`, `Canary`, `Partial RELRO`, `ASLR` | `heap`, `use after free (UAF)`, `double free`, `fastbins`, `__malloc_hook`, `overlapping chunks` |
| [\*CTF (2018)](https://ctftime.org/event/614/) | [babystack](StarCTF/2018/babystack) | `x86_64`, `NX`, `Canary`, `Full RELRO`, `ASLR` | `stack overflow`, `GOT`, `pthread`, `Thread Local Storage (TLS)`, `stack_guard` |
| [\*CTF (2018)](https://ctftime.org/event/614/) | [note](StarCTF/2018/note) | `x86_64`, `NX`, `Full RELRO`, `ASLR` | `stack overflow`, `off-by-one`, `return oriented programming (ROP)`, `least significant byte (LSB)`, `saved rbp`, `GOT` |
| [\*CTF (2018)](https://ctftime.org/event/614/) | [warmup](StarCTF/2018/warmup) | `x86_64`, `NX`, `Full RELRO`, `ASLR` | `stack overflow`, `one gadget`, `GOT` |
| [WPICTF (2018)](https://ctftime.org/event/600) | [Forker.level1](WPICTF/2018/Forker.level1) | `x86_64`, `Partial RELRO`, `ASLR` | `stack overflow`, `return-to-csu`, `return oriented programming (ROP)`, `GOT`, `shell code` |
| [WPICTF (2018)](https://ctftime.org/event/600) | [Forker.level2](WPICTF/2018/Forker.level2) | `x86_64`, `NX`, `Canary`, `Partial RELRO`, `ASLR` | `stack overflow`, `fork`|
| [UIUCTF (2018)](https://ctftime.org/event/587) | [how2heap](UIUCTF/2018/how2heap) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `heap`, `one gadget` |
| [0CTF Quals (2018)](https://ctftime.org/event/557) | [babyheap](0CTFQuals/2018/babyheap) | `x86_64`, `NX`, `Canary`, `PIE`, `Full RELRO`, `ASLR` | `heap`, `off-by-one`, `double free`, `fastbin dup`, `__malloc_hook`, `one gadget`, `top chunk` |
| [0CTF Quals (2018)](https://ctftime.org/event/557) | [babystack](0CTFQuals/2018/babystack) | `x86_32`, `Canary`, `Partial RELRO`, `ASLR` | `stack overflow`, `return oriented programming (ROP)`, `GOT`, `PLT` |
| [iCTF (2018)](https://ctftime.org/event/567) | [fantasticiot](iCTF/2018/fantasticiot) | `x86_32`, `Canary`, `NX`, `ASLR` | `attack & defense`, `strncmp`, `binary patching` |
| [TAMUCTF (2018)](https://ctftime.org/event/559) | [pwn5](TAMUCTF/2018/pwn5) | `x86_32`, `Partial RELRO`, `NX`, `ASLR` | `stack overflow`, `return oriented programming (ROP)` |
| [NullconCTF (2018)](https://ctftime.org/event/566) | [pwn2-box](NullconCTF/2018/pwn2-box) | `x86_64`, `Partial RELRO`, `ASLR` | `shell code`, `return oriented programming (ROP)`, `one gadget`, `syscall` |
| [CodegateCTF (2018)](https://ctftime.org/event/542) | [BaskinRobins31](CodegateCTF/2018/BaskinRobins31) | `x86_64`, `Partial RELRO`, `NX`, `ASLR` | `stack overflow`, `return oriented programming (ROP)`, `GOT`, `one gadget` |
| [CodegateCTF (2018)](https://ctftime.org/event/542) | [SuperMarimo](CodegateCTF/2018/Super_Marimo) | `x86_64`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `heap`, `GOT`, `fastbin`, `one gadget` |
| [34C3 (2017)](https://ctftime.org/event/544) | [SimpleGC](34C3/2017/SimpleGC) | `x86_64`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `heap`, `use after free (UAF)`, `GOT`, `glibc tcache`, `fastbin` |
| [SECCON (2017)](https://ctftime.org/event/512) | [election](SECCON/2017/election) | `x86_64`, `Canary`, `Full RELRO`, `NX`, `ASLR` | `buffer overflow`, `arbitrary write`, `GOT`, `__malloc_hook`, `one gadget`, `fastbin` |
| [SECCON (2017)](https://ctftime.org/event/512) | [secure_keymanager](SECCON/2017/secure_keymanager) | `x86_64`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `heap`, `double free`, `format string`, `GOT`, `PLT`, `fastbin` |
| [SECCON (2017)](https://ctftime.org/event/512) | [video_player](SECCON/2017/video_player) | `x86_64`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `heap`, `use after free (UAF)`, `GOT`, `one gadget`, `__malloc_hook`, `vtable`, `virtual calls`, `overlapping chunks`, `fastbin` |
| [CSAW Quals (2017)](https://ctftime.org/event/488) | [SCV](CSAWQuals/2017/SCV) | `x86_64`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `stack overflow`, `buffer overflow`, `information disclosure`, `buffer over-read`, `return oriented programming (ROP)`, `one gadget` |
| [pwnable.kr](http://pwnable.kr/) | [asm](pwnable.kr/asm) | `x86_64`, `PIE`, `Partial RELRO`, `NX`, `ASLR` | `stack overflow`, `shell code`, `syscall` |
| [pwnable.kr](http://pwnable.kr/) | [bof](pwnable.kr/bof) | `x86_32`, `PIE`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `stack overflow` |
| [pwnable.kr](http://pwnable.kr/) | [lotto](pwnable.kr/lotto) | `x86_64`, `Canary`, `Partial RELRO`, `NX`, `ASLR` | `random generator` |
| [pwnable.tw](https://pwnable.tw/) | [orw](pwnable.tw/orw) | `x86_32`, `Canary`, `Partial RELRO` | `shell code`, `syscall` |
| [pwnable.tw](https://pwnable.tw/) | [start](pwnable.tw/start) | `x86_32` | `stack overflow`, `shell code` |
