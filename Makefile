SRC=main.c
BIN=jeu

$(BIN): $(SRC)
	gcc -Wall -g -std=c99 $(SRC) `sdl-config --cflags --libs` -o $(BIN)

clean:
	rm -f $(BIN)
