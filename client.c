/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:29:18 by makacem           #+#    #+#             */
/*   Updated: 2022/05/30 11:43:27 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*string_to_send;
	int		b;

	if (argc != 3 || ft_atoi(argv[1]) <= 0)
		return (0);
	server_pid = ft_atoi(argv[1]);
	string_to_send = argv[2];
	while (*string_to_send)
	{
		b = 1;
		while (b <= 8)
		{
			if (*string_to_send & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
				*string_to_send = *string_to_send >> 1;
				b++;
			usleep(500);
		}
		string_to_send++;
	}
	return (0);
}
