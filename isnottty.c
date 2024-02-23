/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** isnottty.c
*/
#include "minishell1.h"
#include "my.h"

int shell_command2(char **argv, char **env, S_t *s)
{
    int fork_info = fork();
    int status;

    if (fork_info == 0) {
        for (int i = 0; s->arr_execve[i] != NULL; i++) {
            free(s->arr[0]);
            s->arr[0] = malloc(my_strlen(s->arr_execve[i]) * sizeof(char));
            s->arr[0] = s->arr_execve[i];
            execve(s->arr[0], s->arr, env);
        }
        my_printf("%s: Command not found.\n", s->input);
        exit(2);
    } else {
        wait(&status);
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
        else
            return 0;
    }
}

static void check_basic2(S_t *s)
{
    if (my_strcmp(s->input, "exit") == 0)
        exit(0);
}

void input_to_arr2(S_t *s, char **env)
{
    s->arr = malloc(50 * sizeof(char *));
    s->arr = str_to_word_array(s->input);
    s->arr_execve = malloc(100 * sizeof(char *));
    for (int i = 0; s->arr_path[i] != NULL; i++) {
        s->arr_execve[i] = malloc(my_strlen(s->arr_path[i])
        + my_strlen(s->arr[0]) * sizeof(char));
        s->arr_execve[i] = my_strcat(s->arr_execve[i], s->arr_path[i]);
        s->arr_execve[i] = my_strcat(s->arr_execve[i], s->arr[0]);
    }
    return;
}

int execute2(char **argv, char **env, S_t *s)
{
    int fork_info = fork();
    int status;

    if (fork_info == 0) {
        s->execute = malloc(10 * sizeof(char *));
        s->execute[0] = malloc(my_strlen(s->input) + 2 * sizeof(char));
        s->execute[0] = my_strcat(s->execute[0], "./");
        s->execute[0] = my_strcat(s->execute[0], s->input);
        execve(s->execute[0], s->execute, env);
    } else {
        wait(&status);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            my_printf("Segmentation fault\n");
            return 0;
        }
    }
    exit(1);
    return 1;
}

static void error_handling(S_t *s)
{
    s->nb = 0;
    for (int i = 0; s->input[i] != '\0'; i++) {
        if (s->input[i] == ' ' || s->input[i] == '\t' || s->input[i] == '\n')
            s->nb++;
    }
}

static void remove_n(S_t *s)
{
    int n = 0;

    for (int i = 0; s->input[i] != '\0'; i++)
        n = i;
    if (s->input[n] == '\n')
        s->input[n] = '\0';
}

static void error_handling2(S_t *s)
{
    s->nb = 0;
    for (int i = 0; s->input[i] != '\0'; i++) {
        if (s->input[i] < 0 || s->input[i] > 127)
            s->nb++;
    }
}

int echo_command(char **argv, char **env, S_t *s)
{
    input_to_arr2(s, env);
    if (my_strcmp(s->arr[0], "setenv") == 0 || my_strcmp(s->arr[0], "cd") == 0)
        return check_setenv_cd(argv, env, s);
    check_basic2(s);
    shell_command2(argv, env, s);
    return 0;
}

int isnottty(char **argv, char **env, S_t *s)
{
    size_t input_size = 0;

    s->input = malloc(input_size);
    while (getline(&s->input, &input_size, stdin) != -1) {
        error_handling(s);
        if (s->nb == my_strlen(s->input))
            return 0;
        remove_n(s);
        error_handling2(s);
        if (s->nb != 0) {
            my_printf("%s: Command not found.\n", s->input);
            return 2;
        }
        if (execute2(argv, env, s) == 0)
            return 0;
        s->r = echo_command(argv, env, s);
    }
    return 0;
}
