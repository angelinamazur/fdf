int gnl(char **line)
{
	int rd = 0;
	int i = 0;
	char *buffer = malloc(10000);
	* line = buffer;
	while ((rd = read(0, &buffer[i], 1))
}