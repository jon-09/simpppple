#include "header.h"

void _ls(const char *dir, int op_a, int op_l)
{
	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh)
	{
		if (errno = ENOENT)
			perror("Directory doesn't exist");
		
		else
			perror("Unable to read directory");
		
		exit(EXIT_FAILURE);
	}
	
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;

		printf("%s  ", d->d_name);
		if(op_l) printf("\n");
	}
	if(!op_l)
		printf("\n");

}	
