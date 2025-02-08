/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_decode_utf8_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

static void	mtc_decode_2byte(const char *utf8, unsigned int *unicode, int *bc)
{
	unsigned int	first_chunk;
	unsigned int	second_chunk;
	unsigned char	first_byte;

	first_byte = (unsigned char) utf8[0];
	first_chunk = (first_byte & MASK_CHUNK_5) << BITS_SUBS_BYTE;
	second_chunk = (unsigned char) utf8[1] & MASK_CHUNK_6;
	*unicode = first_chunk | second_chunk;
	*bc = 2;
}

static void	mtc_decode_3byte(const char *utf8, unsigned int *unicode, int *bc)
{
	unsigned int	first_chunk;
	unsigned int	second_chunk;
	unsigned int	third_chunk;
	unsigned char	first_byte;

	first_byte = (unsigned char) utf8[0];
	first_chunk = (first_byte & MASK_CHUNK_4) << (BITS_SUBS_BYTE * 2);
	second_chunk = ((unsigned char) utf8[1] & MASK_CHUNK_6) << BITS_SUBS_BYTE;
	third_chunk = (unsigned char) utf8[2] & MASK_CHUNK_6;
	*unicode = first_chunk | second_chunk | third_chunk;
	*bc = 3;
}

static void	mtc_decode_4byte(const char *utf8, unsigned int *unicode, int *bc)
{
	unsigned int	first_chunk;
	unsigned int	second_chunk;
	unsigned int	third_chunk;
	unsigned int	fourth_chunk;
	unsigned char	first_byte;

	first_byte = (unsigned char) utf8[0];
	first_chunk = (first_byte & MASK_CHUNK_3) << (BITS_SUBS_BYTE * 3);
	second_chunk = (unsigned char) utf8[1] & MASK_CHUNK_6;
	second_chunk <<= BITS_SUBS_BYTE * 2;
	third_chunk = ((unsigned char) utf8[2] & MASK_CHUNK_6) << BITS_SUBS_BYTE;
	fourth_chunk = (unsigned char) utf8[3] & MASK_CHUNK_6;
	*unicode = first_chunk | second_chunk | third_chunk | fourth_chunk;
	*bc = 4;
}

unsigned int	mtc_decode_utf8(const char *utf8, int *bytes_consumed)
{
	unsigned int	unicode;
	unsigned char	first_byte;

	unicode = 0;
	first_byte = (unsigned char) utf8[0];
	if ((first_byte & SEQUENCE_LENGTH_MASK_1) == BYTE_COUNT_MASK_1)
	{
		unicode = first_byte;
		*bytes_consumed = 1;
	}
	else if ((first_byte & SEQUENCE_LENGTH_MASK_2) == BYTE_COUNT_MASK_2)
		mtc_decode_2byte(utf8, &unicode, bytes_consumed);
	else if ((first_byte & SEQUENCE_LENGTH_MASK_3) == BYTE_COUNT_MASK_3)
		mtc_decode_3byte(utf8, &unicode, bytes_consumed);
	else if ((first_byte & SEQUENCE_LENGTH_MASK_4) == BYTE_COUNT_MASK_4)
		mtc_decode_4byte(utf8, &unicode, bytes_consumed);
	else
		*bytes_consumed = 0;
	return (unicode);
}
