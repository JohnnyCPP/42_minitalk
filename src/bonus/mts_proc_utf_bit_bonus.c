/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_proc_utf_bit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

static	int	mts_get_utf8_len(unsigned char first_byte)
{
	if ((first_byte & SEQUENCE_LENGTH_MASK_1) == BYTE_COUNT_MASK_1)
		return (UTF_BYTE_LENGTH_1);
	else if ((first_byte & SEQUENCE_LENGTH_MASK_2) == BYTE_COUNT_MASK_2)
		return (UTF_BYTE_LENGTH_2);
	else if ((first_byte & SEQUENCE_LENGTH_MASK_3) == BYTE_COUNT_MASK_3)
		return (UTF_BYTE_LENGTH_3);
	else if ((first_byte & SEQUENCE_LENGTH_MASK_4) == BYTE_COUNT_MASK_4)
		return (UTF_BYTE_LENGTH_4);
	return (UTF_INVALID_SEQUENCE);
}

static	void	mts_reset_buffer(unsigned char *buffer)
{
	int	byte;

	byte = 0;
	while (byte < UTF_BUFFER_SIZE)
	{
		buffer[byte] = '\0';
		byte ++;
	}
}

static	void	mts_process_msb(int bit, t_utf8_data *data)
{
	*data->current_byte = (*data->current_byte << 1) | bit;
	(*data->bit_count)++;
	if (*data->bit_count == BITS_IN_BYTE)
	{
		data->buffer[(*data->byte_count)++] = *data->current_byte;
		*data->current_byte = 0;
		*data->bit_count = 0;
		if (mts_get_utf8_len(data->buffer[0]) == UTF_INVALID_SEQUENCE)
		{
			*data->byte_count = 0;
			return ;
		}
		if (mts_get_utf8_len(data->buffer[0]) == *data->byte_count)
		{
			if (*data->buffer == '\0')
				ft_printf("\n");
			else
				ft_printf("%s", data->buffer);
			*data->byte_count = 0;
			mts_reset_buffer(data->buffer);
		}
	}
}

void	mts_proc_utf_bit(int bit, pid_t pid, unsigned char *buf, char *curr_b)
{
	static pid_t			client_pid = 0;
	static int				byte_count = 0;
	static int				bit_count = 0;
	t_utf8_data				utf8_data;

	if (client_pid != pid)
	{
		mts_reset_buffer(buf);
		*curr_b = '\0';
		client_pid = pid;
		byte_count = 0;
		bit_count = 0;
	}
	utf8_data = (t_utf8_data){buf, curr_b, &byte_count, &bit_count};
	mts_process_msb(bit, &utf8_data);
}
