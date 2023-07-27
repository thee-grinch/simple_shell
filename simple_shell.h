#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int _putchar(char c);
void _puts(char *s);
char *_strcpy(char *, char *);
int calculate_tokens(char *s);
int _strlen(char *s);
void tokenize(char *, char **);
void free_all(char **);
int execute(char **s, char *command);
void _strcat(char *, char *);
char *_which(char *command, char *token, char *pathcheck, char *pathcpy);

void free_them(char *first, ...);
#endif
