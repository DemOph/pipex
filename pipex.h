/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:09:36 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/12 11:20:13 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(char const *s);
void    ft_putstr_fd(char *s, int fd);
char    **ft_split(char const *s, char c);