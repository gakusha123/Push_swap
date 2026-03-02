SRC = parser.c \
	disorder.c \
	utils/nodes_utils.c \
	utils/parser_flags_utils.c \
	utils/parser_utils.c \
	utils/parsing_index.c \
	utils/split.c \
	utils/split_utils.c \
	utils/utils.c \
	utils/parser_utils2.c \
	main.c \
#tu captes la syntaxe pour les fonctions dans un fichier pour que le nakefile les retrouve

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

NAME = push_swap

OBJDIR = build
# nom du dossier ou je veux mettre mes .o et .d crees pour fair eplus propre #

OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
# transforme ta liste de .c en liste de .o, mais en les mettant dans build, patsubst ca permet de substituer par pattern genre $(patsubst <motif>, <remplacement>, <liste>) #

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
