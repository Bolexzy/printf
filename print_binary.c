#include "main.h"

/**/
int _printfBin(va_list args)
{
	char *bin_buff;
	int bin_len;

	bin_buff = litoa(va_arg(args, int), 2);
	bin_len = print((bin == NULL) ? "(NULL)" : bin);

	return bin_len;
}
