/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_decode_utf8_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

/*
void	mts_decode_utf8(unsigned char *buffer, int byte_count)
{
	unsigned int	unicode;
	unsigned int	first_chunk;
	unsigned int	second_chunk;
	unsigned int	third_chunk;
	unsigned int	fourth_chunk;

	unicode = 0;
	if (byte_count == UTF_BYTE_LENGTH_1)
		unicode = buffer[0];
	else if (byte_count == UTF_BYTE_LENGTH_2)
	{
		first_chunk = (buffer[0] & MASK_CHUNK_5) << BITS_SUBS_BYTE;
		unicode = first_chunk | (buffer[1] & MASK_CHUNK_6);
	}
	else if (byte_count == UTF_BYTE_LENGTH_3)
	{
		first_chunk = (buffer[0] & MASK_CHUNK_4) << BITS_SUBS_BYTE * 2;
		second_chunk = (buffer[1] & MASK_CHUNK_6) << BITS_SUBS_BYTE;
		unicode = first_chunk | second_chunk | (buffer[2] & MASK_CHUNK_6);
	}
	else if (byte_count == UTF_BYTE_LENGTH_4)
	{
		first_chunk = (buffer[0] & MASK_CHUNK_3) << BITS_SUBS_BYTE * 3;
		second_chunk = (buffer[1] & MASK_CHUNK_6) << BITS_SUBS_BYTE * 2;
		third_chunk = (buffer[2] & MASK_CHUNK_6) << BITS_SUBS_BYTE;
		fourth_chunk = buffer[3] & MASK_CHUNK_6;
		unicode = first_chunk | second_chunk | third_chunk | fourth_chunk;
	}
	else
		return ;
	ft_printf("%c", unicode);
}
*/
