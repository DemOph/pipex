/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:04:21 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 21:11:20 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**search_for_path(char **envp)
{
	int		i;
	char	**path_splited;

	i = 0;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		(*envp)++;
	if (*envp == NULL)
		return (NULL);
	if (ft_strncmp(*envp, "PATH=", 5) == 0)
	{
		path_splited = ft_split(*envp + 5, ':');
		return (path_splited);
	}
	return (NULL);
}

char	**store_flags_return_cmd(int i, char **argv)
{
	char	**argg;

	if (i == 0)
		argg = ft_split(argv[2], ' ');
	else
		argg = ft_split(argv[3], ' ');
	return (argg);
}

void	iscmd_builtin_sh(char **argv, char **envp)
{
	t_vars	vars;

	vars.path_splitted = search_for_path(envp);
	vars.pid = malloc(sizeof(int) * 2);
	if (pipe(vars.p) < 0)
		ft_putstr_fd("pipe failed!\n", 2);
	if (!vars.pid)
		exit(EXIT_FAILURE);
	vars.i = -1;
	while (++(vars.i) < 2)
	{
		vars.cmd = store_flags_return_cmd(vars.i, argv);
		vars.j = 0;
		join_paths(&vars, argv, envp);
		if (access(vars.path_dir, F_OK) == -1)
			access_denied(vars.cmd[0]);
		free_tab2dim(vars.cmd);
	}
	free_tab2dim(vars.path_splitted);
	free(vars.pid);
	return ;
}

void	pipex(int argc, char **argv, char **envp)
{
	int	i;
	int	fd1;
	int	fd2;

	i = 0;
	if (argc != 5)
		exit(EXIT_FAILURE);
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 < 0)
			argv1_neg(argv);
		close(fd1);
		fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 0)
			argv4_neg();
		close(fd2);
	}
	iscmd_builtin_sh(argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	pipex(argc, argv, envp);
	return (0);
}
