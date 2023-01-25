/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:17:25 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/25 03:09:44 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*y;

	y = b;
	while (len > 0)
	{
		*y = (unsigned char)c;
		y++;
		len--;
	}
	return (b);
}
