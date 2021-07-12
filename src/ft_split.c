/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:19:25 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/12 11:19:55 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int              word_count(char const *s, char c)
{
        int                     i;
        int                     wc;

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

static int              word_len(char const *s, char c)
{
        int                     len;

        len = 0;
        while (s[len] && s[len] != c)
                len++;
        return (len);
}

static char             *ft_strncpy(char *dst, char const *src, int n)
{
        int                     i;

        i = 0;
        while (src[i] && i < n - 1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (dst);
}

static  void    free_incase_ofleak(char **tab, int k)
{
        int                     i;

        i = -1;
        while (++i < k)
                free(tab[i]);
        free(tab);
}

char                    **ft_split(char const *s, char c)
{
        char            **tab;
        int                     i;
        int                     k;

        if (!s)
                return (NULL);
        if (!(tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
                return (NULL);
        i = 0;
        k = 0;
        while (i < word_count(s, c))
        {
                while (s[k] == c)
                        k++;
                if (!(tab[i] = (char *)malloc(sizeof(char) * (word_len(s + k, c) + 1))))
                {
                        free_incase_ofleak(tab, i);
                        return (NULL);
                }
                ft_strncpy(tab[i++], s + k, word_len(s + k, c) + 1);
                k += word_len(s + k, c);
        }
        tab[i] = NULL;
        return (tab);
}