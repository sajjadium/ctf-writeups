# SECCON 2017 Quals

[CTFtime Event](https://ctftime.org/event/512)

[CTFtime Writeups](https://ctftime.org/event/512/tasks/)

[CTFium](https://github.com/sajjadium/CTFium/tree/master/SECCON/2017/Quals/)

| Challenge   | Info               | Exploitation         | Links     |
|:-----------:|--------------------|----------------------|:---------:|
| [election](election) | `x86_64` `NX` `Canary` `Full RELRO` `ASLR` | `GOT` `__malloc_hook` `fastbin` `null byte overflow` `null byte poisoning` `off-by-one` `one gadget` | [CTFtime](https://ctftime.org/event/512) [Writeups](https://ctftime.org/task/5040) [CTFium](https://github.com/sajjadium/CTFium/tree/master/SECCON/2017/Quals/election) |
| [secure_keymanager](secure_keymanager) | `x86_64` `NX` `Canary` `Partial RELRO` `ASLR` | `GOT` `PLT` `double free` `fastbin` `format string` `heap` | [CTFtime](https://ctftime.org/event/512) [Writeups](https://ctftime.org/task/5041) [CTFium](https://github.com/sajjadium/CTFium/tree/master/SECCON/2017/Quals/secure_keymanager) |
| [video_player](video_player) | `x86_64` `NX` `Canary` `Partial RELRO` `ASLR` | `GOT` `__malloc_hook` `fastbin` `heap` `one gadget` `overlapping chunks` `use after free` `virtual calls` `vtable` | [CTFtime](https://ctftime.org/event/512) [Writeups](https://ctftime.org/task/5051) [CTFium](https://github.com/sajjadium/CTFium/tree/master/SECCON/2017/Quals/video_player) |
