/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_set_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

static	void	mts_associate_actions(struct sigaction *sigac)
{
	int	status_code;

	status_code = sigaction(SIGUSR1, sigac, NULL);
	if (status_code == -1)
	{
		perror(ERROR_SIGACTION);
		exit(EXIT_FAILURE);
	}
	status_code = sigaction(SIGUSR2, sigac, NULL);
	if (status_code == -1)
	{
		perror(ERROR_SIGACTION);
		exit(EXIT_FAILURE);
	}
}

static	void	mts_initialize_signal_set(struct sigaction *s_sigaction)
{
	int	status_code;

	status_code = sigemptyset(&s_sigaction->sa_mask);
	if (status_code == -1)
	{
		perror(ERROR_EMPTYSET);
		exit(EXIT_FAILURE);
	}
	status_code = sigaddset(&s_sigaction->sa_mask, SIGUSR1);
	if (status_code == -1)
	{
		perror(ERROR_ADDSET);
		exit(EXIT_FAILURE);
	}
	status_code = sigaddset(&s_sigaction->sa_mask, SIGUSR2);
	if (status_code == -1)
	{
		perror(ERROR_ADDSET);
		exit(EXIT_FAILURE);
	}
}

void	mts_set_handlers(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = mts_signal_handler;
	s_sigaction.sa_flags = SA_SIGINFO | SA_RESTART;
	mts_initialize_signal_set(&s_sigaction);
	mts_associate_actions(&s_sigaction);
}
