
# code details

EXE = ./library
SRC= main.c save.c user.c interface.c book_management.c

# generic build details

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK= 

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c book_management.h user.h save.h interface.h book_management.h
user.o: user.c book_management.h user.h save.h interface.h book_management.h
save.o: save.c book_management.h user.h save.h interface.h book_management.h
interface.o: interface.c book_management.h user.h save.h interface.h book_management.h
book_management.o: book_management.c book_management.h user.h save.h interface.h

