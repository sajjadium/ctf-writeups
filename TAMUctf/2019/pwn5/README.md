This challenge has a `stack overflow` vulnerability, by which you can overwrite the return address. Then, using `return to libc` (`ret2libc`), you are able to spawn `/bin/sh`.
