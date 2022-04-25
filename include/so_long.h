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

# define EXIT 53
# define UP 13 
# define DOWN 1 
# define LEFT 0 
# define RIGHT 2

enum 
{
	PLAIN,
	PLAIN2,
	WALL,
	CHAMPI,
	P_PLAYER,
	EX,
};

typedef struct	s_vars
{
	void	*screen;
	void	*window;
}				t_vars;

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
	int		pos[30][24];
	int		n_mush;
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
	void	*road_left;
	void	*road_right;
	void	*road_main;
	t_mush	*mush;
	t_play	*player;
	t_vars	*vars;
}				t_assets;


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
void		ft_set_grass(t_assets *assets, void *screen, void *window);
void    	ft_put_grid(void *screen, void *window, t_assets *assets);
char		*ft_get_map(int fd);
void		ft_free_to_destroy(void *screen, t_assets *assets);
int			ft_close(int keycode, t_vars *vars);
int			ft_terminate(int keycode, t_vars *vars);
int			ft_key_hook(int keycode, t_assets *assets);
int			ft_render_next(void *assets);
#endif
