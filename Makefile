NAME = parser

HEADER = parser.h 

LIST_C = parser_main.c parser_utils.c

OBJ_C = ${patsubst %.c, ${OBJ}%.o, ${LIST_C}}

FLAGS = -Wall -Wextra -Werror

READL = -L/usr/local/lib -I/usr/local/include -lreadline
LIBFT = -L./src/libft -lft

SRC = src/
OBJ = obj/

GREEN = \033[0;32m
NC = \033[0m

all : ${NAME}
	@echo -n "${GREEN} DONE ! ${NC}"

${NAME} : ${OBJ_C} ${OBJ} ${LIBFT}
	@gcc -g -o ${NAME} ${FLAGS} ${OBJ_C} ${READL} ${LIBFT}

${LIBFT} :
	make bonus -C ${SRC}libft

${OBJ}%.o : ${SRC}%.c ${HEADER}
	@mkdir -p ${OBJ}
	@gcc ${FLAGS} -c $< -o $@

clean :
	@make clean -C ${SRC}libft
	@rm -rf ${OBJ_C} ${OBJ}
	@echo "object files was deleted"

fclean : clean
	@make fclean -C ${SRC}libft
	@rm -f ${NAME}
	@echo "${NAME} was deleted"

re : fclean all

.PHONY : all clean fclean re 