/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:11:30 by rel-isma          #+#    #+#             */
/*   Updated: 2023/01/26 04:04:15 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static void ft_send_m(int pid, char *str)
{
    int i = 0;
    int bit;
    while (str[i])
    {
        bit = 7;
        while (bit >= 0)
        {
            if ((str[i] & (1 << bit)))
            {
                if (kill(pid, SIGUSR1) == -1) 
                {
                    write(1 ,"Error: ", 7);
                    exit(1);
                }
            }
            else {
                if (kill(pid, SIGUSR2) == -1) 
                {
                    write(1 ,"Error: ", 7);
                    exit(1);
                }
            }
            bit--;
            usleep(800);
        }
        i++;
    }
}

int main(int argc, char* argv[]) 
{
    int pid;
    if (argc != 3)
    {
        write(1 ,"error: not enough arguments\n", 28);
        return 1;
    }

    pid = ft_atoi(argv[1]);
    if(kill(pid,0) == -1) 
    {
       write(1 ,"Error: ", 7);
        return 1;
    }
    ft_send_m(pid, argv[2]);

    return 0;
}
