/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_send_message_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

static	void	mtc_send_utf8_char(const char *buf, int utf_bytes, pid_t pid)
{
	int	byte;
	int	bit;
	int	bit_position;

	byte = 0;
	while (byte < utf_bytes)
	{
		bit_position = BITS_IN_BYTE - 1;
		while (0 <= bit_position)
		{
			bit = ft_get_bit((long) buf[byte], bit_position);
			mtc_send_bit(pid, bit);
			bit_position --;
		}
		byte ++;
	}
}

static	void	mtc_initialize_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < UTF_BUFFER_LENGTH)
	{
		buffer[i] = '\0';
		i ++;
	}
}

void	mtc_send_message(pid_t pid, const char *message)
{
	char			buffer[UTF_BUFFER_LENGTH];
	int				i;
	int				utf_bytes;
	int				bytes_consumed;
	unsigned int	unicode;

	mtc_initialize_buffer(buffer);
	i = 0;
	while (message[i] != '\0')
	{
		unicode = mtc_decode_utf8(&message[i], &bytes_consumed);
		if (bytes_consumed == 0)
		{
			ft_putendl_fd(ERROR_UTF8, STDERR_FILENO);
			break ;
		}
		utf_bytes = mtc_encode_utf8(buffer, unicode);
		mtc_send_utf8_char(buffer, utf_bytes, pid);
		i += bytes_consumed;
	}
	mtc_send_utf8_char("\0", 1, pid);
}
