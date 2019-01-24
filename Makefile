##
## EPITECH PROJECT, 2018
## raytracer
## File description:
## Makefile
##

NAME	= raytracer

CC	= g++

RM	= rm -f

SRCS	=	./src/Scene.cpp			\
			./src/Sphere.cpp		\
			./src/Plane.cpp			\
			./src/Cylinder.cpp		\
			./src/Cone.cpp			\
			./src/Light.cpp			\
			./src/AShape.cpp		\
			./src/Eye.cpp			\
			./src/DeltaHandler.cpp	\
			./src/Raytracer.cpp		\
			./src/DirectorVector.cpp\
			./src/main.cpp


OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
