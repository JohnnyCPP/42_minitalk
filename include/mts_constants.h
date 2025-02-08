/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTS_CONSTANTS_H
# define MTS_CONSTANTS_H

/**
 * @brief Application errors.
 */
# define ERROR_EMPTYSET "An error occurred initializing an empty signal set"
# define ERROR_ADDSET "An error occurred adding a signal set"
# define ERROR_SIGACTION "An error occurred associating an action to a signal"
# define ERROR_SIGMEM "An error occurred allocating memory to a signal"

/**
 * @brief Used in an infinite loop to keep the server waiting for signals.
 */
# define TRUE 1

/**
 * @brief Amount of bits in a byte.
 */
# define BITS_IN_BYTE 8

/**
 * @brief Order in which bits of a char are decoded from the client.
 *
 * Set to 0 for least-significant-bit first.
 * Set to 1 for most-significant-bit first.
 */
# define LSB_FIRST 0
# define MSB_FIRST 1
# define TRANSMISSION_ENDIANESS MSB_FIRST

#endif
