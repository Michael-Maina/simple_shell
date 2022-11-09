#include "main.h"

void path_finder(char **cmd)
{
	char *path, *token, *token_cmd, *temp;
	char *array[1024];
	int j, i = 0, k;
	struct stat *buff = NULL;
	int len = 0;

	path = _getenv("PATH");

	while(path[len] != '\0')
		len++;

	printf("path: %s\nlen: %d\n", path, len);
	token = strtok(path, ":");

	while(token)
	{
		array[i++] = token;
		/*printf("%s\n array: %s\n", token, array[i]);*/
		token = strtok(NULL, ":");
	}
	k = i;
	printf("%d\n", k);	
	i = 0;
	while(i < k)
	{
		printf("%s\n", array[i]);
		i++;
	}
	i = 0;
	while (i < k)
	{
		temp = array[i];
		token_cmd = "";
		printf("temp: %s\n", temp);
		token_cmd = _strcat(temp, "/");
		token_cmd = _strcat(token_cmd, *cmd);

		printf("cmd: %s\n", *cmd);
		printf("token_cmd: %s\n", token_cmd);

		j = stat(token_cmd, buff);
		printf("j: %d\n", j);

		if (j == -1)
		{
			i++;
			continue;
		}
		else
		{
			*cmd = token_cmd;
                        printf("%s\n", *cmd);
                        return;

		}
	}
}
int main()
{
	char *cmd = "ls";

	path_finder(&cmd);
	return (0);
}
