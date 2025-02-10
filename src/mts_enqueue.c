/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_enqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

void	mts_enqueue(int bit, pid_t pid)
{
	t_signal	*new_signal;

	new_signal = (t_signal *) ft_calloc(1, sizeof(t_signal));
	if (!new_signal)
	{
		perror(ERROR_SIGMEM);
		return ;
	}
	new_signal->bit = bit;
	new_signal->pid = pid;
	new_signal->next = NULL;
	if (g_queue.tail != NULL)
		g_queue.tail->next = new_signal;
	else
		g_queue.head = new_signal;
	g_queue.tail = new_signal;
}
