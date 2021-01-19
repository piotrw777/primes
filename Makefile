CC = g++
FLAGS := -g -pthread -Wpedantic -Wall -pedantic-errors -std=c++17
LIBS := `pkg-config --cflags --libs gtk+-2.0`
OUT = prog.out

SRC = $(wildcard *.cpp)
INC = $(wildcard *.h)

$(OUT): $(SRC) $(INC)
	$(CC) $(FLAGS) -o $(OUT) $(SRC)

clean:
	rm -fv $(OUT)

run: $(OUT)
	./$(OUT)

all:	$(OUT) run