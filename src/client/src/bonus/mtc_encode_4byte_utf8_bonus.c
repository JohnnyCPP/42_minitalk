/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_encode_4byte_utf8_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

int	mtc_encode_4byte_utf8(char *buffer, unsigned int unicode)
{
	unsigned int	first_chunk;
	unsigned int	second_chunk;
	unsigned int	third_chunk;
	unsigned int	fourth_chunk;

	first_chunk = unicode >> (BITS_SUBS_BYTE * 3);
	second_chunk = (unicode >> (BITS_SUBS_BYTE * 2)) & CHUNK_BITMASK;
	third_chunk = (unicode >> BITS_SUBS_BYTE) & CHUNK_BITMASK;
	fourth_chunk = unicode & CHUNK_BITMASK;
	buffer[UNICODE_BYTE_1] = (char)(BYTE_COUNT_MASK_4 | first_chunk);
	buffer[UNICODE_BYTE_2] = (char)(SUBSEQUENT_BYTE_MASK | second_chunk);
	buffer[UNICODE_BYTE_3] = (char)(SUBSEQUENT_BYTE_MASK | third_chunk);
	buffer[UNICODE_BYTE_4] = (char)(SUBSEQUENT_BYTE_MASK | fourth_chunk);
	return (UNICODE_BYTE_LENGTH_4);
}
