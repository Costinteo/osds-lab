FLAGS=-fno-stack-protector -no-pie -g

all:
	@echo "Usage: make EXERCISE_NAME"

clean:
	rm -r ./bin

ex4:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc ex4.c -o ./bin/ex4 ${FLAGS} -zexecstack

%:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc $@.c -o ./bin/$@ ${FLAGS}
