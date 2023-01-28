/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:11:30 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/28 10:56:56 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	confirm_m(int signal)
{
	if (signal == SIGUSR2)
	{
		write(1, "message recieved\n", 17);
	}
	exit(0);
}

static	void	ft_sigusr1(int *pid)
{
	if (kill(*pid, SIGUSR1) == -1)
	{
		write(1, "Error: ", 7);
		exit(1);
	}
}

static	void	ft_sigusr2(int *pid)
{
	if (kill(*pid, SIGUSR2) == -1)
	{
		write(1, "Error: ", 7);
		exit(1);
	}
}

static	void	ft_send_m(int pid, char *str)
{
	int	i;
	int	bit;
	int	len;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	while (i <= len)
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((str[i] & (1 << bit)))
				ft_sigusr1(&pid);
			else
				ft_sigusr2(&pid);
			bit--;
			usleep(800);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "error: not enough arguments\n", 28);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		write(1, "Error: ", 7);
		return (1);
	}
	signal(SIGUSR2, confirm_m);
	ft_send_m(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
