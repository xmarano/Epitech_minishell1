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
        return 2;
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
        s->execute[0] = malloc(my_strlen(s->input) * sizeof(char));
        s->execute[0] = s->input;
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
    return 0;
}

int isnottty(char **argv, char **env, S_t *s)
{
    size_t input_size = 0;
    int n = 0;

        s->input = malloc(input_size);
        getline(&s->input, &input_size, stdin);
        if (s->input[0] != ' ' && s->input[0] != '\t' && s->input[0] != '\n'
        && s->input[0] != '!' && s->input[0] > 0 && s->input[0] < 127) {
            for (int i = 0; s->input[i] != '\0'; i++)
                n = i;
            s->input[n] = '\0';
            if (s->input[0] == '.' || s->input[0] == '/') {
                return execute2(argv, env, s);
            }
            input_to_arr2(s, env);
            check_basic2(s);
            return shell_command2(argv, env, s);
        }
    return 0;
}