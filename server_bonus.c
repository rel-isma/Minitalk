/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:11:22 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/28 05:41:16 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static	void	reset_unicode(unsigned char *tab, int *index, int *nbyte)
{
	*index = 0;
	*nbyte = 0;
	ft_memset(tab, 0, 4);
}

static	void	reset_pid(t_data	*data)
{
	data->c = 0;
	data->bit = 0;
	data->flag = 1;
}

static	void	unicode_h(unsigned char c, int *flag)
{
	static unsigned char	tab[4] = {0};
	static int				index = 0;
	static int				nbyte = 0;

	if (*flag == 1)
	{
		reset_unicode(tab, &index, &nbyte);
		*flag = 0;
	}
	if (c >= 192 && c <= 223)
		nbyte = 2;
	else if (c >= 224 && c <= 239)
		nbyte = 3;
	else if (c >= 240)
		nbyte = 4;
	tab[index++] = c;
	if (index == nbyte)
	{
		write(1, tab, nbyte);
		nbyte = 0;
		index = 0;
		ft_memset(tab, 0, 4);
	}
}

static	void	signal_h(int sig, siginfo_t *info, void *ptr)
{
	static t_data	data;

	(void) ptr;
	if (data.pid != info->si_pid)
	{
		reset_pid(&data);
		data.pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		data.c = (data.c << 1) | 1;
	else if (sig == SIGUSR2)
		data.c = (data.c << 1) | 0;
	data.bit++;
	if (data.bit == 8)
	{
		if (data.c == 0)
			kill(info->si_pid, SIGUSR2);
		if (data.c <= 127)
			write(1, &data.c, 1);
		else
			unicode_h(data.c, &data.flag);
		data.bit = 0;
		data.c = 0;
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
