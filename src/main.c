/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

t_queue	g_queue;

int	main(void)
{
	mts_display_pid();
	mts_initialize_queue();
	mts_set_handlers();
	while (TRUE)
	{
		if (g_queue.head)
			mts_dequeue();
		else
			pause();
	}
	return (EXIT_SUCCESS);
}
