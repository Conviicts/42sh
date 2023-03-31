#include "42sh.h"

int main(int ac, char **av, char **env) {
	(void)ac;
	(void)av;
	t_42sh			shell;
	struct termios	*term;
	
	ft_memset(&shell, 0, sizeof(shell));
	shell.env = parse_env(env);

	if ((term = init_term(&shell)) == NULL) {
		ft_putstr_fd("42sh: Can't find terminal definition. Exiting now.\n", 2);
		free_env(shell.env);
		free(term);
		return (0);
	}

	free_env(shell.env);
	free(term);
	system("leaks 42sh");
	return (0);
}
