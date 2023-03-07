NAME = cub3d.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
AR = ar rc

SRCS = main.c \
		core/hooks.c \
		core/movements.c \
		core/calculations.c \
		parsing/printer.c\
		parsing/primaryChecks.c\
		parsing/libft/ft_strdup.c\
		parsing/libft/ft_strjoin.c\
		parsing/libft/ft_substr.c\
		parsing/libft/ft_strlen.c\
		parsing/libft/ft_strcmp.c\
		parsing/libft/ft_strchr.c\
		parsing/libft/ft_strrchr.c\
		parsing/libft/ft_strncmp.c\
		parsing/libft/ft_split.c\
		parsing/libft/ft_atoi.c\
		parsing/parseFile.c\
		parsing/parseMap.c\
		parsing/getNextline.c\
		parsing/parseUtils.c\
		parsing/bluePrint/color.c\
		parsing/bluePrint/textures.c\
		parsing/leaksHunter.c\
		parsing/inits.c\
		map/render.c


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