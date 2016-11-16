/**
 * print_name - print @name via function pointer @f
 * @name: name
 * @f: function used to print @name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
