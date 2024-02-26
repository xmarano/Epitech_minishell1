/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** check_setenv_cd.c
*/
#include "minishell1.h"
#include "my.h"

int do_setenv2(S_t *s)
{
    if (s->arr[1][0] < 65 || s->arr[1][0] > 90 && s->arr[1][0] < 97
    || s->arr[1][0] > 122) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return 1;
    }
    for (int i = 1; s->arr[1][i] != '\0'; i++) {
        if (s->arr[1][i] > 9 && s->arr[1][i] < 65 || s->arr[1][i] > 90
        && s->arr[1][i] < 97 || s->arr[1][i] > 122) {
            write(2, "setenv: Variable name must contain ", 36);
            write(2, "alphanumeric characters.\n", 26);
            return 1;
        }
    }
    return 0;
}

int do_setenv(char **argv, char **env, S_t *s)
{
    int nb_args = 0;

    for (int i = 0; s->arr[i] != NULL; i++)
        nb_args = i;
    if (nb_args == 0) {
        for (int i = 0; env[i] != NULL; i++)
            my_printf("%s\n", env[i]);
        return 0;
    }
    if (nb_args > 2) {
        write(2, "setenv: Too many arguments.\n", 29);
        return 1;
    }
    if (do_setenv2(s) == 1)
        return 1;
    return 0;
}

int do_unsetenv(char **argv, char **env, S_t *s)
{
    int nb_args = 0;

    for (int i = 0; s->arr[i] != NULL; i++)
        nb_args = i;
    if (nb_args == 0) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return 1;
    }
    return 0;
}

int check_setenv_cd(char **argv, char **env, S_t *s)
{
    if (my_strcmp(s->arr[0], "setenv") == 0)
        return do_setenv(argv, env, s);
    if (my_strcmp(s->arr[0], "unsetenv") == 0)
        return do_unsetenv(argv, env, s);
    return 0;
}
