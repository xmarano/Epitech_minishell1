/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-leo.gregori
** File description:
** my.h
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#ifndef MY_H
    #define MY_H
int my_put_nbr(int nb);
int my_atoi(char *str);
char my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr_recursive(int nb);
char *my_strdup(char const *src);
int my_printf(const char *format, ...);
int my_strcmp(char const *s1, char const *s2);
#endif