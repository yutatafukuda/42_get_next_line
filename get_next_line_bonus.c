/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufukuda <yufukuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:38:25 by yufukuda          #+#    #+#             */
/*   Updated: 2023/03/10 01:27:55 by yufukuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_real_save(char *save)
{
	char	*real_save;
	size_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	real_save = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (real_save == NULL)
		return (NULL);
	if (ft_strchr(save, '\n') == NULL)
	{
		free(real_save);
		free(save);
		return (NULL);
	}
	i++;
	ft_memcpy(real_save, save + i, ft_strlen(save) - i);
	real_save[ft_strlen(save) - i] = '\0';
	free(save);
	return (real_save);
}

char	*ft_get_line(char *save)
{
	char	*real_line;
	size_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	real_line = malloc(sizeof(char) * (i + 1 + 1));
	if (real_line == NULL)
	{
		free(save);
		return (NULL);
	}
	if (ft_strchr(save, '\n') == NULL)
	{
		free(real_line);
		return (ft_strdup(save));
	}
	ft_memcpy(real_line, save, i);
	real_line[i] = '\n';
	real_line[i + 1] = '\0';
	return (real_line);
}

char	*ft_last_free(char *buf, char *save)
{
	free(buf);
	free(save);
	return (NULL);
}

char	*ft_read_and_save_check(int fd, char *save)
{
	char	*buf;
	ssize_t	read_size;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + (size_t)1));
	if (buf == NULL)
	{
		free(save);
		return (NULL);
	}
	read_size = 1;
	while (!ft_strchr(save, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (ft_last_free(buf, save));
		buf[read_size] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (read_size == 0 && *save == '\0')
		return (ft_last_free(buf, save));
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	save[fd] = ft_read_and_save_check(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_real_save(save[fd]);
	return (line);
}

// int main(void)
// {
// 	int	fd;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));
// 	system("leaks -q a.out");
// 	close(fd);
// 	// BUFFER_SIZE=42;
// }
