/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_denied.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:38:55 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 16:35:24 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	access_denied(char *cmd)
{
	write(2, "no command found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
