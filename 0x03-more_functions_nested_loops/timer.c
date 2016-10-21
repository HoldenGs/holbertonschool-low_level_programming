#include "holberton.h"
#include <time.h>
#include <stdio.h>

/**
 * main - time the performance of a function
 *
 * Return: 0
 */
int main(void)
{
	int msec;

	clock_t start = clock(), diff;
	primefind();
	diff = clock() - start;

	msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken %d seconds %d milliseconds\n", msec / 1000, msec % 1000);

	return (0);
}
