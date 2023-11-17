#include "main.h"

/**
 * get_the_path - get the full path
 * @name: argument name
 * Return: always success
 */

char *get_the_path(char *name_file)
{
	char *path = getenv("PATH");
	char *full_path;

	if (start_with_slash(name_file) && access(name_file, X_OK) == 0)
		return (strdup(name_file));

	if (!path)
	{
		perror("path not found");
		return (NULL);
	}

	full_path = get_location_file(path, name_file);

	if (full_path == NULL)
	{
		write(2, name_file, strlen(name_file));
		write(2, ": command not found\n", 19);
		return (NULL);
	}

	return (full_path);
}

/**
 * get_location-file - get the executable path
 * @path: path variable
 * @name: executable path
 * Return; absolute path to the executable
 */

char *get_location_file(char *path, char *name_file)
{
	char *path_copy, *token;
	struct stat file_path;
	char *path_buffer = NULL;

	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(strlen(token) + strlen(name_file) + 2);
		if (!path_buffer)
		{
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, name_file);
		strcat(path_buffer, "\0");

		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_buffer)
		free(path_buffer);
	return (NULL);
}


/**
 * startswithslash - file start with "/"
 * @str: file to be checked
 * Return: 0 if yes and 1 if NO
 */

int start_with_slash(const char *str)
{
	if (str != NULL || str[0] == '/')
		return (1);

	return (0);
}
