/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:05:57 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/07 17:58:07 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    i = 0;
    if ((!s1 || !s2) && n == 0)
            return (0);
    while ((s1[i] || s2[i]) && i < n)
    {
            if (s1[i] != s2[i])
                    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
            i++;
    }
    return (0);
}