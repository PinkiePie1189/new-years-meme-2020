CC = gcc
CFLAGS = -Wall -Wextra -I ./include -L ./lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
gbemu: main.o display.o game.o texture.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
main.o: main.c
	$(CC) $(CFLAGS) -c $^ $(LIBS)
display.o: display.c
	$(CC) $(CFLAGS) -c $^ $(LIBS)
game.o: game.c
	$(CC) $(CFLAGS) -c $^ $(LIBS)

