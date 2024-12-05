all:
	@echo "Usage: make EXERCISE_NAME"

clean:
	rm -r ./bin

ex1:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex1.c -o ./bin/ex1 -fcf-protection=full -fno-stack-protector -pie -zrelro -g

ex2:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	g++ ex2.cpp -o ./bin/ex2 -fcf-protection=full -fno-stack-protector -no-pie -zrelro -g

puzzle:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc puzzle.c -o ./bin/puzzle -fcf-protection=full -fno-stack-protector -pie -zrelro -g
