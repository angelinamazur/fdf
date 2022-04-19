NAME = fdf

SRC = get_next_line.c get_next_line_utils.c main.c ft_atoi.c ft_split.c read_file.c\
		draw.c

HEADER = fdf.h

OBJS = ${SRCS:%.c=%.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f $(NAME)

re : fclean all