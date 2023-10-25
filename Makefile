NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = \

OBJS = $(SRCS: .c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
