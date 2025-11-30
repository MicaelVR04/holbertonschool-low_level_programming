#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: number of bytes read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount, wcount;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	rcount = read(fd, buf, letters);
	if (rcount <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	wcount = write(STDOUT_FILENO, buf, rcount);

	free(buf);
	close(fd);

	if (wcount == -1 || wcount != rcount)
		return (0);

	return (wcount);
}
