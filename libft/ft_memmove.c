/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:24:21 by ldes-cou          #+#    #+#             */
/*   Updated: 2020/12/03 10:13:28 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	if (src <= dst)
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
