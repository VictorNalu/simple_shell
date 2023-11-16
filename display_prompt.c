#include "main.h"

/**
 * main - Entry point
 *Description: Display a prompt
 *Return: Always 0 (Success)
 */
int main(void);
int main(void)
{
	char prompt[] = "my_shell$ ";
	char *input = NULL, *tok;
	size_t count = 0;
	ssize_t read;
	pid_t child_pid;
	int i, starts;
	char **array;
	char *delim = "\n";

	while (true)
	{
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	read = getline(&input, &count, stdin);

	if (read == -1)
	{
		perror("exiting my shell");
		exit(1);
	}

	tok = strtok(input, delim);

	array = malloc(sizeof(char *) * 1023);
	i = 0;

	while (tok != NULL)
	{
		array[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&starts);
	}

	}
	free(input);
}
