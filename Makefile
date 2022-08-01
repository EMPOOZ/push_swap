NAME = push_swap
 
CFILES =	src/commands.c src/full_sort_utils.c src/full_sort_utils1.c src/full_sort_utils2.c src/full_sort_utils3.c \
			src/full_sort.c src/full_sort2.c src/lst.c src/perevod_ake_provirka.c src/pushswap.c src/sort_low.c \
			src/sorting.c gnl1/get_next_line.c gnl1/get_next_line_utils.c

CHECKER =	src/commands.c src/full_sort_utils.c src/full_sort_utils1.c src/full_sort_utils2.c src/full_sort_utils3.c \
			src/full_sort.c src/full_sort2.c src/lst.c src/perevod_ake_provirka.c checker1/checker1.c checker1/help_main.c src/sort_low.c \
			src/sorting.c gnl1/get_next_line.c gnl1/get_next_line_utils.c

OBJECTS = $(CFILES:.c=.o)

OBJECTS_C = $(CHECKER:.c=.o)

LIB_PATH = libft/
 
CC = gcc
 
CFLAGS = -Wall -Wextra -Werror
 
all: subsystem $(NAME)
 
subsystem:
	make -C $(LIB_PATH) all
 
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

checker: $(OBJECTS_C)
	$(CC) $(CFLAGS) $(OBJECTS_C) $(LIB_PATH)libft.a -o checker

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_C)
 
fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)
	rm -f checker
 
re: fclean all
 
call: all clean
	make -C $(LIB_PATH) fclean