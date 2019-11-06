// check the number of connected pieces in tetrimino
// return 1 if thr tetrimino has 6 or 8 connections, otherwise return 0
int		connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 16)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 16 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 4) < 16 && str[i + 4] == '#')
				block++;
			if ((i - 4) >= 0 && str[i - 4] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

//check the figure, if it is valid returns 1, otherwise ret 0

int		checker(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;

	while (str[i])
		i++;
	if (i != 16)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		if (str[i] == '#' && ++count > 4)
			return (0);
		i++;
	}
	if (!connection(str))
		return (0);
	return (1);
}
