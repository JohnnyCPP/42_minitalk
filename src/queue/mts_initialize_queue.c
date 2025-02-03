/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_initialize_queue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

void	mts_initialize_queue(void)
{
	g_queue.head = NULL;
	g_queue.tail = NULL;
}
