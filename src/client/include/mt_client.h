/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MT_CLIENT_H
# define MT_CLIENT_H

# include "libft.h"
//	includes "perror()"
# include <stdio.h>
//	includes "pid_t"
# include <sys/types.h>
//	includes "kill()", "SIGUSR1", "SIGUSR2", "sig_atomic_t"
# include <signal.h>
# include "mtc_constants.h"
# include "mtc_structures.h"
# include "mtc_prototypes.h"
# include "mtc_constants_bonus.h"
# include "mtc_prototypes_bonus.h"

extern volatile sig_atomic_t	g_acknowledgement;

#endif
