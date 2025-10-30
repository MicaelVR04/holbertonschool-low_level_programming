#include <stdio.h>

/**
 * main - prints the program name followed by a new line
 * @argc: number of command line arguments
 * @argv: array of strings containing the arguments
 *
 * Return: 0 (success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
