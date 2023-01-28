/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:14:50 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/26 06:47:10 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static	void	reset_pid(int *pid, int *bit, unsigned char *c, siginfo_t *info)
{
	if (*pid != info->si_pid)
	{
		*c = 0;
		*bit = 0;
		*pid = info->si_pid;
	}
}

static	void	signal_h(int sig, siginfo_t *info, void *ptr)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	static int				pid;

	(void) ptr;
	reset_pid(&pid, &bit, &c, info);
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_h;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
