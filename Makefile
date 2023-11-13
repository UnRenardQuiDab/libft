# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 17:41:39 by bwisniew          #+#    #+#              #
#    Updated: 2023/11/13 12:52:01 by bwisniew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
C_FLAGS=-Wall -Wextra -Werror -MMD -MP
LIBC=ar
LIBC_FLAG=crs 
SRC=ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c
SRC_BONUS=ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c
OUTDIR=output
OBJ=$(SRC:%.c=${OUTDIR}/%.o)
OBJ_BONUS=$(SRC_BONUS:%.c=${OUTDIR}/%.o)
DEP=$(OBJ:.o=.d)
DEP_BONUS=$(OBJ_BONUS:.o=.d)
INCLUDE=/libft.h
NAME=libft.a

all: $(NAME)

-include ${DEP} ${DEP_BONUS}

$(NAME): $(OBJ)
	$(LIBC) $(LIBC_FLAG) $(NAME) $(OBJ)

${OUTDIR}/%.o: %.c | ${OUTDIR}
	$(CC) $(C_FLAGS) -I $(INCLUDE) -c -o $@ $<

bonus: $(OBJ) $(OBJ_BONUS)
	${MAKE} ${NAME} SRC="${SRC} ${SRC_BONUS}"

${OUTDIR}:
	mkdir -p $@

clean:
	rm -rf ${OUTDIR}

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re