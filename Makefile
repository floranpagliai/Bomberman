NAME		=	bomberman

DIR		=	src/

SRC		=	$(DIR)main.cpp\
			$(DIR)MyGame.cpp\
			$(DIR)Camera.cpp\
			$(DIR)Bomberman.cpp\
			$(DIR)Bomb.cpp\
			$(DIR)Flamme.cpp\
			$(DIR)MapElement.cpp\
			$(DIR)Bonus.cpp\
			$(DIR)Map.cpp\
			$(DIR)Display.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDE		+=	-I./include/ -I./lib/include

CXXFLAGS	+=

LDFLAGS		=	-L./lib -Wl,--rpath=./lib -lgdl_gl -lGL -lGLU -lsfml-audio



$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -Werror -Wall -W
		make clean

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) src/*~
		$(RM) src/*#
		$(RM) include/*~
		$(RM) include/*#

fclean	:	clean
		$(RM) $(NAME)

re	: 	fclean all

.cpp.o	:
		$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@