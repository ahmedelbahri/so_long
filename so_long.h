/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:19:59 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/01/19 13:46:22 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define PX 50
# define C 0xFFFFFF

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**map;
	int		i_h;
	int		i_w;
	int		w_h;
	int		w_w;
	int		d_x;
	int		d_y;
	int		moves;
	int		c_count;
	char	*msg;
}				t_data;

char	**ft_map(char *map);
int		ft_strrchr_ber(char *str);
int		ft_arg_check(int argc, char **argv);
size_t	ft_strlen(char *s);
int		ft_lencmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_mapcheck(char **map);
int		key_hook(int keycode, t_data *d);
void	ft_down(t_data *d);
void	ft_free_map(t_data *d, char *msg);
void	ft_left(t_data *d);
void	ft_right(t_data *d);
void	ft_up(t_data *d);
int		key_hook(int keycode, t_data *d);
int		ft_close(t_data *d);
int		ft_strcmp(char *s1, char *s2);

#endif