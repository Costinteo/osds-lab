all:
	@echo "Usage: make EXERCISE_NAME"

clean:
	rm -r ./bin

ex1:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex1.c -o ./bin/ex1 -fno-stack-protector -no-pie -mgeneral-regs-only -g

ex2:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex2.c -o ./bin/ex2 -zlazy -g

cookies:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc cookies.c -o ./bin/cookies -g
  
bite:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc bite.c -o ./bin/bite -g


