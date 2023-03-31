#include "42sh.h"

static void	handle_buffer(t_42sh *shell, char *buffer) {
	if (is_print_del_char(shell, buffer)) {}
	else if (is_arrow_key(buffer)) {}
}

void		loop(t_42sh *shell) {
	(void)shell;
	char	buffer[11];
	int		ret;

	ft_bzero(buffer, 11);
	ft_putstr_fd("42sh > ", 1);
	shell->command = ft_strdup("");
	while ((ret = read(0, buffer, 10))) {
		// ft_putstr_fd(buf, 1);
		handle_buffer(shell, buffer);
		if (strcmp(buffer, "\n") == 0) {
			// TODO: handle command
			shell->command = ft_strdup("");
			ft_putstr_fd("\n42sh > ", 1);
		}
		ft_bzero(buffer, 11);
	}
}
