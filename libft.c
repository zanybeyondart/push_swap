/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:48:23 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/09 18:10:02 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lentotal;
	char	*strjoin;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2 || !s1)
		return (NULL);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(lentotal + 1);
	if (!strjoin)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (free((char *)s1), strjoin);
}

char	**ft_split(const char *s, char c)
{
	int		v[2];
	int		start;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ((countword (s, c)) + 1));
	if (!result)
		return (NULL);
	v[0] = 0;
	v[1] = 0;
	while (s[v[0]] != '\0' && v[1] < (countword (s, c)))
	{
		if (s[v[0]] == c)
			v[0]++;
		else
		{
			start = v[0];
			while (s[v[0]] != c && s[v[0]] != '\0')
				v[0]++;
			result[v[1]++] = wordassign ((char *) s + start, v[0] - start);
		}
	}
	result[v[1]] = NULL;
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d == s || (d == NULL && s == NULL ))
	{
		return (d);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
