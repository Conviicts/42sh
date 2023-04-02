/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:42:40 by jode-vri          #+#    #+#             */
/*   Updated: 2023/04/02 10:42:41 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_putchar(int c)
{
	static int	fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_RDWR);
	if (!isatty(fd))
	{
		ft_putstr_fd("/dev/tty is not a valid tty.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (c == -1)
	{
		close(fd);
		return (c);
	}
	write(fd, &c, 1);
	return (c);
}

void	add_char(t_42sh *shell, char *buffer) {
	(void)shell;
	(void)buffer;
	shell->command = ft_strjoin(shell->command, buffer);
	ft_putstr_fd(buffer, 1);
}

void	del_char(t_42sh *shell) {
	(void)shell;
	if (ft_strlen(shell->command) > 0) {
		ft_putstr_fd("\b \b", 1);
		shell->command = ft_substr(shell->command, 0, ft_strlen(shell->command) - 1);
	}
	// tputs(tgetstr("vb", NULL), 1, ft_putchar);
	// tputs(tgetstr("le", NULL), 1, ft_putchar);
	// tputs(tgetstr("nd", NULL), 1, ft_putchar);
}

int		is_print_del_char(t_42sh *shell, char *buffer) {
	if ((ft_isalpha(buffer[0]) || (buffer[0] >= 32 && buffer[0] <= 64)
		|| (buffer[0] >= 123 && buffer[0] <= 126) || (buffer[0] >= 91 && buffer[0] <= 96))
		&& buffer[1] == '\0')
		add_char(shell, buffer);
	else if (buffer[0] == 127 && buffer[1] == 0)
		del_char(shell);
	else
		return (0);
	return (1);
}
