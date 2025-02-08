/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_structures_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTS_STRUCTURES_BONUS_H
# define MTS_STRUCTURES_BONUS_H

/**
 * @brief Group of variables used when processing UTF-8 sequences.
 */
typedef struct s_utf8_data
{
	unsigned char	*buffer;
	char			*current_byte;
	int				*byte_count;
	int				*bit_count;
}				t_utf8_data;

#endif
