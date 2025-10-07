# Operating Systems: Design and Security Laboratory

This is the repository where the materials for the Operating Systems: Design and Security Lab can be found.

In the lab we will touch on several subjects and exploitation techniques also explained in the course, such as:

* Virtual Memory
* Buffer Overflows
* Shellcoding
* Return 2 Libc
* Return Oriented Programming
* Address Space Layout Randomization & PIE
* Stack Canaries
* Data-Only Attacks
* Function Oriented Programming and Counterfeit Object Oriented Programming
* Intel CET
* Use-After-Free
* Double Free
* Other fun stuff

## Lab format

Each lab has a directory containing a `README.md`. Those will explain important concepts, ask helpful questions and offer you exercises.

We will use the READMEs as support for the lab, but will also probably use the whiteboard and slides from [.hidden](https://dothidden.xyz) presentations to explain various concepts.

## Grading

The labs each have a flat **7 points**. The points are equally divided between the exercises.[^exception]
This might not be completely fair, as some labs/exercises are harder and others are easier. We welcome suggestions for next years.

You also get one extra point for free, so you can achieve a total of 50 points.

[^exception]: With the exception of Lab 7, which is special.


## Contributions

If you spot a mistake, be it either technical or spelling, please open a pull request to fix it, or at least open an issue.

We also welcome any feedback, discussions or suggestions to improve the lab. Let the PRs rain.

## Extra Resources

Some extra resources compiled throughout the years. If you feel overwhelmed, this list might help you in solving the labs, or understanding what we're doing better.
Feel free to suggest any extra articles or resources that helped you!

If you have questions about understanding a specific thing, or you are stuck somewhere, please message us.

* [GDB Cheatsheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
* [pwndbg Cheatsheet](https://pwndbg.re/CheatSheet.pdf)
* [Computer Architecture Primer](https://youtu.be/L1ung0wil9Y) - everything up to min 47 is directly applicable to the lab.
* [Great playlist from LiveOverflow](https://youtu.be/6jSKldt7Eqs?list=PLhixgUqwRTjxglIswKp9mpkfPNfHkzyeN) - popular security youtuber, this video is about x64 assembly and the stack.
	The playlist has plenty of other videos that can help you! But watch out - most other videos showcase the 32 bits calling convention, which passes parameters on the stack, unlike x64 which first uses the registers. We use 64 bits at the lab!
* [Codebending .hidden presentation](https://docs.google.com/presentation/d/1H1jfutKSter7UFtRmciRgn3QCBCej-o84l6MS-XXMvQ) - the slides showcase how instructions affect RBP, RSP and RIP.
* [ROP challenge walkthrough from John Hammond](https://youtu.be/tMN5N5oid2c) - popular security youtuber, directly applicable to challenges in the lab.
* Don't forget you can use `man func` to read about a certain function `func`, directly from your Linux terminal!
* The [.hidden website](https://dothidden.xyz/tags/pwn/) has writeups and script solutions for multiple challenges like those from the lab. Some of your colleagues wrote nicer pwntools scripts for the lab than I did for those writeups though!
* **USE THE DEBUGGER**. Use it a lot. Step through everything. Understand it. Observe the changes throughout program execution.
* The **HINTS** in the Lab have a significant chance of helping you when you are writing your exploit and something doesn't work and you are not sure what.
* [How To Ask Questions The Smart Way](http://catb.org/~esr/faqs/smart-questions.html) - a well-known article explaining the mindset you should be having when trying to find the answer to a question.

Don't forget, if you have read the above and are stuck and you don't know what to do, please ask for help.
