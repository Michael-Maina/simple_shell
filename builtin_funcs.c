#include "main.h"

void __exit(char **cmd)
{
	int i = 0, status;

	if (cmd[1] == NULL)
	{
		exit(EXIT_SUCCESS);
		return;
	}

	while(cmd[1][i])
	{
		if(_isdigit(cmd[1][i]) == 0)
		{
			perror("ERROR!!!");
			return;
		}
	i++;
	}
	status = _atoi(cmd[1]);
	exit(status);
}
