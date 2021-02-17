/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:42:41 by ldes-cou          #+#    #+#             */
/*   Updated: 2020/12/03 10:29:48 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_word(const char *s, int start, char c)
{
	int i;

	i = 0;
	while (s[start] != c && s[start] != '\0')
	{
		i++;
		start++;
	}
	return (i);
}

static int	ft_num_word(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char		**ft_split(const char *s, char c)
{
	int		start;
	char	**array;
	int		i;
	int		nb_word;
	int		len;

	i = 0;
	start = 0;
	nb_word = ft_num_word(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	while (i < nb_word)
	{
		while (s[start] == c)
			start++;
		len = ft_len_word(s, start, c);
		array[i++] = ft_substr(s, start, len);
		start += len + 1;
	}
	array[i] = NULL;
	return (array);
}
