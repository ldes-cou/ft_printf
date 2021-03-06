/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:21:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/06 11:21:52 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

static int	size_nbr(long unsigned n, int base)
{
	int				size;
	long unsigned	nbis;

	size = 0;
	nbis = n;
	if (nbis < 0)
	{
		size++;
		nbis = -n;
	}
	if (nbis == 0)
		return (1);
	while (nbis > 0)
	{
		size++;
		nbis = nbis / base;
	}
	return (size);
}

static char	*def_base(int base)
{
	char	*def;

	def = (char *)malloc(sizeof(char) * base + 1);
	if (!def)
		return (NULL);
	if (base == 16)
		def = "0123456789abcdef";
	else if (base == 10)
		def = "0123456789";
	return (def);
}

char		*ft_itoa_base(long unsigned n, int base)
{
	char			*nbr;
	unsigned long	nbis;
	char			*tab;
	int				size;

	nbis = n;
	nbr = NULL;
	size = size_nbr(nbis, base);
	tab = def_base(base);
	if (n == 0)
		return (ft_strdup("0"));
	nbr = (char *)malloc(size * sizeof(char) + 1);
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	if (n < 0)
		n = -n;
	while (nbis > 0)
	{
		nbr[size - 1] = tab[nbis % base];
		nbis = nbis / base;
		size--;
	}
	return (nbr);
}

