/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTS_PROTOTYPES_H
# define MTS_PROTOTYPES_H

/**
 * @brief Prints the PID of the running process through stdout.
 */
void	mts_display_pid(void);

//	TODO: document this function
void	mts_process_bit(const int bit, siginfo_t *info);

//	TODO: document this function
void	mts_signal_handler(int signum, siginfo_t *info, void *context);

/**
 * @brief Populates a struct sigaction, configuring the signal handler.
 *
 * This function maps "SIGUSR1" and "SIGUSR2" signals to the 
 * "mts_signal_handler" function to run when these are received.
 */
void	mts_set_handlers(void);

#endif
