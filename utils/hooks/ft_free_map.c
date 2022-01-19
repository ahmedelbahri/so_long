/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:35:47 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 17:00:29 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free_map(t_data *d, char *msg)
{
	int	x;

	x = 0;
	if (ft_strcmp(msg, "Closed succesfully") != 0)
		mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
	while (d->map[x])
	{
		free(d->map[x]);
		x++;
	}
	printf("%s", msg);
	free(d->map);
	exit(0);
}
