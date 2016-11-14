#ifndef DOG
#define DOG

/**
 * struct dog - structure defining a dog
 * @name: string dog name
 * @age: float number age
 * @owner: string owner name
 *
 * Description: structure defining a dog with the @name of the dog, @age of
 * the dog, and the @owner name of the dog.
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog;
#endif
