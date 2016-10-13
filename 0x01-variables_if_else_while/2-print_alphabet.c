#include <stdio.h>

/**
 * main - print out alphabet in lower case in order
 * Return: 0
 */
int main(void)
{
  int i;
  i = 97;
while (i<123) {
    putchar(i);
    i++;
}
putchar('\n');
return (0);
}
