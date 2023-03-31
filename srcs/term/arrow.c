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