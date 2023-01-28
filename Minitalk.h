/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:07:29 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/28 10:37:37 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int				bit;
	unsigned char	c;
	int				flag;
	int				pid;
}	t_data;

void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);

#endif
