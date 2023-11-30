# Name of the project
NAME = get_next_line.a

# Sources
SRCS = get_next_line.c get_next_line_utils.c

# Objects
SRCS_OBJS = $(SRCS:.c=.o)

# Compiler
CC = cc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	ar -r $@ $^

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
