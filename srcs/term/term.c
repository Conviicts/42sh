/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:42:26 by jode-vri          #+#    #+#             */
/*   Updated: 2023/04/02 10:42:35 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char		*get_prompt(t_42sh *shell) {
	char	*res;
	char	*ps1;
	char	**cwd;

	ps1 = get_env_var(shell->env, "PS1");
	if (!ps1 || ft_strncmp(ps1, "", ft_strlen(ps1)) == 0) {
		free(ps1);
		ps1 = getcwd(NULL, 0);
		cwd = ft_split(ps1, '/');
		res = ft_strjoin("\e[0;32m", "➜ \e[1;36m");
		res = ft_strjoin(res, cwd[ft_arraylen(cwd) - 1]);
		res = ft_strjoin(res, " \e[0;33m✗ \e[0m");
	}
	else {
		res = ps1;
	}
	return (res);
}

t_termios	*init_termios(t_termios *term, int i) {
	static t_termios *res = NULL;

	if (i)
		res = term;
	return (res);
}

t_termios	*init_term(t_42sh *shell) {
	t_termios	term;
	t_termios	*res;
	char			*term_name;

	res = malloc(sizeof(t_termios));
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
