#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int i = fork();
	if (i == 0)
		printf("This is the child process!!!\n");
	return (0);
}
