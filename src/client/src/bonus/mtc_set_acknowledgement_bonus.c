/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_set_acknowledgement_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

volatile sig_atomic_t	g_acknowledgement = 0;

static	void	mtc_acknowledgement_handler(int signum)
{
	(void) signum;
	g_acknowledgement = 1;
}

void	mtc_set_acknowledgement(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_handler = mtc_acknowledgement_handler;
	s_sigaction.sa_flags = SA_NOFLAGS;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, NULL);
}
