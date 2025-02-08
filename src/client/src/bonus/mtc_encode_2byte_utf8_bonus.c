/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_encode_2byte_utf8_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

int	mtc_encode_2byte_utf8(char *buffer, unsigned int unicode)
{
	unsigned int	first_chunk;
	unsigned int	second_chunk;

	first_chunk = unicode >> BITS_SUBS_BYTE;
	second_chunk = unicode & CHUNK_BITMASK;
	buffer[UNICODE_BYTE_1] = (char)(BYTE_COUNT_MASK_2 | first_chunk);
	buffer[UNICODE_BYTE_2] = (char)(SUBSEQUENT_BYTE_MASK | second_chunk);
	return (UNICODE_BYTE_LENGTH_2);
}
