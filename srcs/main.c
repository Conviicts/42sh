#include "42sh.h"

int main(int ac, char **av, char **env) {
	(void)ac;
	(void)av;
	(void)env;
	
	t_42sh	shell;
	
	ft_memset(&shell, 0, sizeof(shell));

	shell.env = init_env(env);

	// printf("%s\n", ((t_env*)shell.env->content)->value);
	// printf("%s\n", ((t_env*)shell.env->next->content)->value);
	// printf("%s\n", ((t_env*)shell.env->next->next->content)->value);
	// printf("%s\n", ((t_env*)shell.env->next->next->next->content)->value);

	// system("leaks 42sh");
	return (0);
}
