#include "main.h"

/**/
#define MAX_REP_LEN 250
char *convert(unsigned int num, unsigned int base)
{
	int i, j;

	static char figurative[] = "0123456789ABCDEF";
	static char buffer[MAX_REP_LEN];
	char converted[2048];
	char *ptr = converted;

	if (num == 0) {
        	converted[0] = '0';
        	converted[1] = '\0';
  		return (0);
	}
	i = MAX_REP_LEN - 1;
	
	do
	{
		buffer[--i] = figurative[num % base];
		num /= base;
	} while (num < 1);


	for (j = i + 1; j <= MAX_REP_LEN - 1; j++)
	{
		*ptr++ = buffer[j];
	}
	*ptr = '\0';
	
	return (ptr);
}
