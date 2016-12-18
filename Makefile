# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etrobert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/18 15:32:17 by etrobert          #+#    #+#              #
#    Updated: 2016/12/18 16:04:43 by etrobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCDIR		= srcs
INCDIR		= includes

LSTDIR		= $(SRCDIR)/ft_list
LSTSRCNAM	= ft_list_new.c ft_list_delete.c \
			  ft_list_begin.c ft_list_end.c \
			  ft_list_it_inc.c ft_list_it_dec.c ft_list_it_get.c \
			  ft_list_push_back.c ft_list_pop_back.c \
			  ft_list_empty.c ft_list_push_front.c \
			  ft_list_it_advance.c ft_list_it_end.c \
			  ft_list_it_next.c ft_list_it_next_n.c \
			  ft_list_front.c ft_list_back.c ft_list_insert.c \
			  ft_list_erase.c ft_list_erase_range.c ft_list_apply.c ft_list_size.c \
			  ft_list_e_new.c ft_list_e_delete.c ft_list_clear.c
LSTSRC		= $(LSTSRCNAM:%=$(LSTDIR)/%)
LSTOBJ		= $(LSTSRC:%.c=%.o)

PRIDIR		= $(SRCDIR)/ft_printf
PRISRCNAM	= ft_printf.c ft_vprintf.c ft_pri_opts.c ft_pri_size.c \
			  ft_pri_format.c ft_pri_print.c ft_printf.c ft_vprintf.c \
			  ft_pri_fmt_fct.c ft_pri_fmt_fct_ox.c ft_pri_fmt_fct_cs.c \
			  ft_pri_fmt_fct_u.c ft_pri_is_number.c ft_pri_decrypt_format.c \
			  ft_pri_format_fct.c ft_pri_size_width.c ft_pri_format_units.c \
			  ft_pri_size_fct.c ft_pri_print_fct.c \
			  ft_pri_valid_format.c ft_pri_print_fmt.c \
			  ft_pri_sputwstr.c ft_pri_size_wchar.c ft_pri_sputnwstr.c
PRISRC		= $(PRISRCNAM:%=$(PRIDIR)/%)
PRIOBJ		= $(PRISRC:%.c=%.o)

MEMDIR		= $(SRCDIR)/ft_memory
MEMSRCNAM	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_memdup.c \
			  ft_nrealloc.c
MEMSRC		= $(MEMSRCNAM:%=$(MEMDIR)/%)
MEMOBJ		= $(MEMSRC:%.c=%.o)

STRDIR		= $(SRCDIR)/ft_string
STRSRCNAM	= ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
			  ft_strnew.c ft_strdel.c \
			  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
			  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strsplit.c \
			  ft_itoa.c ft_atoi.c
STRSRC		= $(STRSRCNAM:%=$(STRDIR)/%)
STROBJ		= $(STRSRC:%.c=%.o)

GNLDIR		= $(SRCDIR)/get_next_line
GNLSRCNAM	= get_next_line.c
GNLSRC		= $(GNLSRCNAM:%=$(GNLDIR)/%)
GNLOBJ		= $(GNLSRC:%.c=%.o)

BASDIR		= $(SRCDIR)/ft_base
BASSRCNAM	= ft_putnbr_fd_base.c ft_itoa_base.c \
			  ft_digits_base.c ft_ll_digits_base.c ft_uintmax_digits_base.c \
			  ft_sputull_dig.c ft_sputll_dig.c ft_sputuintmax_dig.c \
			  ft_base.c
BASSRC		= $(BASSRCNAM:%=$(BASDIR)/%)
BASOBJ		= $(BASSRC:%.c=%.o)

CHARTDIR	= $(SRCDIR)/ft_char_tools
CHARTSRCNAM	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_isblank.c ft_isspace.c ft_toupper.c ft_tolower.c
CHARTSRC	= $(CHARTSRCNAM:%=$(CHARTDIR)/%)
CHARTOBJ	= $(CHARTSRC:%.c=%.o)

