NAME = cub3d.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
AR = ar rc

SRCS = main.c \
		hooks.c \
		utils/utils.c \
		utils/calculations.c
				
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -lmlx -framework OpenGL -framework AppKit -o cub3d

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf cub3d

re : fclean all

.PHONY: re fclean all clean