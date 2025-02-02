/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_send_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

static	void	mtc_send_msb_first(pid_t pid, const char c)
{
	int	bits;
	int	bit;
	int	i;

	bits = BITS_IN_BYTE * sizeof(char);
	i = bits - 1;
	while (0 <= i)
	{
		bit = ft_get_bit((long) c, i);
		mtc_send_bit(pid, bit);
		i --;
	}
}

static	void	mtc_send_lsb_first(pid_t pid, const char c)
{
	int	bits;
	int	bit;
	int	i;

	bits = BITS_IN_BYTE * sizeof(char);
	i = 0;
	while (i < bits)
	{
		bit = ft_get_bit((long) c, i);
		mtc_send_bit(pid, bit);
		i ++;
	}
}

void	mtc_send_char(pid_t pid, const char c)
{
	if (TRANSMISSION_ENDIANESS == LSB_FIRST)
		mtc_send_lsb_first(pid, c);
	else if (TRANSMISSION_ENDIANESS == MSB_FIRST)
		mtc_send_msb_first(pid, c);
}
