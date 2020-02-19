#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Fibonacci.h"

// print a HugeInteger (followed by a newline character)
void hugePrint(HugeInteger *p)
{
	int i;

	if (p == NULL || p->digits == NULL)
	{
		printf("(null pointer)\n");
		return;
	}

	for (i = p->length - 1; i >= 0; i--)
		printf("%d", p->digits[i]);
	printf("\n");
}

int main(void)
{
	unsigned int *temp;
	HugeInteger *p;

	hugePrint(p = parseString("12345"));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseString("354913546879519843519843548943513179"));
	temp = toUnsignedInt(p);
	if (temp == NULL)
		printf("Good work.\n");
	else
		printf("Uh oh...\n");
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseString(NULL));
	temp = toUnsignedInt(p);
	if (temp == NULL)
		printf("Good work.\n");
	else
		printf("Uh oh...\n");
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(246810));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(0));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(INT_MAX));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(UINT_MAX));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	return 0;
}
