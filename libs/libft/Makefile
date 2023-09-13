NAME		=	libft.a
CC			=	cc
AR			=	ar rc

SRCS_DIR	=	src/
SRCS		=	$(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS		=	$(SRCS:%.c=%.o)

FLAGS		=	-Wall -Wextra -Werror

DEPS		=	-I./inc/

RM			=	rm -rf

all			:	$(NAME)

%.o:		%.c
			$(CC) $(FLAGS) $(DEPS) -c $< -o $@

$(NAME)		:	$(OBJS)
			ar rc $(NAME) $(OBJS)


clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all

.PHONY 		: all clean fclean re
