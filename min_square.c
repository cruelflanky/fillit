int		min_square(t_list *begin)
{
	int		i;
	int		sqrt;

	i = 1;
	sqrt = 1;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	i *= 4;
	while (sqrt * sqrt < i)
		++sqrt;
	i = sqrt * sqrt;
	return (sqrt);
}
