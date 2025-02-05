/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_send_bit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

void	mtc_send_bit(pid_t pid, const int bit)
{
	int	transmission_status;

	transmission_status = 0;
	if (bit == 0)
		transmission_status = kill(pid, SIGUSR1);
	else if (bit == 1)
		transmission_status = kill(pid, SIGUSR2);
	if (transmission_status == -1)
	{
		perror(ERROR_TRANSMISSION);
		exit(EXIT_FAILURE);
	}
	while (!g_acknowledgement)
		pause();
	g_acknowledgement = 0;
}
