/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_animator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:08:39 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 16:10:24 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_animation(t_data *d)
{
	static int	i;
	void		*img;
	t_enemy		*tmp;

	tmp = d->enemy;
	while (tmp)
	{
		if (i >= 0 && i <= 100)
			img = mlx_xpm_file_to_image(d->mlx, "img/K.xpm", &d->i_w, &d->i_h);
		if (i >= 201 && i <= 200)
			img = mlx_xpm_file_to_image(d->mlx, "img/K0.xpm", &d->i_w, &d->i_h);
		if (i >= 201 && i <= 300)
			img = mlx_xpm_file_to_image(d->mlx, "img/K1.xpm", &d->i_w, &d->i_h);
		if (i >= 301 && i <= 400)
			img = mlx_xpm_file_to_image(d->mlx, "img/K2.xpm", &d->i_w, &d->i_h);
		if (i >= 401 && i <= 500)
			img = mlx_xpm_file_to_image(d->mlx, "img/K3.xpm", &d->i_w, &d->i_h);
		if (i == 500)
			i = 0;
		mlx_put_image_to_window(d->mlx, d->win, img, tmp->x * PX, tmp->y * PX);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

t_enemy	*ft_lstlast(t_enemy *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_enemy	*ft_lstnew(int x, int y)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == 0)
		return (0);
	enemy->x = x;
	enemy->y = y;
	enemy->next = NULL;
	return (enemy);
}

void	ft_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*lst1;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	lst1 = ft_lstlast(*lst);
	lst1->next = new;
}

void	loop_animator(t_data *d)
{
	t_enemy	*enemy;
	int		n;
	int		x;
	int		y;

	n = 1;
	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'K')
			{
				if (n++ == 1)
					enemy = ft_lstnew(x, y);
				else
					ft_lstadd_back(&enemy, ft_lstnew(x, y));
			}
			x++;
		}
		y++;
	}
	d->enemy = enemy;
	mlx_loop_hook(d->mlx, ft_animation, d);
}
