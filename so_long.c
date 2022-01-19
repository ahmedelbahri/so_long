/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:32:30 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/18 16:44:09 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapdim(t_data *d)
{
	d->w_h = 0;
	while (d->map[d->w_h])
	{
		d->w_w = 0;
		while (d->map[d->w_h][d->w_w])
			(d->w_w)++;
		(d->w_h)++;
	}
}

void	ft_put_image(t_data d, int x, int y)
{
	void	*img;

	img = NULL;
	if (d.map[x][y] == '1')
		img = mlx_xpm_file_to_image(d.mlx, "img/1.xpm", &d.i_w, &d.i_h);
	else if (d.map[x][y] == '0')
		img = mlx_xpm_file_to_image(d.mlx, "img/0.xpm", &d.i_w, &d.i_h);
	else if (d.map[x][y] == 'P')
		img = mlx_xpm_file_to_image(d.mlx, "img/P.xpm", &d.i_w, &d.i_h);
	else if (d.map[x][y] == 'C')
		img = mlx_xpm_file_to_image(d.mlx, "img/C.xpm", &d.i_w, &d.i_h);
	else if (d.map[x][y] == 'E')
		img = mlx_xpm_file_to_image(d.mlx, "img/E.xpm", &d.i_w, &d.i_h);
	mlx_put_image_to_window(d.mlx, d.win, img, y * PX, x * PX);
}

void	put_to_win(t_data d)
{
	int		x;
	int		y;

	x = 0;
	while (d.map[x])
	{
		y = 0;
		while (d.map[x][y])
		{
			ft_put_image(d, x, y);
			y++;
		}
		x++;
	}
}

void	get_x_y_c(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == 'P')
			{
				d->d_y = i;
				d->d_x = j;
			}
			if (d->map[i][j] == 'C')
				(d->c_count)++;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (ft_arg_check(argc, argv) == 1)
		return (0);
	d.map = ft_map(argv[1]);
	if (d.map == 0)
		return (0);
	d.moves = 0;
	get_x_y_c(&d);
	if (ft_mapcheck(d.map) == 0)
	{
		ft_mapdim(&d);
		d.mlx = mlx_init();
		d.win = mlx_new_window(d.mlx, d.w_w * PX, d.w_h * PX, "new game");
		mlx_key_hook(d.win, key_hook, &d);
		mlx_hook(d.win, 17, 0, ft_close, &d);
		put_to_win(d);
		mlx_loop(d.mlx);
	}
	return (0);
}
