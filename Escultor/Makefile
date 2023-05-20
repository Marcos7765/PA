FLAGS = -Wall -Wextra -pedantic
CC = g++ $(FLAGS)
OBJ = main.o Sculptor.o
out= exSculptor

main: $(OBJ)
	$(CC) $(OBJ) -o $(out)

$(OBJ): %.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm *.o $(out)