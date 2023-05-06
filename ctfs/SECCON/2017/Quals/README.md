# SECCON 2017 Quals

[CTFtime Event](https://ctftime.org/event/512)

[CTFtime Writeups](https://ctftime.org/event/512/tasks/)

[Archives](https://github.com/sajjadium/ctf-archives/tree/master/ctfs/ctfs/SECCON/2017/Quals/)

| Challenge   | Info               | Exploitation         | Links     |
|:-----------:|--------------------|----------------------|:---------:|
| [election](election) | `x86_64` `NX` `Canary` `Full RELRO` `ASLR` | `GOT` `__malloc_hook` `fastbin` `null byte overflow` `null byte poisoning` `off-by-one` `one gadget` | [Writeups](https://ctftime.org/task/5040) [Archives](https://github.com/sajjadium/ctf-archives/tree/master/ctfs/SECCON/2017/Quals/election) |
| [secure_keymanager](secure_keymanager) | `x86_64` `NX` `Canary` `Partial RELRO` `ASLR` | `GOT` `PLT` `double free` `fastbin` `format string` `heap` | [Writeups](https://ctftime.org/task/5041) [Archives](https://github.com/sajjadium/ctf-archives/tree/master/ctfs/SECCON/2017/Quals/secure_keymanager) |
| [video_player](video_player) | `x86_64` `NX` `Canary` `Partial RELRO` `ASLR` | `GOT` `__malloc_hook` `fastbin` `heap` `one gadget` `overlapping chunks` `use after free` `virtual calls` `vtable` | [Writeups](https://ctftime.org/task/5051) [Archives](https://github.com/sajjadium/ctf-archives/tree/master/ctfs/SECCON/2017/Quals/video_player) |
