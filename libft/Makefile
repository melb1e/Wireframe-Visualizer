NAME = libft.a

SRCS = ft_tolower.c ft_toupper.c ft_strrchr.c \
ft_strnstr.c ft_strncmp.c ft_strlen.c ft_strlcpy.c \
ft_strlcat.c ft_strdup.c ft_strchr.c ft_memset.c \
ft_memmove.c ft_memcmp.c ft_memchr.c ft_memcpy.c ft_isprint.c \
ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c ft_calloc.c ft_bzero.c \
ft_atoi.c ft_isspace.c \
ft_strjoin.c  ft_split.c \
ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c \
ft_substr.c ft_strtrim.c ft_itoa.c \
ft_striteri.c ft_strmapi.c get_next_line/get_next_line_utils.c \
get_next_line/get_next_line.c ft_strdel.c ft_atoi_base.c \
ft_free_second_level_arr.c ft_max.c ft_mod.c ft_sign.c \
ft_wcount.c ft_percent.c ft_find_index.c ft_memalloc.c \
ft_strchrs.c ft_strdel.c ft_strsubchr.c ft_strsub.c \
ft_strnew.c

INCREMAKE = libft.h \
			get_next_line/get_next_line.h \
			Makefile
		
OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${INCREMAKE}
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${INCREMAKE}
		ar rcs ${NAME} ${OBJS}

bonus:	${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all