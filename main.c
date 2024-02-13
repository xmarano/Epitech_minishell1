/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** main.c
*/
#include "minishell1.h"
#include "my.h"

void ls_shell(char **argv, char **env)
{
    char *str[] = {"/bin/ls", NULL};
    int fork_info = fork();

    if (fork_info == 0) {
        execve(str[0], str, env);
        return;
    } else {
        wait(NULL);
    }
}

int main(int argc, char **argv, char **env)
{
    char *input;
    size_t input_size = 0;

    while (1) {
        my_printf("➤ ");
        input = malloc(input_size);
        getline(&input, &input_size, stdin);
        if (my_strcmp("ls\n", input) == 0)
            ls_shell(argv, env);
        free(input);
    }
    return 0;
}
