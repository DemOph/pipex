/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:23:11 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/07 17:58:22 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char    *ft_strdup(const char *s1)
{
    int i;
    char    *ptr;

    if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1) + 1))))
            return (NULL);
    i = 0;
    while (s1[i])
    {
            ptr[i] = s1[i];
            i++;
    }
    ptr[i] = '\0';
    return (ptr);
}