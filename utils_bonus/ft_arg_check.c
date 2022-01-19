/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:00:21 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/17 21:18:55 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_arg_check(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Too few arguments for function call.");
		return (1);
	}
	if (argc > 2)
	{
		printf("Too many arguents for function call.");
		return (1);
	}
	if (ft_strrchr_ber(argv[1]) == 0)
	{
		printf("Map file shoulde be .ber");
		return (1);
	}
	return (0);
}
