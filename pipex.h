/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:09:36 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 20:46:08 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_vars
{
	char	*path_dir_orig;
	char	*path_dir;
	char	**path_splitted;
	char	**cmd;
	int		*pid;
	int		p[2];
	int		i;
	int		j;
}				t_vars;

void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char const *s);
void	free_incase_ofleak(char **tab, int k);
char	**ft_split(char const *s, char c);
void	pipex(int argc, char **argv, char **envp);
void	argv1_neg(char **argv);
void	argv4_neg(void);
void	cmd_is_known(t_vars *vars, char **argv, char **envp);
void	access_denied(char *cmd);
void	free_tab2dim(char **s);
void	join_paths(t_vars *vars, char **argv, char **envp);

#endif