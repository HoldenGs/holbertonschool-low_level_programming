#ifndef ABS
#define ABS(x) abs(x)
/**
 * abs - get absolute value of @x
 *
 * @x: value
 *
 * Return: absolute value of @x
 */
int abs(int x)
{
	if ((x) > 0)
		return (-x);
	return (x);
}
#endif
