There is a `stack overflow` vulnerability in this challenge, by which you can leak `read@GOT`, find `glibc` base address, and jump to `execve` found by `one gadget` using `return oriented programming (ROP)` technique.

`return-to-csu: A New Method to Bypass 64-bit Linux ASLR` BlackHat talk is a must-read (https://www.blackhat.com/docs/asia-18/asia-18-Marco-return-to-csu-a-new-method-to-bypass-the-64-bit-Linux-ASLR.pdf).
