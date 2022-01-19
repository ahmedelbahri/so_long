/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:22:01 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 17:17:27 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strcheck(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_elements(char *str, int *p, int *c, int *e)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != '0' && str[i] != '1' && str[i] != 'K')
		{
			printf("Error\nUnrecognised element");
			return (1);
		}
		if (str[i] == 'P')
			(*p)++;
		if (str[i] == 'C')
			(*c)++;
		if (str[i] == 'E')
			(*e)++;
		i++;
	}
	return (0);
}

int	ft_mapchecker(char **map, int *p, int *c, int *e)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_lencmp(map[0], map[i]) == 1)
		{
			printf("Error\nYour map alignement isn't valid");
			return (1);
		}
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			printf("Error\nYour inner borders are not set right");
			return (1);
		}
		if (ft_check_elements(map[i], p, c, e) == 1)
			return (1);
		i++;
	}
	return (i);
}

int	ft_mapcheck(char **map)
{
	int	p;
	int	c;
	int	e;
	int	len;

	p = 0;
	c = 0;
	e = 0;
	if (map[0] == NULL)
		return (1);
	len = ft_mapchecker(map, &p, &c, &e);
	if (len == 1)
		return (1);
	if (p != 1 || c < 1 || e < 1)
	{
		printf("Error\ninvalid elements");
		return (1);
	}
	if (ft_strcheck(map[len - 1], '1') == 1 || ft_strcheck(map[0], '1') == 1)
	{
		printf("Error\nYour map top or bottom border isn't valid");
		return (1);
	}
	return (0);
}
