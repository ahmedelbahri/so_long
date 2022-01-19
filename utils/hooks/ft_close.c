/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:13:45 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 17:00:03 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_close(t_data *d)
{
	d->msg = "Closed succesfully";
	ft_free_map(d, d->msg);
	exit(0);
	return (0);
}