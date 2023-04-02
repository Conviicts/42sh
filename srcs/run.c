/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:42:15 by jode-vri          #+#    #+#             */
/*   Updated: 2023/04/02 10:42:16 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void	handle_buffer(t_42sh *shell, char *buffer) {
	if (is_print_del_char(shell, buffer)) {}
	else if (is_arrow_key(buffer)) {}
}

void		loop(t_42sh *shell) {
	char	buffer[11];
	int		ret;

	ft_bzero(buffer, 11);
	shell->command = ft_strdup("");
	shell->prompt = get_prompt(shell);
	ft_putstr_fd(shell->prompt, 1);
	while ((ret = read(0, buffer, 10))) {
		// ft_putstr_fd(buf, 1);
		handle_buffer(shell, buffer);
		if (strcmp(buffer, "\n") == 0) {
			// TODO: handle command
			shell->command = ft_strdup("");
			shell->prompt = get_prompt(shell);
			ft_putstr_fd("\n", 1);
			ft_putstr_fd(shell->prompt, 1);
		}
		ft_bzero(buffer, 11);
	}
}
