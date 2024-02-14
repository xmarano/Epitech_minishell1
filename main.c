/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** main.c
*/
#include "minishell1.h"
#include "my.h"

static void check_basic(S_t *s)
{
    if (my_strcmp(s->input, "exit") == 0)
        exit(0);
}

void input_to_arr(S_t *s)
{
    char *bin = "/bin/\0";

    s->arr = malloc(50 * sizeof(char *));
    s->arr = str_to_word_array(s->input);
    bin = my_strcat(bin, s->arr[0]);
    s->arr[0] = bin;
}

void shell_command(char **argv, char **env, S_t *s)
{
    int fork_info = fork();

    if (fork_info == 0) {
        execve(s->arr[0], s->arr, env);
        exit(0);
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
        my_printf("\x1b[38;5;208m" "➤  " "\x1b[36m" "~ " "\x1b[0m");
        s.input = malloc(input_size);
        getline(&s.input, &input_size, stdin);
        if (my_strcmp(s.input, "\n\0") != 0) {
            for (int i = 0; s.input[i] != '\0'; i++)
                n = i;
            s.input[n] = '\0';
            input_to_arr(&s);
            check_basic(&s);
            shell_command(argv, env, &s);
        }
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
