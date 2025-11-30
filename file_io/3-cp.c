#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * open_file_from - opens file_from for reading
 * @filename: file to open
 *
 * Return: file descriptor
 * Exit: 98 on error
 */
int open_file_from(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_file_to - opens file_to for writing
 * @filename: file to open/create
 *
 * Return: file descriptor
 * Exit: 99 on error
 */
int open_file_to(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor
 *
 * Exit: 100 on error
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from fd_from to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 *
 * Exit: 98 if read fails, 99 if write fails
 */
void copy_file(int fd_from, int fd_to)
{
	ssize_t rcount, wcount;
	char buffer[BUFFER_SIZE];

	while ((rcount = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		wcount = write(fd_to, buffer, rcount);
		if (wcount != rcount)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (rcount == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}
}

/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 * Exit: 97 if incorrect number of arguments
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(argv[1]);
	fd_to = open_file_to(argv[2]);
	copy_file(fd_from, fd_to);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
