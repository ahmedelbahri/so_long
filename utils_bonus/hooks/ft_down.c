/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:34:33 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/17 21:19:33 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_lost_down(t_data *d)
{
	d->msg = "You lost!!";
	(d->moves)++;
	printf("moves %d\n", d->moves);
	ft_free_map(d, d->msg);
}

void	ft_exit_down(t_data *d)
{
	d->msg = "You won!!";
	(d->moves)++;
	printf("moves %d\n", d->moves);
	ft_free_map(d, d->msg);
}

void	ft_down(t_data *d)
{
	void	*img;

	if (d->map[d->d_y + 1][d->d_x] == 'K')
		ft_lost_down(d);
	else if (d->map[d->d_y + 1][d->d_x] == 'E' && d->c_count == 0)
		ft_exit_down(d);
	else if (d->map[d->d_y + 1][d->d_x] != 'E')
	{
		if (d->map[d->d_y + 1][d->d_x] == 'C' && d->c_count > 0)
			(d->c_count)--;
		d->map[d->d_y + 1][d->d_x] = '0';
		img = mlx_xpm_file_to_image(d->mlx, "img/0.xpm", &d->i_w, &d->i_h);
		mlx_put_image_to_window(d->mlx, d->win, img, d->d_x * PX, d->d_y * PX);
		(d->d_y)++;
		img = mlx_xpm_file_to_image(d->mlx, "img/down.xpm", &d->i_w, &d->i_h);
		mlx_put_image_to_window(d->mlx, d->win, img, d->d_x * PX, d->d_y * PX);
		(d->moves)++;
		printf("moves %d\n", d->moves);
	}
}
