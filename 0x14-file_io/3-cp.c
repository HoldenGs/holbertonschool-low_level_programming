#include "holberton.h"

/**
 * main - copy a file from one name to another
 * @ac: number of arguments
 * @av: pointer to arguments
 *
 * Return: 0 on success; 97 on
 */
int main(int ac, char **av)
{
	int fdr, fdw, rlength, wlength, rclose, wclose;
	char buf[BUFFERSIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fdr = open(av[1], O_RDONLY);
	if (fdr == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	fdw = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fdw == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	rlength = wlength = 1;
	while (rlength)
	{
		rlength = read(fdr, buf, BUFFERSIZE);
		if (rlength == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
		if (rlength > 0)
		{
			wlength = write(fdw, buf, rlength);
			if (wlength == -1)
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
		}
	}
	rclose = close(fdr);
	if (rclose == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdr), exit(100);
	wclose = close(fdw);
	if (wclose == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdw), exit(100);
	return (0);
}
