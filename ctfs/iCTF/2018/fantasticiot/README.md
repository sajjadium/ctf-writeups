There vulnerability is in the `get_flag`, there is a `strncmp`. Basically, if you provide empty string as one of the parameters, it will return `0` because the `n` parameter is extracted from the provided `token`.

In order to fix it, you just need to replace `strncmp` with `strcmp`. The following line is from objdump. You need to replace `8048c95` with `8113480`:

`80497ae:       e8 e2 f4 ff ff          call   8048c95 <strncmp>`

