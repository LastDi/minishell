NAME = minishell

SRCS =	main.c minishell.c error.c preparser.c \
		parser_main.c parser_utils.c sig_handlers.c\
        shell_split.c access_dir.c default_command_utils.c \
        default_commands_1.c default_commands_2.c default_commands_3.c \
        default_commands_4.c default_commands_5.c \
        exec_pipe.c exec_start.c exec_utils.c \
        free_utils.c redirect.c redirect_input.c \
        redirect_utils.c shell_utils.c \
        split.c utils_1.c utils_2.c utils_3.c
#            		delete_it.c \

INCLUDE = minishell.h

READLINE= -L/usr/local/lib -I/usr/local/include -lreadline

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I ./

all		:	$(NAME)

 %.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I ./ -o $(NAME) $(READLINE)

clean	:
			@rm -rf $(OBJS)
			@rm -rf $(OBJS_B)

fclean	:	clean
			@rm -rf $(NAME)
			@rm -rf $(NAME_B)

re		:	fclean all

.PHONY: clean fclean re all