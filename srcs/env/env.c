#include "42sh.h"

void	env_add_back(t_list **lst, char *key, char *value) {
	t_env	*new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return ;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	ft_lstadd_back(lst, ft_lstnew(new));
}

char	*get_env_var(t_list *env, char *key) {
	t_env	*tmp;

	while (env) {
		tmp = (t_env*)env->content;
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
			return (tmp->value);
		env = env->next;
	}
	return (NULL);
}

t_list	*create_env(char **env) {
	t_list	*res;
	char	*tmp;

	res = NULL;
	if (!have_env_var(env, "PATH=")) {
		tmp = get_path();
		env_add_back(&res, "PATH", tmp);
		free(tmp);
	}
	if (!have_env_var(env, "HOME="))
		env_add_back(&res, "HOME", "/");
	if (!have_env_var(env, "SHLVL="))
		env_add_back(&res, "SHLVL", "0");
	if (!have_env_var(env, "TERM="))
		env_add_back(&res, "TERM", "xterm-256color");
	return (res);
}

t_list	*parse_env(char **env) {
	int		i;
	t_list	*res;

	i = 0;
	res = create_env(env);
	while (env[i] != NULL) {
		parse_line(&res, env[i]);
		i++;
	}
	return (res);
}

void	free_env(t_list *lst) {
	t_list	*tmp;
	t_env	*tmp2;

	while (lst) {
		tmp = lst->next;
		tmp2 = (t_env*)lst->content;
		free(tmp2->key);
		free(tmp2->value);
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}
