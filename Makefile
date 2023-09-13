NAME		=	cub3D
LIBFT		=	libs/libft/libft.a
MLX			=	libs/minilibx/libmlx.a
CC			=	cc

SRCS_DIR	=	src/
SRCS		=	$(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS		=	$(SRCS:%.c=%.o)

BONUS		=	0
DEBUG		=	0

LIBFTFLAGS			=		-Llibs/libft -lft
MLXFLAGS			=		-Llibs/minilibx -lmlx -lXext -lX11 -lm -lz


CFLAGS	=	-Wall -Wextra -Werror -I./inc/ -g -DBONUS=$(BONUS) -DDEBUG=$(DEBUG)
RM		=	rm -f

all:		$(NAME)
bonus:
			make fclean && make all BONUS=1
debug:
			make fclean && make all DEBUG=1

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(OBJS) $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
			make -C libs/libft

$(MLX):
			make -C libs/minilibx

clean:
			make -C libs/libft clean
			make -C libs/minilibx clean

fclean:		clean
			$(RM) $(NAME) $(OBJS)
			$(RM) $(LIBFT) libs/minilibx/libmlx.a libs/minilibx/libmlx_Linux.a

re:			fclean all

git:
			@git add -A
			@git commit -m "$m"
			@git push
			@echo "Commit sent to GitHub"
# Use make git m="msg to commit"

.PHONY:		all clean fclean re bonus debug git
