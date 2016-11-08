NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS	=
SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c \
		  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		  ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isblank.c ft_isspace.c \
		  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		  ft_strsplit.c ft_itoa.c ft_atoi.c \
		  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_putnbr_fd_base.c ft_digits_base.c ft_itoa_base.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		  ft_lstiter.c ft_lstmap.c ft_lstfold.c \
		  ft_memdup.c
OBJDIR	= objs
OBJ		= $(SRC:%.c=$(OBJDIR)/%.o)
DEPS	= libft.h
GIT		= Makefile auteur

.PHONY: fclean all re git no printf check clean 

all: $(NAME)

$(NAME): $(OBJ) 
	ar -rcs $@ $^

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

git:
	git add $(SRC) $(DEPS) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(DEPS)

printf:
	@echo "Detection des printf :\033[1;31m"
	@cat $(SRC) $(DEPS) | grep printf | cat
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
