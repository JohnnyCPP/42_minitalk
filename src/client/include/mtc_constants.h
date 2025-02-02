/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTC_CONSTANTS_H
# define MTC_CONSTANTS_H

/**
 * @brief Application errors.
 */
# define ERROR_ARGC "Usage: ./client <server_PID> <message>"
# define ERROR_PID_FORMAT "The PID must be a number."
# define ERROR_PID_OFLOWS "The PID value exceeds integer limits."
# define ERROR_TRANSMISSION "Error sending a signal to the server."

/**
 * @brief Amount of arguments expected on the client.
 */
# define ARG_AMOUNT 3

/**
 * @brief Position of PID in argv array.
 */
# define ARG_PID 1

/**
 * @brief Position of message in argv array.
 */
# define ARG_MESSAGE 2

/**
 * @brief Amount of bits in a byte.
 */
# define BITS_IN_BYTE 8

/**
 * @brief Order in which bits of a char are sent to the server.
 *
 * Set to 0 for least-significant-bit first.
 * Set to 1 for most-significant-bit first.
 */
# define LSB_FIRST 0
# define MSB_FIRST 1
# define TRANSMISSION_ENDIANESS LSB_FIRST

#endif
