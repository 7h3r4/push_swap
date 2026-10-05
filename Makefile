NAME = push_swap
BONUS_NAME = checker

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_HDR = $(LIBFT_DIR)/libft.h

HEADERS = includes/push_swap.h $(LIBFT_HDR)

COMMON_SRCS = src/parse.c src/process_arr.c src/create_stack.c \
	   src/disorder.c src/utils.c src/stack_utils.c \
	   src/movesets/push.c src/movesets/swap.c src/movesets/rotate.c \
	   src/movesets/rev_rotate.c
SRCS = src/main.c src/sort.c src/bench.c \
	   src/algos/small_sort.c src/algos/issort.c \
	   src/algos/chunk_sort.c src/algos/radix_sort.c $(COMMON_SRCS)
BONUS_SRCS = bonus/checker_bonus.c $(COMMON_SRCS)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HDR) $(LIBFT_DIR)/Makefile
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS) $(BONUS_OBJS): $(HEADERS)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
