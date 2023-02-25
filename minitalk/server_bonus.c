/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:48:01 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/18 18:00:22 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

/* c and bit starts at 0 both
if SIGUSR2 then 1 (0000.0001) | c (0000.0000)
and c turn to 0000.0001 = (1), and stores it (static int)
*/

/*in the 2nd turn if signal = SIGUSR2 (1)
1 << 1 0000.0001 << 1 = 0000.0010 (2) | c (1) (0000.0001)
= 0000.0011 (3)*/

/*struct siginfo_t
	si_pid - process id*/

/*kill function - sends a SIGNAL to a process pid*/

/*the handler funct must hv 3 args if SA_SIGINFO is defined (main)
void hander(int sig, siginfo_t *info, void *ucontext)
	sig - the signal that invoked the handler function
	*info - a pointer to a struct siginfo_t that has info about the sign
		si_pid (process ID)*/

void	handler_sig(int signal, siginfo_t *info, void *context)
{
	static unsigned int	c;
	static int			bit;

	(void)context;
	c = (signal == SIGUSR2) << bit | c;
	bit++;
	if (bit == 8)
	{
		if (c)
			ft_printf("%c", c);
		else
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

/*struct sigaction  (include signal.h)
	sa_sigaction - function that handles a signal and points to other fucnt
	sa_flags - using SA_SIGINFO to ignore sa_handler and use sa_sigaction*/

/* getpid() function returns process id;*/

/*pause() function keeps process going till ex: ENDING sig (Ctrl + C)*/

/*sigaction(int sign, struct sigaction *act, 0)
- handle a signal to a function (pointed by act.sig_action)
	sign - signal recieved
	act - new act for sig*/

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID is %d\n", pid);
	act.sa_sigaction = handler_sig;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
}
