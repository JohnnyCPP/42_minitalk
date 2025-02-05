/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MT_SERVER_H
# define MT_SERVER_H

# include "libft.h"
// includes "perror()"
# include <stdio.h>
/**	
 * includes signals, "struct sigaction", "sigaction()", 
 * "sigemptyset()", "kill()"
 */
# include <signal.h>
# include "mts_constants.h"
# include "mts_structures.h"
# include "mts_prototypes.h"

extern t_queue	g_queue;

#endif
