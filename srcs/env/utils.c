#include "42sh.h"

int		have_env_var(char **env, char *check) {
	int	i;

	i = 0;
	while (env && env[i]) {
		if (ft_strnstr(env[i], check, ft_strlen(check)))
			return (1);
		i++;
	}
	return (0);
}

char	*get_path(void) {
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

void	parse_line(t_list **res, char *env) {
	char	*ptr;
	char	*s1;
	char	*s2;

	ptr = ft_strchr(env, '=');
	if (!ptr)
		return ;
	s1 = ft_substr(env, 0, ptr - env);
	s2 = ft_substr(ptr, 1, ft_strlen(ptr) - 1);
	if (!s2)
		s2 = ft_strdup("");
	env_add_back(res, s1, s2);
	free(s1);
	free(s2);
}
