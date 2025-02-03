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

/**
 * @brief Processes a bit that has been received from the client.
 *
 * @param bit The bit received.
 * @param info Provides additional information about a received signal.
 *
 * This function stores a single bit in a static buffer. When the buffer 
 * contains enough bits, prints a character.
 * If the character is a null-terminator, prints a newline character.
 *
 * "info" is used to check the sender PID. If the PID changes during 
 * transmissions, the processing resets, allowing further communication.
 */
void	mts_process_bit(const int bit, siginfo_t *info);

/**
 * @brief Decodes a bit when a signal is received.
 *
 * @param signum The received signal number.
 * @param info Additional information about the received signal.
 * @param context Can be cast to (* ucontext_t) to refer to the receiving 
 *                thread's context that was interrupted when the signal 
 *                was delivered. Provides access to the thread's 
 *                execution context (e.g. CPU registers)
 *
 * This function accepts only "SIGUSR1" or "SIGUSR2" signals.
 * If the signal is not one of the allowed signals, immediately returns.
 * A "SIGUSR1" signal is decoded as a 0.
 * A "SIGUSR2" signal is decoded as a 1.
 * For each signal received, "mts_process_bit()" 
 * is called to store each bit in a buffer.
 */
void	mts_signal_handler(int signum, siginfo_t *info, void *context);

/**
 * @brief Populates a struct sigaction, configuring the signal handler.
 *
 * This function maps "SIGUSR1" and "SIGUSR2" signals to the 
 * "mts_signal_handler" function to run when these are received.
 */
void	mts_set_handlers(void);

#endif
