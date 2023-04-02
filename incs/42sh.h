#ifndef PROMPT_H
#define PROMPT_H

# include <signal.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

#include "libft.h"

#define t_termios struct termios

typedef struct	s_env {
	char		*key;
	char		*value;
}				t_env;


typedef struct	s_42sh {
	t_list		*env;
	char		*command;
	char		*prompt;
}				t_42sh;

t_list			*parse_env(char **env);
char			*get_env_var(t_list *env, char *key);
void			parse_line(t_list **res, char *env);
char			*get_path(void);
int				have_env_var(char **env, char *check);
void			env_add_back(t_list **lst, char *key, char *value);
void			free_env(t_list *lst);


t_termios		*init_term(t_42sh *shell);
t_termios		*init_termios(t_termios *term, int i);

int				is_print_del_char(t_42sh *shell, char *buffer);
int				is_arrow_key(char *buffer);

char			*get_prompt(t_42sh *shell);

void			loop(t_42sh *shell);



#endif