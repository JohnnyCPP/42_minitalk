/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_process_bit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

void	mts_process_bit(const int bit, siginfo_t *info)
{
	static pid_t	client_pid = 0;
	static int		bit_count = 0;
	static char		buffer;

	if (client_pid != info->si_pid)
	{
		buffer = 0;
		bit_count = 0;
		client_pid = info->si_pid;
	}
	buffer <<= 1;
	buffer |= bit;
	bit_count ++;
	if (bit_count == BITS_IN_BYTE)
	{
		if (buffer == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", buffer);
		buffer = 0;
		bit_count = 0;
	}
}
