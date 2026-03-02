SRC = parser.c \
	disorder.c \
	utils/nodes_utils.c \
	utils/parser_flags_utils.c \
	utils/parser_utils.c \
	utils/parsing_index.c \
	utils/split.c \
	utils/split_utils.c \
	utils/utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

NAME = push_swap

OBJDIR = build

OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	rm -f *.o *.d utils/*.o utils/*.d

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
