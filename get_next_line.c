/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:27:23 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/05/18 19:54:42 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line(char *rest)
{
	char	*line;
	int		index;
	int		i;

	i = 0;
	if (ft_strlen(rest) <= 0)
		return (NULL);
	index = ft_find(rest);
	if (index == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	while (rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_rest(char *rest)
{
	int		len;
	int		index;
	char	*tmp;

	if (!rest)
		return (NULL);
	len = ft_strlen(rest);
	index = ft_find(rest);
	if (index != -1)
	{
		tmp = ft_substr(rest, (index + 1), (len - index - 1));
		free (rest);
		rest = tmp;
		return (rest);
	}
	free (rest);
	return (NULL);
}

char	*ft_read(int fd, char *buff, char *rest)
{
	char	*tmp;
	int		n;

	n = 1;
	while (n > 0 && ft_find(rest) == -1)
	{
		n = read (fd, buff, BUFFER_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			tmp = ft_strjoin(rest, buff);
			if (rest)
				free(rest);
			rest = NULL;
			rest = tmp;
		}
	}
	free (buff);
	buff = NULL;
	if (n == -1)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*rest;

	if (BUFFER_SIZE <= 0 || (fd != 0 && fd <= 2))
		return (NULL);
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rest = ft_read(fd, buff, rest);
	line = ft_line(rest);
	rest = ft_rest(rest);
	return (line);
}

// int main()
// {
// 	int fd = open("walid.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));

// }