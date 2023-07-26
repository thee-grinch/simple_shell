#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
void printprompt(void);
int _strlen(char *s);
char *_strcpy(char *destination, char *source);
char **tokenize(char *, char **);
int calculate_tokens(char *s);
void release_memory(char **);
int execute(char **, char *);
char *_which(char *);
char *_strcat(char *, char *);
char *allocate(char *, int);

#endif
