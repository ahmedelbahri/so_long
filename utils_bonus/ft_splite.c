/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:48:09 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/17 21:19:10 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_countw(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c)
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

int	ft_lencount(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**ft_free(char **ml)
{
	int	i;

	i = 0;
	while (ml[i])
	{
		free(ml[i]);
		i++;
	}
	free(ml);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**ml;
	int		i;
	int		j;

	if (!s)
		return (0);
	ml = malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (ml == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < ft_countw(s, c))
	{
		if (s[i] != c)
		{
			ml[j] = ft_substr(s, i, ft_lencount(s + i, c));
			if (!ml[j])
				return (ft_free(ml));
			i = i + ft_lencount(s + i, c);
			j++;
		}
		i++;
	}
	ml[j] = NULL;
	return (ml);
}
