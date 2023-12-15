/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:11:00 by igama             #+#    #+#             */
/*   Updated: 2023/12/14 21:29:00 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp_ch;
	int		i;

	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	temp_ch = c;
	i = 0;
	while (*(s + i) && (*(s + i) != temp_ch))
		i++;
	if (*(s + i) == temp_ch)
		return ((char *) s + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_sum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	len_sum = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len_sum));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}
