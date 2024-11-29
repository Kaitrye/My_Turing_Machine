CC=clang++
CFLAGS=-pedantic-errors -gdwarf-4 -std=c++20
LDFLAGS=
SOURCES=main.cpp turingmachine.cpp ringtape.cpp program.cpp command.cpp
EXECUTABLE=tm

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE):
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

