CXX = g++
CC = gcc
CFLAGS = -Wall -g 
#LDFLAGS = 
OBJFILES = Wall.o main.o Tile.o Map.o API.o FloodFill.o TileQueue.o Node.o

TARGET = final

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJFILES)

main.o: main.c API.o Map.o Wall.o Tile.o FloodFill.o TileQueue.o Node.o
	$(CXX) $(CLFAGS) -c main.c

Wall.o : Wall.c Wall.h
	$(CXX) $(CFLAGS) -c Wall.c

Tile.o: Tile.c Tile.h
	$(CXX) $(CFLAGS) -c Tile.c

Map.o: Map.c Map.h Tile.o Wall.o
	$(CXX) $(CFLAGS) -c Map.c

API.o: API.c API.h
	$(CXX) $(CFLAGS) -c API.c

FloodFill.o: FloodFill.c FloodFill.h TileQueue.o
	$(CXX) $(CFLAGS) -c FloodFill.c

TileQueue.o: TileQueue.c TileQueue.h Node.o Map.o 
	$(CXX) $(CFLAGS) -c TileQueue.c

Node.o: Node.c Node.h Tile.o
	$(CXX) $(CFLAGS) -c Node.c

MoveQueue.o: MoveQueue.c MoveQueue.h TileQueue.o
	$(CXX) $(CFLAGS) -c MoveQueue.o
	
clean: 
	rm -f Map.o Tile.o Wall.o main.o API.o FloodFill.o TileQueue.o Node.o final.exe
