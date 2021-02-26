#include "libft.h"
int		ft_intlen(int n)
{
	int		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
