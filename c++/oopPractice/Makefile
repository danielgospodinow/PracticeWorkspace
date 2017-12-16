CC = g++
CFLAGS = -c -Wall

all: arena clean_o

arena: main.o monster.o shield.o weapon.o polearm.o axe.o arena.o knight.o utils.o lama.o zombie.o dragon.o
			$(CC) main.o monster.o shield.o weapon.o polearm.o axe.o arena.o knight.o utils.o lama.o zombie.o dragon.o -o Arena

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

monster.o: src/monster.cpp
	$(CC) $(CFLAGS) src/monster.cpp

shield.o: src/shield.cpp
	$(CC) $(CFLAGS) src/shield.cpp

weapon.o: src/weapon.cpp
	$(CC) $(CFLAGS) src/weapon.cpp

polearm.o: src/polearm.cpp
	$(CC) $(CFLAGS) src/polearm.cpp

axe.o: src/axe.cpp
	$(CC) $(CFLAGS) src/axe.cpp

arena.o: src/arena.cpp
	$(CC) $(CFLAGS) src/arena.cpp

knight.o: src/knight.cpp
	$(CC) $(CFLAGS) src/knight.cpp

utils.o: src/utils.cpp
	$(CC) $(CFLAGS) src/utils.cpp

lama.o: src/lama.cpp
	$(CC) $(CFLAGS) src/lama.cpp

zombie.o: src/zombie.cpp
	$(CC) $(CFLAGS) src/zombie.cpp

dragon.o: src/dragon.cpp
	$(CC) $(CFLAGS) src/dragon.cpp

clean:
	rm -rf *.o Arena

clean_o:
	rm -rf *.o
