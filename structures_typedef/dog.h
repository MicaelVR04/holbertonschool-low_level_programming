#ifndef DOG_H
#define DOG_H
/**
 * struct dog - defines a new type of structure
 * @name: pointer to dogs name
 * @age: dogs age (float)
 * @owner: pointer to owners name (string)
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
