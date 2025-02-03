/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_signal_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

void	mts_signal_handler(int signum, siginfo_t *info, void *context)
{
	int	bit;

	(void) context;
	if (signum != SIGUSR1 && signum != SIGUSR2)
		return ;
	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	mts_process_bit(bit, info);
}
