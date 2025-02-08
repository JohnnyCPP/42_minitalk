/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mts_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTS_PROTOTYPES_BONUS_H
# define MTS_PROTOTYPES_BONUS_H

/**
 * @brief Processes a bit part of a UTF-8 sequence.
 *
 * @param bit The bit to process.
 * @param pid The pid from the sender process.
 * @param buf The buffer containing the UTF-8 sequence.
 * @param curr_b The current byte of the UTF-8 sequence.
 */
void	mts_proc_utf_bit(int bit, pid_t pid, unsigned char *buf, char *curr_b);

#endif
