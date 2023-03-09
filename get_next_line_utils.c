/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufukuda <yufukuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:38:29 by yufukuda          #+#    #+#             */
/*   Updated: 2023/03/02 13:38:30 by yufukuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*a;

	i = 0;
	while (s1[i] != '\0')
		i++;
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*point;
	const char	*pointer;

	point = (char *)dst;
	pointer = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		point[i] = pointer[i];
		i++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *save, char *buf)
{
	char	*new_save;
	size_t	i;
	size_t	j;

	if (save == NULL && buf)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	else if (save == NULL || buf == NULL)
		return (NULL);
	i = ft_strlen(save);
	j = ft_strlen(buf);
	new_save = (char *)malloc(sizeof(char) * (i + j + 1));
	if (new_save == NULL)
	{
		free(save);
		free(buf);
		return (NULL);
	}
	ft_memcpy(new_save, save, i);
	ft_memcpy(new_save + i, buf, j);
	new_save[i + j] = '\0';
	free(save);
	return (new_save);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (s == NULL)
		return (NULL);
	if (c == '\0')
	{
		while (*s != '\0')
			s++;
		p = (char *)s;
		return (p);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			p = (char *)s;
			return (p);
		}
		s++;
	}
	return (NULL);
}

// int main()
// {
// 	// char	str = NULL;
// 	printf("%s",ft_strchr(NULL, '\n'));
// }