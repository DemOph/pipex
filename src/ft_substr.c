/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:32:49 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 19:54:23 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	l;
	char	*ptr;

	j = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(&s[start]);
	if (start > ((unsigned int)ft_strlen(s)))
		return (ft_strdup(""));
	if (l >= len)
		l = len;
	ptr = (char *)malloc(sizeof(*ptr) * (len + 1));
	if (!ptr)
		return (NULL);
	while (j < l && s[start])
	{
		ptr[j] = s[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
