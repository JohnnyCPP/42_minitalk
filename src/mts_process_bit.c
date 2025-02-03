/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_process_bit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_server.h"

static	void	mts_process_msb_first(const int bit, int *bcount, char *buff)
{
	*buff <<= 1;
	*buff |= bit;
	(*bcount)++;
	if (*bcount == BITS_IN_BYTE)
	{
		if (*buff == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", *buff);
		*buff = 0;
		*bcount = 0;
	}
}

static	char	mts_rotate_right(unsigned char c, int shift)
{
	unsigned char	result;
	int				end_position;

	result = c >> shift;
	end_position = BITS_IN_BYTE - shift;
	result |= (c << end_position);
	return ((char) result);
}

static	void	mts_process_lsb_first(const int bit, int *bcount, char *buff)
{
	*buff = mts_rotate_right((unsigned char)(*buff), 1);
	*buff |= bit;
	(*bcount)++;
	if (*bcount == BITS_IN_BYTE)
	{
		if (*buff == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", *buff);
		*buff = 0;
		*bcount = 0;
	}
}

void	mts_process_bit(const int bit, siginfo_t *info)
{
	static pid_t	client_pid = 0;
	static int		bit_count = 0;
	static char		buffer;

	if (client_pid != info->si_pid)
	{
		buffer = 0;
		bit_count = 0;
		client_pid = info->si_pid;
	}
	if (TRANSMISSION_ENDIANESS == LSB_FIRST)
		mts_process_lsb_first(bit, &bit_count, &buffer);
	else if (TRANSMISSION_ENDIANESS == MSB_FIRST)
		mts_process_msb_first(bit, &bit_count, &buffer);
}
