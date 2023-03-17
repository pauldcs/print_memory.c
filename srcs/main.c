#include "hexdump.h"
#include "libstringf.h"
#include <stdlib.h>
#include <string.h>

void print_usage(void) {
	fputstr(1,
		"Usage: ./hdump [OPTIONS] FILE\n\n"
		"Description:\n"
		"  Display the contents of a file in hexadecimal format.\n\n"
		"Options:\n"
		"  --stdin         Read from stdin instead of a file"
		"  --size=SIZE     Maximum number of bytes to read from the file (default: unlimited).\n"
		"  --start=OFFSET  Starting byte offset to read from (default: 0).\n"
		"  --end=OFFSET    Ending byte offset (default: end of file).\n"
		"  --raw           Output raw bytes in hexadecimal format, without formatting.\n\n"
		"Arguments:\n"
		"  FILE            The path to the file to be read.\n\n"
	);
}

static const char *get_next_argument(int *ac, char ***av)
{
	if (*ac) {
		--(*ac);
		return (*++*av);
	}
	return (NULL);
}

int main(int ac, char *av[])
{
	t_dump_params 	params;
	char			*ptr;

	if (ac < 2) {
		display_usage();
		return (EXIT_FAILURE);
	}
	memset(&params, 0, sizeof(params));
	while ((ptr = (char *)get_next_argument(&ac, &av)) != NULL) {
		if (!parse_argument(ptr, &params))
			return (EXIT_FAILURE);
	}
	return (!hexdump(&params));
}
