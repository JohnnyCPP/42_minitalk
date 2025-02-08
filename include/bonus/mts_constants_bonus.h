/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_constants_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTS_CONSTANTS_BONUS_H
# define MTS_CONSTANTS_BONUS_H

/**
 * @brief Maximum amount of bytes of a UTF-8 character.
 */
# define UTF_BUFFER_SIZE 4

/**
 * @brief Bitmasks to check UTF-8 sequence length.
 *
 * - 0x80 -> 1000 0000
 * - 0xE0 -> 1110 0000
 * - 0xF0 -> 1111 0000
 * - 0xF8 -> 1111 1000
 */
# define SEQUENCE_LENGTH_MASK_1 0x80
# define SEQUENCE_LENGTH_MASK_2 0xE0
# define SEQUENCE_LENGTH_MASK_3 0xF0
# define SEQUENCE_LENGTH_MASK_4 0xF8

/**
 * @brief Bitmasks that determine the amount of bytes of a UTF-8 sequence.
 *
 * - 0x00 -> 0000 0000
 * - 0xC0 -> 1100 0000
 * - 0xE0 -> 1110 0000
 * - 0xF0 -> 1111 0000
 */
# define BYTE_COUNT_MASK_1 0x00
# define BYTE_COUNT_MASK_2 0xC0
# define BYTE_COUNT_MASK_3 0xE0
# define BYTE_COUNT_MASK_4 0xF0

/**
 * @brief Possible lengths of a variable-length UTF-8 sequence.
 */
# define UTF_BYTE_LENGTH_1 1
# define UTF_BYTE_LENGTH_2 2
# define UTF_BYTE_LENGTH_3 3
# define UTF_BYTE_LENGTH_4 4

/**
 * @brief Return value of invalid UTF-8 sequence.
 */
# define UTF_INVALID_SEQUENCE -1

/**
 * @brief Amount of bits per subsequent byte of a unicode character.
 */
# define BITS_SUBS_BYTE 6

/**
 * @brief Bitmasks to select a given amount of bits in a UTF-8 chunk.
 */
# define MASK_CHUNK_3 0x07
# define MASK_CHUNK_4 0x0F
# define MASK_CHUNK_5 0x1F
# define MASK_CHUNK_6 0x3F

#endif
