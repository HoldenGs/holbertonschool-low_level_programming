#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_dog - create a new dog
 * @name: dog name
 * @age: dog age
 * @owner: owner name
 *
 * Return: dog_t; NULL if failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doge;

	doge = malloc(sizeof(dog_t));
	if (doge == NULL)
		return (NULL);

	doge->name = name;
	doge->age = age;
	doge->owner = owner;

	return (doge);
}
