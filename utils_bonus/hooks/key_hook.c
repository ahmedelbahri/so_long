/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:50:32 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 17:04:03 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_color(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < 15)
	{
		x = 0;
		while (x < 50)
		{
			mlx_pixel_put(d->mlx, d->win, 70 + x, d->w_h * PX + y, 0x000000);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_data *d)
{
	char	*m;

	if (keycode == 53 || keycode == 17)
		ft_free_map(d, "Exited Succesfully");
	if ((keycode == 0 || keycode == 123) && d->map[d->d_y][d->d_x - 1] != '1')
		ft_left(d);
	if ((keycode == 2 || keycode == 124) && d->map[d->d_y][d->d_x + 1] != '1')
		ft_right(d);
	if ((keycode == 13 || keycode == 126) && d->map[d->d_y - 1][d->d_x] != '1')
		ft_up(d);
	if ((keycode == 1 || keycode == 125) && d->map[d->d_y + 1][d->d_x] != '1')
		ft_down(d);
	m = ft_itoa(d->moves);
	ft_color(d);
	mlx_string_put(d->mlx, d->win, 70, d->w_h * PX - 4, C, m);
	return (0);
}
