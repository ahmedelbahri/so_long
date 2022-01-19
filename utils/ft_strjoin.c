/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:40:52 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 16:59:23 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *tab, char *buffer)
{
	char	*al;
	size_t	i;
	size_t	j;

	if (!tab || !buffer)
		return (0);
	al = malloc(strlen(tab) + strlen(buffer) + 1);
	if (al == 0)
		return (0);
	i = 0;
	j = 0;
	while (i <= strlen(tab) + strlen(buffer))
	{
		while (i < strlen(tab))
		{
			al[i] = tab[i];
			i++;
		}
		al[i++] = buffer[j++];
	}
	al[i] = '\0';
	free(tab);
	free(buffer);
	return (al);
}
