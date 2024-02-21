/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** main.c
*/
#include "minishell1.h"
#include "my.h"

static void path_to_bin(S_t *s, char **env, int i)
{
    char *path = NULL;
    int j = 0;

    s->arr_path = malloc(100 * sizeof(char *));
    path = strtok(env[i] + 5, ":");
    while (path != NULL) {
        s->arr_path[j] = malloc(my_strlen(path) * sizeof(char));
        s->arr_path[j] = path;
        s->arr_path[j] = my_strcat(s->arr_path[j], "/");
        path = strtok(NULL, ":");
        j++;
    }
    return;
}

int shell(char **argv, char **env)
{
    S_t s;

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
        env[i][2] == 'T' && env[i][3] == 'H')
            path_to_bin(&s, env, i);
    }
    if (isatty(0)) {
        istty(argv, env, &s);
    } else {
        return isnottty(argv, env, &s);
    }
    free(s.input);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1)
        return 84;
    return shell(argv, env);
}
