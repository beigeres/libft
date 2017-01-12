NAME		= exec

SRCDIR		= .
OBJDIR		= objs
INCDIR		= includes

#SRCNAM		= list_cpp_begin.c
#SRCNAM		= vector_test.c
#SRCNAM		= vector_new_test.c
#SRCNAM		= test_gnl.c
SRCNAM		= test_list_erase.c
INCNAM		=

CC			= clang
CFLAGS		= -Wall -Wextra -I$(INCDIR) -I $(LIBFTDIR)/includes -g
LDFLAGS		= -L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%) -g

GIT			= README.md

LIBFTDIR	= ../
LIBFTNAM	= libft.a
LIBFT		= $(LIBFTNAM:%=$(LIBFTDIR)/%)

SRC			= $(SRCNAM:%=$(SRCDIR)/%)
INC			= $(INCNAM:%=$(INCDIR)/%)
OBJ			= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re $(LIBFT)

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)| grep -B1 Error | cat

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	$(MAKE) all
