/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv1_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:21:36 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 20:17:46 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	argv1_neg(char **argv)
{
	write(2, "no such file or directory: ", 27);
	write(2, argv[1], ft_strlen(argv[1]));
	write(2, "\n", 1);
	open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	exit(1);
}
