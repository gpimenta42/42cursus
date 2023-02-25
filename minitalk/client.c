/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:00:05 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/18 18:02:06 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

int	ft_error_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]) == NULL)
			return (1);
		i++;
	}
	return (0);
}

/* search last bit of the associated char and compare it with 1 (0000.0001)
if both are 1 (&) then it send SIGUSR2 sign*/

/*kill function - sends a SIGNAL to a process pid*/

/*usleep function - pauses x defind microscnds
(to server process it bf another sig)*/

void	char_send(int pid, unsigned int c)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(200);
	}
}

/*exit 1 - failure*/

int	main(int ac, char **av)
{
	int					pid;
	int					i;

	i = 0;
	if (ac != 3 || ft_error_check(av[1]) == 1)
	{
		ft_printf("ERROR: Invalid input.\n");
		ft_printf("Please try: ./client <PID> <string>\n");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		char_send(pid, av[2][i]);
		i++;
	}
}
