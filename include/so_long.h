/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:43:02 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/06 17:29:15 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include "mlx.h"

# define TITLE "Pricess Mushroom in eastern Europe"
# define XPM ".xpm"
# define P_TERRAIN "./assets/terrain/XPM/"
# define P_MOVE "./assets/princess_animation/XPM/"
# define P_COLLECT "./assets/collect_animation/XPM/"
# define P_TANK "./assets/tank_animation/XPM/"
# define P_MUSH "./assets/mushroom_animation/XPM/"
# define BUFF 20 

enum
{
	LEFT,
	DOWN,
	RIGHT,
	UP = 13,
	EXIT = 53,
	PLAIN = 0,
	PLAIN2,
	L_ROAD,
	ROAD,
	R_ROAD,
	CHAMPI,
	P_PLAYER,
	WALL,
	EX,
};

typedef struct s_vars
{
	void	*screen;
	void	*window;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_tank
{
	int		xt[10];
	int		yt[10];
	int		speed[10];
	bool	is_right[10];
	void	*rig[8];
}				t_tank;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	bool	is_right;
	void	*left;
	void	*right;
	void	*left_mush;
	void	*right_mush;
	void	*left_move[3];
	void	*right_move[3];
	void	*left_collect[11];
	void	*right_collect[11];
}				t_play;

typedef struct s_mush
{
	int		*x;
	int		*y;
	void	*img[17];
}				t_mush;

typedef struct s_exit
{
	int		x;
	int		y;
}				t_exit;

typedef struct s_assets
{
	int		x;
	int		y;
	int		len;
	int		heigth;
	int		pos[64][40];
	int		n_mush;
	int		no_mush;
	int		n_road;
	int		n_tank;
	int		collected;
	char	*map;
	bool	victory;
	bool	dead;
	bool	show_it;
	bool	cant_move;
	bool	collects;
	void	*grass[3];
	void	*rock_left;
	void	*rock_right;
	void	*rock_line;
	void	*rock_column;
	void	*tree;
	void	*tent;
	void	*supplies;
	void	*l_road;
	void	*r_road;
	void	*road;
	t_mush	*mush;
	t_tank	*tank;
	t_play	*player;
	t_vars	*vars;
	t_exit	*exit;
}				t_assets;

char		*ft_itoa(int n);
void		ft_mini_ui(t_assets *assets);
char		*ft_join(char *str1, char *str2);
char		*nw_pth(char *PATH, char *xpm);
int			ft_check_ber(char **argv);
int			ft_strlen(char *str);
void		ft_putnbr_fd(int n, int fd);
void		ft_print_moves(t_assets *assets);
t_assets	*ft_init_xpm(void *screen);
void		ft_init_struct(t_assets *assets);
void		*ft_prep_assets(void *scrn, char *PTH, char *fl);
int			ft_screen_size(t_assets *assets);
int			ft_open_map(char **argv, t_assets *assets);
void		ft_init_tank_speed(t_assets *assets);
void		ft_terrain(t_assets *assets, void *screen);
int			ft_set_data(t_assets *assets, int *i, int *j);
void		ft_set_box(t_assets *assets, void *screen, void *window);
void		ft_set_player(t_assets *assets, void *screen, void *window);
void		ft_set_mush(t_assets *assets, void *screen, void *window);
void		ft_set_road(t_assets *assets, void *screen, void *window);
void		ft_set_tank(t_assets *assets, void *scre, void *win);
void		ft_set_exit(t_assets *assets, void *screen, void *window);
void		ft_set_grass(t_assets *assets, void *screen, void *window);
void		ft_put_grid(void *screen, void *window, t_assets *assets);
void		ft_tile_select(t_assets *assets, void *scre, void *win, int i);
void		ft_show_it(t_assets *assets, int x, int y, int pos);
void		ft_clean_message(t_assets *assets);
void		ft_init_tank_speed(t_assets *assets);
void		ft_anim_tank(t_assets *assets);
void		ft_delete_shrooms(t_assets *assets, int x, int y);
void		ft_exit(t_assets *assets);
void		ft_clean_behind(t_assets *assets, int dx, int dy);
char		*ft_get_map(int fd);
void		ft_free_to_destroy(void *screen, t_assets *assets);
int			ft_close(int keycode, t_vars *vars);
int			ft_terminate(int keycode, t_vars *vars);
void		ft_move(t_assets *assets, int dx, int dy);
int			ft_key_hook(int keycode, t_assets *assets);
int			ft_render_next(void *assets);
#endif
