/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** main.c
*/
#include "minishell1.h"
#include "my.h"

void shell_command(char **argv, char **env, S_t s)
{
    char *str[] = {"/bin/", NULL};
    str[0] = my_strcat(str[0], s.input);
    int fork_info = fork();

    if (fork_info == 0) {
        execve(str[0], str, env);
        return;
    } else {
        wait(NULL);
    }
}

void shell(char **argv, char **env)
{
    size_t input_size = 0;
    int n = 0;
    S_t s;

    while (1) {
        my_printf("➤ ");
        s.input = malloc(input_size);
        getline(&s.input, &input_size, stdin);
        for (int i = 0; s.input[i] != '\0'; i++)
            n = i;
        s.input[n] = '\0';
        shell_command(argv, env, s);
        free(s.input);
    }
    return;
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1)
        return 84;
    shell(argv, env);
    return 0;
}
