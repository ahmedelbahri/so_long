/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:50:32 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 17:04:17 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_hook(int keycode, t_data *d)
{
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
	return (0);
}
