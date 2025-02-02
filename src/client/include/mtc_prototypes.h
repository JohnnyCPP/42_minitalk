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

// TODO: document this function
void	mtc_send_bit(pid_t pid, const int bit);

// TODO: document this function
void	mtc_send_char(pid_t pid, const char c);

// TODO: document this function
void	mtc_send_message(pid_t pid, const char *message);

#endif
