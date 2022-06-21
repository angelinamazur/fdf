NAME = fdf

SRCS = get_next_line.c get_next_line_utils.c main.c ft_atoi.c ft_split.c read_file.c draw_badone.c free.c events.c env_init.c hex_to_dec.c height_width.c

HEADER = fdf.h

OBJS = ${SRCS:%.c=%.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f $(NAME)

re : fclean all