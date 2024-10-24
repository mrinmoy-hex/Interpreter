exec = hello.out	# Executable name
sources = $(wildcard src/*.c)
objects = $(patsubst src/%.c, build/%.o, $(sources))
#flags = -g -Iinclude	# for include dir
flags = -g

# Rule to create the executable from object files
$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

# Rule to create object files in the build directory from source files
build/%.o: src/%.c | build
	gcc -c $(flags) $< -o $@


build:
	mkdir -p build

clean:
	-rm -rf *.out
	-rm -rf build

.PHONY: clean build
