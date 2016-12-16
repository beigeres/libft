NAME	= libft.a

SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes

SRCNAM	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
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
		  ft_putnbr_fd_base.c ft_itoa_base.c \
		  ft_memdup.c ft_nrealloc.c \
		  ft_slist.c ft_slist_tools.c ft_slist_it.c \
		  ft_hlist.c ft_hlist_tools.c ft_hlist_it.c \
		  ft_math.c ft_max.c \
		  ft_digits_base.c ft_ll_digits_base.c ft_uintmax_digits_base.c \
		  ft_sputull_dig.c ft_sputll_dig.c ft_sputuintmax_dig.c \
		  ft_printf.c ft_vprintf.c ft_pri_opts.c ft_pri_size.c \
		  ft_pri_format.c ft_pri_print.c ft_printf.c ft_vprintf.c \
		  ft_pri_fmt_fct.c ft_pri_fmt_fct_ox.c ft_pri_fmt_fct_cs.c \
		  ft_pri_fmt_fct_u.c ft_pri_is_number.c ft_pri_decrypt_format.c \
		  ft_putwchar.c ft_sputwchar.c ft_wchar_bits.c ft_wchar_dig.c \
		  ft_sputwstr.c ft_sputnwstr.c ft_pri_size_fct.c ft_pri_print_fct.c \
		  ft_pri_format_fct.c ft_pri_size_width.c ft_pri_format_units.c \
		  ft_size_wchar.c ft_pri_valid_format.c ft_pri_print_fmt.c \
		  ft_base.c get_next_line.c \
		  ft_list_new.c ft_list_delete.c \
		  ft_list_begin.c ft_list_end.c \
		  ft_list_it_inc.c ft_list_it_dec.c \
		  ft_list_push_back.c ft_list_pop_back.c \
		  ft_list_empty.c ft_list_push_front.c \
		  ft_list_it_advance.c ft_list_it_end.c \
		  ft_list_it_next.c ft_list_it_next_n.c \
		  ft_list_front.c ft_list_back.c ft_list_insert.c \
		  ft_list_erase.c ft_list_erase_range.c ft_list_apply.c ft_list_size.c \
		  ft_list_e_new.c ft_list_e_delete.c ft_list_clear.c

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR) -g
LDFLAGS	=  -g

INCNAM	= libft.h ft_bool.h ft_math.h ft_base.h ft_printf.h \
		  ft_slist.h ft_hlist.h ft_char_tools.h ft_memory.h ft_string.h \
		  ft_wchar.h get_next_line.h ft_alloc.h ft_list.h
INC		= $(INCNAM:%=$(INCDIR)/%)

GIT		= Makefile libft.xml libft.png TODO auteur

.PHONY: fclean all re git no printf check clean

all: $(NAME)

$(NAME): $(OBJ) 
	ar -rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $< 

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
