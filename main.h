#ifndef MAIN_H
#define MAIN_H

/**
 * file: main.h
 * description: this is the header file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* handling path functions */

char *get_location_file(char *path, char *name_file);
char *get_the_path(char *name_file);
int start_with_slash(const char *str);

#endif /*MAIN_H*/

