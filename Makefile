##
## Makefile for Makefile in /home/paglia_f//WorkOffline/printf
##
## Made by floran pagliai
## Login   <paglia_f@epitech.net>
##
## Started on  Mon Nov 14 10:39:32 2011 floran pagliai
## Last update Tue Feb 19 13:53:29 2013 floran pagliai
##

NAME= 	abstract_VM

SRC=	include/my_atof.cpp\
	include/my_atoi.cpp\
	src/main.cpp\
	src/Calculator.cpp\
	src/Operand.cpp\
	src/Exception.cpp\
	src/Lexer.cpp


OBJ=	$(SRC:.cpp=.o)

CC=	clang++

FLAG=	-W -Wall -Werror

all:	$(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)
	rm -rf *~
	rm -rf *#


fclean:	clean
	rm -f $(NAME)

re: fclean all