/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_validate_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

void	mtc_validate_arguments(const int argc, const char **argv)
{
	const char	*pid;
	int			i;

	if (argc != ARG_AMOUNT)
	{
		ft_putendl_fd(ERROR_ARGC, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pid = argv[ARG_PID];
	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putendl_fd(ERROR_PID_FORMAT, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i ++;
	}
	if (ft_ioverflow(pid))
	{
		ft_putendl_fd(ERROR_PID_OFLOWS, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
