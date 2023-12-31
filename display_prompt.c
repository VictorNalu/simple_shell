#include "main.h"

/**
 * main - Entry point
 *Description: Display a prompt
 *Return: Always 0 (Success)
 */
int main(void);
int main(void)
{
	char *input = NULL, *tok;
	size_t count = 0;
	ssize_t read;
	pid_t child_pid;
	int i, starts;
	char **array;
	char *delim = "\n";
	char *path;
	int num_tok = 0;
	char prompt[] = "my_shell$ ";

	while (true)
	{
		if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	read = getline(&input, &count, stdin);

	if (read == -1)
	{
		exit(0);
	}

	tok = strtok(input, delim);

	array = malloc(sizeof(char *) * num_tok);
	i = 0;

	while (tok != NULL)
	{
		array[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;

	path = get_the_path(array[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(path, array, NULL) == -1)
		{
			perror("failed to execute");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&starts);
	}

	free(path);
	free(array);

	}
	free(input);
	free(delim);
	return (0);
}
