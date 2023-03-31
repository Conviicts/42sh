#include "42sh.h"
#include "libft.h"


static int			have_env_var(char **env, char *check) {
	int	i;

	i = 0;
	while (env && env[i]) {
		if (ft_strnstr(env[i], check, ft_strlen(check)))
			return (1);
		i++;
	}
	return (0);
}

static char			*get_path(void) {
	char	path[255];
	int		ret;
	int		fd;

	ret = 0;
	if ((fd = open("/etc/paths", O_RDONLY)) == -1)
		return (NULL);
	ret = read(fd, path, 255);
	close(fd);
	path[ret - 1] = '\0';
	ret = 0;
	while (path[ret]) {
		if (path[ret] == '\n')
			path[ret] = ':';
		ret++;
	}
	return (ft_strdup(path));
}

void				add_elem_end(t_list **lst, char *key, char *value) {
	t_env	*new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return ;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	ft_lstadd_back(lst, ft_lstnew(new));
}

t_list	*init_env(char **env) {
	t_list	*res;
	char	*tmp;

	res = NULL;
	if (!have_env_var(env, "PATH=")) {
		tmp = get_path();
		add_elem_end(&res, "PATH", tmp);
		free(tmp);
	}
	if (!have_env_var(env, "HOME="))
		add_elem_end(&res, "HOME", "/");
	if (!have_env_var(env, "SHLVL="))
		add_elem_end(&res, "SHLVL", "0");
	if (!have_env_var(env, "TERM="))
		add_elem_end(&res, "TERM", "xterm-256color");
	
	return (res);
}