#include "42sh.h"

void		loop(t_42sh *shell) {
	(void)shell;
	char	buf[11];
	int		r;

	ft_bzero(buf, 11);
	ft_putstr_fd("42sh > ", 1);
	while ((r = read(0, buf, 10))) {
		ft_putstr_fd(buf, 1);
		if (strcmp(buf, "\n") == 0) {
			ft_putstr_fd("42sh > ", 1);
		}
		ft_bzero(buf, 11);
	}
}