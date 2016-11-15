#ifndef DOG_H
#define DOG_H

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
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif
