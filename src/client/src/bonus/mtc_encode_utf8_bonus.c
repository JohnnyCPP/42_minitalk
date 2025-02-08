/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtc_encode_utf8_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mt_client.h"

static	int	mtc_encode_1byte_utf8(char *buffer, unsigned int unicode)
{
	buffer[UNICODE_BYTE_1] = (char) unicode;
	return (UNICODE_BYTE_LENGTH_1);
}

int	mtc_encode_utf8(char *buffer, unsigned int unicode)
{
	if (unicode <= CODE_POINT_1)
		return (mtc_encode_1byte_utf8(buffer, unicode));
	else if (unicode <= CODE_POINT_2)
		return (mtc_encode_2byte_utf8(buffer, unicode));
	else if (unicode <= CODE_POINT_3)
		return (mtc_encode_3byte_utf8(buffer, unicode));
	else if (unicode <= CODE_POINT_4)
		return (mtc_encode_4byte_utf8(buffer, unicode));
	return (UTF_INVALID_INPUT);
}
