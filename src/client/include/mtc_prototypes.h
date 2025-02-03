/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTC_PROTOTYPES_H
# define MTC_PROTOTYPES_H

/**
 * @brief Checks that the amount of arguments is right.
 *
 * @param argc The amount of arguments.
 * @param argv The arguments.
 *
 * If the mount is not as expected, or the PID is not a number, 
 * prints an error message and returns EXIT_FAILURE.
 *
 * It also verifies that the PID doesn't overflows an integer.
 */
void	mtc_validate_arguments(const int argc, const char **argv);

/**
 * @brief Sends a single bit to a given process.
 *
 * @param pid The process ID of the destination process.
 * @param bit The bit to be sent.
 *
 * This function sends a "SIGUSR1" or a "SIGUSR2" signal, depending if 
 * "bit" is 0 or 1, respectively.
 *
 * It also handles the case when an error occurs sending the signal: 
 * displays an error message and stops execution.
 */
void	mtc_send_bit(pid_t pid, const int bit);

/**
 * @brief Iterates through bits of "c", sending each one to a given process.
 *
 * @param pid The process ID of the destination process.
 * @param c The character to be sent.
 *
 * This function changes its behavior depending on "TRANSMISSION_ENDIANESS", 
 * which determines the order in which the individual bits will be sent.
 */
void	mtc_send_char(pid_t pid, const char c);

/**
 * @brief Sends a message to a given process.
 *
 * @param pid The process ID of the destination process.
 * @param message The message to be sent.
 *
 * This function iterates through characters of "message", sending 
 * each one to the given process with "mtc_send_char()".
 *
 * At the end, sends the null-terminator character.
 */
void	mtc_send_message(pid_t pid, const char *message);

#endif
