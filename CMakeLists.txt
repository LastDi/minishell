cmake_minimum_required(VERSION 3.10)
project(minishell C)

set(CMAKE_C_STANDARD 99)

find_library(READLINE readline /usr/local/lib)

add_executable(minishell main.c minishell.c access_dir.c default_command_utils_1.c default_commands_1.c default_commands_2.c
        default_commands_3.c default_commands_4.c default_commands_5.c default_command_utils_2.c default_command_utils_3.c
        error.c exec_pipe.c exec_start.c exec_utils.c parser_main.c parser_utils.c preparser.c
        redirect.c redirect_input.c redirect_utils.c shell_utils_2.c shell_split.c shell_utils_1.c sig_handlers.c
        split.c utils_1.c utils_2.c utils_3.c utils_4.c utils_5.c free_utils.c)

target_link_libraries(minishell LINK_PUBLIC ${READLINE})