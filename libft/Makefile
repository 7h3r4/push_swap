NAME	= libft.a

SRCS	= ft_atoi.c ft_atoi_parse.c ft_split.c ft_memset.c \
		  ft_strchr.c ft_strcmp.c ft_strlen.c ft_putstr_fd.c ft_putnbr_fd.c

OBJS    = $(SRCS:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

all:	$(NAME)

$(OBJS): libft.h

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re