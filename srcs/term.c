#include "42sh.h"

struct termios	*init_termios(struct termios *term, int i) {
	static struct termios *res = NULL;

	if (i)
		res = term;
	return (res);
}

struct termios	*init_term(t_42sh *shell) {
	struct termios	term;
	struct termios	*res;
	char			*term_name;

	res = malloc(sizeof(struct termios));
	if (!res)
		return (NULL);
	tcgetattr(0, &term);
	tcgetattr(0, res);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (isatty(0) && tcsetattr(0, TCSADRAIN, &term) == -1)
		return (NULL);
	term_name = ft_strdup(get_env_var(shell->env, "TERM"));
	if (!ft_strncmp(term_name, "", ft_strlen(term_name)) || tgetent(NULL, term_name) == ERR) {
		free(term_name);
		free(res);
		return (NULL);
	}
	free(term_name);
	return (res);
}