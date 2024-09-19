# Laboratory 0x02 - Smashing Stacks & pwntools

Ah, yes, the legendary **buffer overflow**. The most infamous vulnerability in history. Kicked off into the "mainstream" security scene by Aleph One (or Elias Levy) with his Phrack article "*Smashing The Stack For Fun and Profit*", buffer overflows have been the plague of software since the dawn of C programming. While stack-based buffer overflows still hold potential today, their capability is heavily limited by modern binary-level protections. These are mechanisms usually introduced by compilers or by the operating system to protect programs from such bugs. Examples include *stack cookies*, *address space layout randomization*, *w^x bit*, *shadow stacks*... The list goes on.

In this laboratory, we shall reproduce and understand a classic buffer overflow attack. We will be using a technique called *code-reusing* initially and then later explore crafting *shellcode*, similarly to the Phrack article. Additionally, we will be learning the widely-used exploitation framework *pwntools*, to help us mount an attack easier, faster and automated.

Note: All the programs we are exploiting will be compiled for 64-bits. We will be temporarily compile without stack cookies, which is one of the protections used by compilers, to simplify the process.

At this point, we should check out [pwntools](https://github.com/Gallopsled/pwntools) and its [documentation](https://docs.pwntools.com/en/stable/). If you're on a Debian derivative, you can install it with the instructions found on the repo:

```
$ sudo apt-get update
$ sudo apt-get install python3 python3-pip python3-dev git libssl-dev libffi-dev build-essential
$ python3 -m pip install --upgrade pip
$ python3 -m pip install --upgrade pwntools
```

Otherwise, you can just install the prerequisites with your distribution's package manager and then install pwntools with `pip install pwntools`.

### What is a buffer overflow?

Simply put, a buffer overflow is when you try to copy more data into a memory location (buffer) than that memory is supposed to hold. For example, if you try to input MORE than 8 characters into a buffer of 8 characters, the copy operations to that buffer *might* continue copying past the end of it. What *past the end* means is that the extra bytes will be copied *up* the stack. The following image presents an example of a buffer overflow that overwrites adjacent value `is_admin` on the stack:

![buffer overflow](../img/buffer_overflow.png)

**[Q1]**: Can you imagine a scenario where this would affect a program's behavior?

## Exercise 1 - Buffer Overflow to bypass authentication

For the first exercise (`ex1.c`), we will be using the scenario you imagined at the previous question. The stack contains a variable that maintains the admin status of the current user. A user is made admin only if they know a secret password.

**[Q2]**: Can you bypass the check that "grants you access", without knowing the secret password?

Note that when compiling, the stack layout does not always follow the declaration order of the source code. Variables may be moved depending on their type, or they can be padded to keep the stack aligned to 16 bytes.

**[Q3]**: How can we inspect the stack layout of a program?

Attempt to exploit the buffer overflow. You can use `echo` and pipes in the terminal to pass input to the program easier: `echo -n 'asdf' | ./bin/ex1`.

Hints: 

* You can pass input to gdb by saving it to a file and loading it when running the process. For example:

```
$ echo -n 'asdf' > input
$ gdb -q
$ pwndbg -q
pwndbg> file ./bin/ex1
Reading symbols from bin/ex1...
pwndbg> run < input
...
```
* You should use breakpoints to stop the debugger when it hits certain instructions. Use `break main`, or `b main`. You can even do `b *main+16` to stop at certain offsets into the function.
* You can see the content of memory by using the [examine](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Memory.html#Memory) command `x/`. You can append a [format](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Output-Formats.html) to it, coupled with a number and a unit size. For example, for printing 80 bytes of content from the stack, in groups of 8 bytes, starting from the `RSP` register, we can do `x/10gx $rsp`. Note that the final `x` formats the output as hexadecimal.


## Exercise 2 - Buffer Overflow, but cooler (ft. pwntools)




## Exercise 3 - Escaping the Matrix

## Exercise 4 - Crafting Byte Incantations

Welcome to the 90's, powerful byte mage. Thou shalt not worry, the [NX bit](https://en.wikipedia.org/wiki/NX_bit) hath not been invented yet. In other words, 'tis *shelcoding* time.





## Extra Challenges

Each lab will also have some extra fun challenges that expand on each exercise, to give you an opportunity to explore more for an exercise you liked. You can get extra points for them. Since this lab only has a single theme, there's only one bonus challenge:

1. **Exploitation prodigy** -- Can you figure out a way to beat `bonus.c`? The objective is to print out `True hackers see beyond what they are told... You won!`.