HLSTDIR		= $(SRCDIR)/ft_hlist
HLSTSRCNAM	= ft_hlist.c ft_hlist_tools.c ft_hlist_it.c
HLSTSRC		= $(HLSTSRCNAM:%=$(HLSTDIR)/%)
HLSTOBJ		= $(HLSTSRC:%.c=%.o)

SLSTDIR		= $(SRCDIR)/ft_slist
SLSTSRCNAM	= ft_slist.c ft_slist_tools.c ft_slist_it.c
SLSTSRC		= $(SLSTSRCNAM:%=$(SLSTDIR)/%)
SLSTOBJ		= $(SLSTSRC:%.c=%.o)

MATHDIR		= $(SRCDIR)/ft_math
MATHSRCNAM	= ft_math.c ft_max.c ft_min_int.c
MATHSRC		= $(MATHSRCNAM:%=$(MATHDIR)/%)
MATHOBJ		= $(MATHSRC:%.c=%.o)

WCHARDIR	= $(SRCDIR)/ft_wchar
WCHARSRCNAM	= ft_putwchar.c ft_sputwchar.c ft_wchar_bits.c ft_wchar_dig.c
WCHARSRC	= $(WCHARSRCNAM:%=$(WCHARDIR)/%)
WCHAROBJ	= $(WCHARSRC:%.c=%.o)

PRINTDIR	= $(SRCDIR)/ft_print
PRINTSRCNAM	= ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
PRINTSRC	= $(PRINTSRCNAM:%=$(PRINTDIR)/%)
PRINTOBJ	= $(PRINTSRC:%.c=%.o)


SRC			= $(LSTSRC) $(PRISRC) $(MEMSRC) $(STRSRC) $(GNLSRC) $(CHARTSRC) \
			  $(HLSTSRC) $(SLSTSRC) $(MATHSRC) $(PRINTSRC)
OBJ			= $(SRC:%.c=%.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR)
LDFLAGS		=

INCNAM		= libft.h ft_bool.h ft_math.h ft_base.h ft_printf.h \
			  ft_slist.h ft_hlist.h ft_char_tools.h ft_memory.h ft_string.h \
			  ft_wchar.h get_next_line.h ft_list.h
INC			= $(INCNAM:%=$(INCDIR)/%)

GIT			= Makefile libft.xml libft.png TODO auteur

.PHONY: fclean all re git no printf check clean

all: $(NAME)

$(NAME): $(OBJ) 
	@printf "Linking\t\t%s\n"	$@
	@ar -rcs $@ $^

$(LSTOBJ): $(INCDIR)/ft_list.h $(INCDIR)/ft_bool.h

$(PRIOBJ): $(INCDIR)/ft_printf.h $(INCDIR)/ft_hlist.h $(INCDIR)/ft_base.h \
	$(INCDIR)/ft_math.h $(INCDIR)/ft_char_tools.h \
	$(INCDIR)/ft_string.h $(INCDIR)/ft_wchar.h $(INCDIR)/ft_bool.h

$(STROBJ): $(INCDIR)/ft_string.h $(INCDIR)/ft_memory.h $(INCDIR)/ft_bool.h \
	$(INCDIR)/ft_base.h $(INCDIR)/ft_char_tools.h

$(GNLOBJ): $(INCDIR)/get_next_line.h

$(BASOBJ): $(INCDIR)/ft_base.h $(INCDIR)/ft_string.h

$(CHARTOBJ): $(INCDIR)/ft_char_tools.h

$(HLSTOBJ): $(INCDIR)/ft_hlist.h $(INCDIR)/ft_slist.h

$(SLSTOBJ): $(INCDIR)/ft_slist.h $(INCDIR)/ft_bool.h

$(MATHOBJ): $(INCDIR)/ft_math.h

$(PRINTOBJ): $(INCDIR)/ft_print.h $(INCDIR)/ft_string.h

%.o: %.c $(INC)
	@printf "Compiling\t%s\n"	$@
	@$(CC) -c $(CFLAGS) -o $@ $< 

git:
	@echo Adding files to git repository
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
	@echo Suppressing obj files
	@rm -rf $(OBJ)

fclean: clean
	@echo Suppressing $(NAME)
	@rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	@$(MAKE) all
