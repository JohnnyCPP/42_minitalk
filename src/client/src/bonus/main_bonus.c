/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

int	main(const int argc, const char **argv)
{
	pid_t		pid;
	const char	*message;

	mtc_validate_arguments(argc, argv);
	pid = ft_atoi(argv[ARG_PID]);
	message = argv[ARG_MESSAGE];
	mtc_set_acknowledgement();
	mtc_send_message(pid, message);
	return (EXIT_SUCCESS);
}
