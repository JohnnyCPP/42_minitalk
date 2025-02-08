/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTC_PROTOTYPES_BONUS_H
# define MTC_PROTOTYPES_BONUS_H

/**
 * @brief Sets up a handler to check for server acknowledgement.
 *
 * The acknowledgement handler assigns 1 to "g_acknowledgement".
 */
void			mtc_set_acknowledgement(void);

/**
 * @brief Encodes a unicode character to its UTF-8 version of 4 bytes.
 *
 * @param buffer A pointer to a string to store the UTF-8 encoded character.
 * @param unicode The code point of the unicode character.
 *
 * @return The amount of bytes occupied by the UTF-8 encoded character.
 */
int				mtc_encode_4byte_utf8(char *buffer, unsigned int unicode);

/**
 * @brief Encodes a unicode character to its UTF-8 version of 3 bytes.
 *
 * @param buffer A pointer to a string to store the UTF-8 encoded character.
 * @param unicode The code point of the unicode character.
 *
 * @return The amount of bytes occupied by the UTF-8 encoded character.
 */
int				mtc_encode_3byte_utf8(char *buffer, unsigned int unicode);

/**
 * @brief Encodes a unicode character to its UTF-8 version of 2 bytes.
 *
 * @param buffer A pointer to a string to store the UTF-8 encoded character.
 * @param unicode The code point of the unicode character.
 *
 * @return The amount of bytes occupied by the UTF-8 encoded character.
 */
int				mtc_encode_2byte_utf8(char *buffer, unsigned int unicode);

/**
 * @brief Encodes a unicode character to its UTF-8 version.
 *
 * @param buffer A pointer to a string to store the UTF-8 encoded character.
 * @param unicode The code point of the unicode character.
 *
 * @return The amount of bytes occupied by the UTF-8 encoded character.
 *
 * This function calls a subsequent function depending on the 
 * code point range in which the unicode character falls upon.
 *
 *   U+0000  - U+007F	-> mtc_encode_1byte_utf8()
 *   U+0080  - U+07FF	-> mtc_encode_2byte_utf8()
 *   U+0800  - U+FFFF	-> mtc_encode_3byte_utf8()
 *   U+10000 - U+10FFFF	-> mtc_encode_4byte_utf8()
 */
int				mtc_encode_utf8(char *buffer, unsigned int unicode);

/**
 * @brief Decodes UTF-8 bytes from an encoded string.
 *
 * @param utf8 The encoded string.
 * @param bytes_consumed Will be updated to hold the UTF-8 bytes processed.
 *
 * @return The decimal value of the unicode code point. If fails, returns 0.
 *
 * This function will decode, from the provided string, the next sequence of 
 * UTF-8 bytes and count the given amount. If the sequence is not valid, 
 * just returns 0.
 */
unsigned int	mtc_decode_utf8(const char *utf8, int *bytes_consumed);

#endif
