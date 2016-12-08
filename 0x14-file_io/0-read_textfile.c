#include "holberton.h"

/**
 * read_textfile - read a text file and print it to POSIX stdout
 * @filename: name of file
 * @letters: number of letters that should be printed
 *
 * Return: actual number of letters printed; 0 if error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t length;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	length = read(fd, buffer, letters);
	if (length == -1)
		return (0);
	write(1, buffer, length);
	close(fd);
	free(buffer);
	return (length);
}
