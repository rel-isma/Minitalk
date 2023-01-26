/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:11:22 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/26 05:21:50 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static  void reset_unicode(unsigned char *tab, int *index, int *nbyte, int *flag) 
{
     if (*flag == 1)
    {
        *index = 0;
        *nbyte = 0;
        ft_memset(tab, 0, 4);
        *flag = 0;
    }
}

static  void reset_pid(int *pid, int *bit, unsigned char *c, siginfo_t *info, int *flag) 
{
    if (*pid != info->si_pid) 
    {
        *c = 0;
        *bit = 0;
        *pid = info->si_pid;
        *flag = 1;
    }
}

static  void unicode_h(unsigned char c, int *flag) 
{
    static unsigned char tab[4] = {0};
    static int index = 0;
    static int nbyte = 0;
    
    reset_unicode(tab, &index, &nbyte, flag);
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

static  void signal_h(int sig, siginfo_t *info, void *ptr)
{
    (void)ptr;
    static int	bit = 0;
    static unsigned char	c = 0;
	static int	pid;
    static  int flag = 0;
    
    reset_pid(&pid, &bit, &c, info, &flag);
    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else if (sig == SIGUSR2)
        c = (c << 1) | 0;
    bit++;
    if (bit == 8)
    {
        if (c <= 127)
            write(1, &c, 1);
        else
            unicode_h(c, &flag);
        bit = 0;
        c = 0;
    }
}

int main()
{
    pid_t pid = getpid();
    ft_printf("Server PID: %d\n", pid);
    
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_h;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
	{
        pause();
	}
    return 0;
}

