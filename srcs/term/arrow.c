/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:42:57 by jode-vri          #+#    #+#             */
/*   Updated: 2023/04/02 10:43:04 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		is_arrow_key(char *buffer) {
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65
		&& buffer[3] == 0)
		ft_putstr_fd("up", 1);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66
		&& buffer[3] == 0)
		ft_putstr_fd("down", 1);
	else
		return (0);
	return (1);
}
