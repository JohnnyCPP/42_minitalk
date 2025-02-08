/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_dequeue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

void	mts_dequeue(void)
{
	t_signal	*target;

	if (!g_queue.head)
		return ;
	target = g_queue.head;
	g_queue.head = target->next;
	if (!g_queue.head)
		g_queue.tail = NULL;
	mts_process_bit(target->bit, target->pid);
	free(target);
}
