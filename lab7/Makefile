all:
	@echo "Usage: make EXERCISE_NAME"

clean:
	rm -r ./bin

ex1:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex1.c -o ./bin/ex1 -pie -g
	echo 'osds{congrats_you_flagged_it!}' > ./flag.txt
	chmod 444 ./flag.txt

ex2:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex2.c -o ./bin/ex2 -no-pie -zlazy -g

ex3:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	nasm -f elf64 -o /tmp/ex3.o ex3.asm
	ld -o ./bin/ex3 /tmp/ex3.o

ex4:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc dummy.c -o ./bin/dummy -g
	gcc ex4.c -o ./bin/ex4 -g

