FLAGS=-fno-stack-protector -no-pie -g

all:
	@echo "Usage: make EXERCISE_NAME"

clean:
	rm -r ./bin

%:
	@if [ ! -d ./bin ]; then mkdir bin; fi
	gcc $@.c -o ./bin/$@ ${FLAGS}
