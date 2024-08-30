NAME = main
CC = c++ -std=c++98 #-fsanitize=address -g
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAIN=   DivideAndRule.cpp


HEADERS = 

all : $(NAME)

$(NAME) : $(MAIN) $(HEADERS)
			@$(CC) $(FLAGS) $(MAIN) -o $(NAME)

clean :

fclean :  clean 
			@$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re