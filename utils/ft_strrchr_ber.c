/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_ber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:44:48 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 16:59:29 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strrchr_ber(char *str)
{
	int		i;
	int		j;
	char	*s;

	s = ".ber";
	j = ft_strlen(s);
	i = ft_strlen(str);
	while (j >= 0 && i >= 0)
	{
		if (str[i] == s[j])
			j--;
		else
			return (0);
		i--;
	}
	return (1);
}
