#ifndef PROMPT_H
#define PROMPT_H

# include <signal.h>
# include <term.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

#include "libft.h"

typedef struct			s_env {
	char				*key;
	char				*value;
}						t_env;


typedef struct			s_42sh {
	t_list				*env;
}						t_42sh;

t_list	*init_env(char **env);


#endif