FLAGS=-fno-stack-protector -no-pie -g

all:
	@echo "Usage: make EXERCISE_NAME"

clean:
	rm -r ./bin

ex2:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex2.c -o ./bin/ex2 ${FLAGS} -mgeneral-regs-only

%:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc $@.c -o ./bin/$@ ${FLAGS}
