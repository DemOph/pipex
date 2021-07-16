/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:53:36 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 17:27:39 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	join_paths(t_vars *vars, char **argv, char **envp)
{
	vars->j = 0;
	while (vars->path_splitted[vars->j])
	{
		vars->path_dir_orig = ft_strjoin((vars->path_splitted[vars->j]), "/");
		vars->path_dir = ft_strjoin(vars->path_dir_orig, vars->cmd[0]);
		if (!access(vars->path_dir, F_OK))
		{
			cmd_is_known(vars, argv, envp);
			free(vars->path_dir_orig);
			free(vars->path_dir);
			break ;
		}
		free(vars->path_dir_orig);
		free(vars->path_dir);
		vars->j++;
	}
}
