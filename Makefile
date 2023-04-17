CC  =  cc
CFLAGS    =    -Wall -Wextra -Werror
ARGS = -Iinclude -lglfw -L"/Users/slazar/goinfre/homebrew/Cellar/glfw/3.3.8/lib"
MLX42_DIRECTORY = /Users/slazar/MLX42/
MLX42 = $(MLX42_DIRECTORY)build/libmlx42.a
MLX42_HEADERS = $(MLX42_DIRECTORY)include/


SRCS =	so_long.c\
		srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/so_long_p1.c\
		srcs/so_long_p2.c\
		srcs/so_long_p3.c\
		srcs/so_long_p4.c

SRCSB =	so_long_bonus.c\
		srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/so_long_p1.c\
		srcs/so_long_p2.c\
		srcs/so_long_p3.c\
		srcs/so_long_p4.c

OBJS    =    ${SRCS:.c=.o}
OBJSB    =    ${SRCSB:.c=.o}
NAME    =    so_long
NAMEBONUS	=	so_long_bonus
RM    =    rm -rf

%.o : %.c
		${CC} $^ -c -o $@

all: ${NAME}

${NAME}:    ${OBJS}
			@echo "\033[0;32m"
			${CC} ${CFLAGS} ${OBJS} ${MLX42} ${ARGS} -o ${NAME}

${NAMEBONUS}:	${OBJSB}
			@echo "\033[0;32m"
			${CC} ${CFLAGS} ${OBJSB} ${MLX42} ${ARGS} -o ${NAMEBONUS}

bonus:     ${NAMEBONUS}

clean:
		@echo "\033[1;31m"
		${RM} ${OBJS} ${OBJSB}

fclean:    clean
			@echo "\033[1;31m"
			${RM} ${NAME} ${NAMEBONUS}

re:        fclean all