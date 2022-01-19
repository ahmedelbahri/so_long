/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:32:30 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 17:19:48 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_put_image(t_data *d)
{
	void			*img;
	static int		k;

	img = NULL;
	k = 0;
	if (d->map[d->x][d->y] == '1')
		img = mlx_xpm_file_to_image(d->mlx, "img/1.xpm", &d->i_w, &d->i_h);
	else if (d->map[d->x][d->y] == '0')
		img = mlx_xpm_file_to_image(d->mlx, "img/0.xpm", &d->i_w, &d->i_h);
	else if (d->map[d->x][d->y] == 'P')
		img = mlx_xpm_file_to_image(d->mlx, "img/P.xpm", &d->i_w, &d->i_h);
	else if (d->map[d->x][d->y] == 'C')
		img = mlx_xpm_file_to_image(d->mlx, "img/C.xpm", &d->i_w, &d->i_h);
	else if (d->map[d->x][d->y] == 'E')
		img = mlx_xpm_file_to_image(d->mlx, "img/E.xpm", &d->i_w, &d->i_h);
	else if (d->map[d->x][d->y] == 'K')
		img = mlx_xpm_file_to_image(d->mlx, "img/K.xpm", &d->i_w, &d->i_h);
	mlx_put_image_to_window(d->mlx, d->win, img, d->y * PX, d->x * PX);
	if (k == 0 && d->map[d->x][d->y] == 'K')
	{
		loop_animator(d);
		k++;
	}
}

void	put_to_win(t_data d)
{
	d.x = 0;
	while (d.map[d.x])
	{
		d.y = 0;
		while (d.map[d.x][d.y])
		{
			ft_put_image(&d);
			d.y++;
		}
		d.x++;
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
		d.win = mlx_new_window(d.mlx, d.w_w * PX, d.w_h * PX + 20, "new game");
		mlx_key_hook(d.win, key_hook, &d);
		mlx_hook(d.win, 17, 0, ft_close, &d);
		mlx_string_put(d.mlx, d.win, 5, d.w_h * PX - 4, C, "moves:");
		mlx_string_put(d.mlx, d.win, 70, d.w_h * PX - 4, C, ft_itoa(d.moves));
		put_to_win(d);
		mlx_loop(d.mlx);
	}
	return (0);
}
