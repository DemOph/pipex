/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:19:25 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/15 21:10:30 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wc++;
		i++;
	}
	return (wc);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strncpy(char *dst, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*free_(int i, char const *s, int k, char c)
{
	char	*tab;

	tab = NULL;
	tab = (char *)malloc(sizeof(char) * (word_len(s + k, c) + 1));
	if (!tab)
	{
		free_incase_ofleak(&tab, i);
		return (NULL);
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (i < word_count(s, c))
	{
		while (s[k] == c)
			k++;
		tab[i] = free_(i, s, k, c);
		ft_strncpy(tab[i++], s + k, word_len(s + k, c) + 1);
		k += word_len(s + k, c);
	}
	tab[i] = NULL;
	return (tab);
}
