/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_dequeue_bonus.c                                :+:      :+:    :+:   */
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
	static unsigned char	buffer[UTF_BUFFER_SIZE];
	static char				current_byte = '\0';
	t_signal				*target;

	if (!g_queue.head)
		return ;
	target = g_queue.head;
	g_queue.head = target->next;
	if (!g_queue.head)
		g_queue.tail = NULL;
	mts_proc_utf_bit(target->bit, target->pid, buffer, &current_byte);
	free(target);
}
