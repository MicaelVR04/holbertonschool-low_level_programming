#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @s: string pointer
 *
 * Return: length of s
 */
static size_t _strlen(char *s)
{
	size_t len = 0;

	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: string to write into the file (can be NULL)
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t wcount;
	size_t len;

	if (filename == NULL)
		return (-1);

	/* Create or truncate, write-only, permissions rw-r--r-- */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = _strlen(text_content);
		if (len > 0)
		{
			wcount = write(fd, text_content, len);
			if (wcount == -1 || (size_t)wcount != len)
			{
				close(fd);
				return (-1);
			}
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
