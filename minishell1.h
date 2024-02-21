/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** minishell1.h
*/
#include "my.h"
#ifndef MINISHELL1_H
    #define MINISHELL1_H

typedef struct S {
    char *input;
    char **arr;
    char **arr_path;
    char **arr_execve;
    char **execute;
    int nb;
    int nb2;
} S_t;

void istty(char **argv, char **env, S_t *s);
int isnottty(char **argv, char **env, S_t *s);
#endif
