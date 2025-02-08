/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_constants_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTC_CONSTANTS_BONUS_H
# define MTC_CONSTANTS_BONUS_H

/**
 * @brief Value for flags settings of the signal handler. No flags are set.
 */
# define SA_NOFLAGS 0

/**
 * @brief Ranges for variable-width unicode encodings.
 *
 * Each value represents the maximum value, inclusive, for each unicode 
 * character of 1, 2, 3, and 4 bytes.
 *
 * These values are used to determine the amount of bytes needed 
 * to encode a given unicode character.
 */
# define CODE_POINT_1 0x7F
# define CODE_POINT_2 0x7FF
# define CODE_POINT_3 0xFFFF
# define CODE_POINT_4 0x10FFFF

/**
 * @brief Amount of bits per subsequent byte of a unicode character.
 */
# define BITS_SUBS_BYTE 6

/**
 * @brief Bitmasks that set bits of the first byte of a unicode character.
 *
 * If a unicode character occupies more than a single byte, these bitmasks 
 * are used to add 1s on the first byte to determine the character size:
 *
 * -   0x00 -> 0000 0000
 * - 2B: C0 -> 1100 0000
 * - 3B: E0 -> 1110 0000
 * - 4B: F0 -> 1111 0000
 *
 * The left 1s self-synchronize the encoding scheme by determining the 
 * amount of bytes needed for the unicode character.
 */
# define BYTE_COUNT_MASK_1 0x00
# define BYTE_COUNT_MASK_2 0xC0
# define BYTE_COUNT_MASK_3 0xE0
# define BYTE_COUNT_MASK_4 0xF0

/**
 * @brief Bits added to identify a continuation byte.
 *
 * Each byte after the first one sets a specific prefix at the beginning:
 *
 * - 0x80 -> '10'00 0000
 *
 * UTF-8 standard identifies a subsequent byte if starts with the "10" prefix.
 * This bitmask is used to set this prefix on subsequent bytes.
 */
# define SUBSEQUENT_BYTE_MASK 0x80

/**
 * @brief Bits extracted to a subsequent byte of a unicode character.
 *
 * 0x3F -> 0011 1111
 *
 * This bitmask is used with bitwise AND to extract 6 bits from a 
 * unicode character storing them into a chunk of bits.
 */
# define CHUNK_BITMASK 0x3F

/**
 * @brief Return value of invalid unicode to UTF-8 conversion.
 */
# define UTF_INVALID_INPUT 0

/**
 * @brief Possible lengths of a variable-width unicode character.
 */
# define UNICODE_BYTE_LENGTH_1 1
# define UNICODE_BYTE_LENGTH_2 2
# define UNICODE_BYTE_LENGTH_3 3
# define UNICODE_BYTE_LENGTH_4 4

/**
 * @brief Indexes of the different bytes of a unicode character.
 *
 * These values are used to get a specific byte from a unicode character.
 */
# define UNICODE_BYTE_1 0
# define UNICODE_BYTE_2 1
# define UNICODE_BYTE_3 2
# define UNICODE_BYTE_4 3

/**
 * @brief Amount of bytes used to store a variable-width UTF-8 character.
 *
 * Includes an extra byte for a null-terminating character.
 */
# define UTF_BUFFER_LENGTH 5

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
 * @brief Bitmasks to select a given amount of bits in a UTF-8 chunk.
 */
# define MASK_CHUNK_3 0x07
# define MASK_CHUNK_4 0x0F
# define MASK_CHUNK_5 0x1F
# define MASK_CHUNK_6 0x3F

#endif
