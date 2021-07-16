/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_known.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:44:40 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/16 08:17:55 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fork_(t_vars *vars)
{
	vars->pid[vars->i] = fork();
	if (vars->pid[vars->i] < 0)
		ft_putstr_fd("fork failed !", 2);
}

void	cmd_is_known(t_vars *vars, char **argv, char **envp)
{
	int	fd;

	fork_(vars);
	if (vars->pid[vars->i] == 0)
	{
		if (vars->i == 0)
		{
			dup2(vars->p[1], 1);
			close(vars->p[0]);
			// fd = open(argv[1], O_RDONLY);
			// dup2(fd, 0);
			// close(fd);
		}
		else
		{
			dup2(vars->p[0], 0);
			close(vars->p[1]);
			fd = open(argv[4], O_RDWR);
			dup2(fd, 1);
			close(fd);
		}
		if (execve(vars->path_dir, vars->cmd, envp) == -1)
			ft_putstr_fd("execve failed!", 2);
		exit(1);
	}
	close(vars->p[1]);
	waitpid(vars->pid[vars->i], 0, 0);
}
