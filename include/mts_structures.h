/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTS_STRUCTURES_H
# define MTS_STRUCTURES_H

/**
 * @brief Represents a signal to be dequeued.
 *
 * This struct is used to store received signals in order to 
 * process them sequentially, without signal loss.
 */
typedef struct s_signal
{
	int				bit;
	pid_t			pid;
	struct s_signal	*next;
}				t_signal;

/**
 * @brief Represents a queue of signals to be processed.
 */
typedef struct s_queue
{
	t_signal	*head;
	t_signal	*tail;
}				t_queue;

#endif
