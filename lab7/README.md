# Laboratory 0x07 - Miscellaneous Pwnage Extravaganza

Come one, come all, to the Pwnage Extravaganza! In this lab we have multiple challenges, taken from several CTFs or created specifically for this lab. Each exercise in this lab is worth 3.5 points, despite it having multiple exercises!!

For the theoretical aspects of the lab, there is not much we haven't discussed already. You need to know the same things we've done so far, but this time you have to apply them in creative ways.

Have fun playing!

## Exercise 1 - Memory Salad

This challenge is taken from CakeCTF.
Please use `make ex1` to build the exercise.

Write a *pwntools* exploit to get the contents of `./flag.txt` printed.

**Hints**:
* Read the manual for interesting functions very carefully.
* Make sure you understand what the `setup()` does very well.

## Exercise 2 - Fliphammer

Rowhammer is useless! You can only flip one bit! You can't exploit anything with that, can you? *Can you?*

Greatly inspired by *Flipper* from *GlacierCTF 2023*.

Use `make ex2` to build the exercise.

Write a *pwntools* exploit to get a shell.

**Hints**:
* Usually, when you have limitations, you should figure out how to get rid of them.
* Writing to memory through `/proc/self/mem` bypasses all segment protections. So even if a segment is `r--` you can still write to it.
* Read a writeup for *Flipper*, [here is one](https://dothidden.xyz/glacierctf_2024/flipper/) from .hidden.

## Exercise 3 - Signal-Return Oriented Vibes

No `pop rdi; ret`, can't ROP your way out of this one, hacker!

Use `make ex3` to build the exercise.

Write a *pwntools* exploit to get a shell.

**Hints**:
* Read the title.
