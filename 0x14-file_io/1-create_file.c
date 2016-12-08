#include "holberton.h"

/**
 * create_file - create a file
 * @filename: name of file
 * @text_content: content of file
 *
 * Return: 1 upon success; -1 upon failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, i, out;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != 0; i++)
			;
		out = write(fd, text_content, i);
		if (out == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
