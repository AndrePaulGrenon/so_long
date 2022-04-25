#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include "mlx.h"

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

typedef struct	s_vars
{
	void	*screen;
	void	*window;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_player
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

typedef struct	s_mush
{
	int		*x;
	int		*y;
	void	*img[17];
}				t_mush;

typedef struct	s_assets
{
	int		x;
	int		y;
	int		len;
	int		heigth;
	int		pos[40][64];
	int		n_mush;
	int		n_road;
	int		collected;
	char	*map;
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
	t_play	*player;
	t_vars	*vars;
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
int			ft_screen_size(t_assets *assets);
int			ft_open_map(char **argv, t_assets *assets);
int			ft_set_data(t_assets *assets, int *i, int *j);
void		ft_set_box(t_assets *assets, void *screen, void *window);
void		ft_set_player(t_assets *assets, void *screen, void *window);
void		ft_set_mush(t_assets *assets, void *screen, void *window);
void		ft_set_road(t_assets *assets, void *screen, void *window);
void		ft_set_grass(t_assets *assets, void *screen, void *window);
void    	ft_put_grid(void *screen, void *window, t_assets *assets);
void		ft_clean_behind(t_assets *assets, int dx, int dy);
char		*ft_get_map(int fd);
void		ft_free_to_destroy(void *screen, t_assets *assets);
int			ft_close(int keycode, t_vars *vars);
int			ft_terminate(int keycode, t_vars *vars);
int			ft_key_hook(int keycode, t_assets *assets);
int			ft_render_next(void *assets);
#endif
