/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:17:28 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 16:58:48 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin_read(char *buffer, char *buff)
{
	char	*al;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(buffer);
	al = malloc(len + 2);
	if (al == 0)
		return (0);
	while (buffer[i])
	{
		al[i] = buffer[i];
		i++;
	}
	al[len] = buff[0];
	al[len + 1] = '\0';
	free(buffer);
	return (al);
}

char	*ft_read(int fd)
{
	char	*buffer;
	char	buff[1];
	int		i;

	i = 1;
	buffer = ft_strdup("");
	while (i)
	{
		i = read(fd, buff, 1);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer = ft_strjoin_read(buffer, buff);
		if (buff[0] == '\n')
			break ;
	}
	if (buffer[0] != '\0')
		return (buffer);
	free(buffer);
	return (NULL);
}

int	ft_validate(char *tab)
{
	int	i;

	if (tab == NULL)
	{
		printf("Error\nempty map file");
		free(tab);
		return (1);
	}
	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (tab[i] == '\n' && tab[i + 1] == '\n')
		{
			printf("Error\nFound extra new line");
			return (1);
		}
		i++;
	}
	if (tab[i] && tab[i] == '\n')
	{
		printf("Error\nFound extra new line at the end");
		return (1);
	}
	return (0);
}

int	ft_norm(int *fd, char *buffer, char *tab)
{
	close((*fd));
	free(buffer);
	if (ft_validate(tab) == 1)
	{
		free(tab);
		return (1);
	}
	return (0);
}

char	**ft_map(char *map)
{
	char	*buffer;
	char	*tab;
	char	**tab2;
	int		fd;

	tab = NULL;
	tab2 = NULL;
	fd = open(map, O_RDWR);
	buffer = ft_read(fd);
	if (buffer == 0)
		return (0);
	while (buffer)
	{
		if (!tab)
			tab = ft_strdup(buffer);
		else
			tab = ft_strjoin(tab, buffer);
		buffer = ft_read(fd);
	}
	if (ft_norm(&fd, buffer, tab) == 1)
		return (0);
	tab2 = ft_split(tab, '\n');
	free(tab);
	return (tab2);
}
