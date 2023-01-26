/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:07:29 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/26 05:13:03 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);

#endif