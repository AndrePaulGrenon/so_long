#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

# define XPM ".xpm"
# define P_TERRAIN "./assets/terrain/XPM/"
# define P_MOVE "./assets/princess_animation/XPM/"
# define P_COLLECT "./assets/collect_animation/XPM/"
# define P_TANK "./assets/tank_animation/XPM/"
# define P_MUSH "./assets/mushroom_animation/XPM/"
# define BUFF 20 

typedef struct	s_mov
{
	void	*img;
	void	*next;
	void	*idle;
	void	*collect;
	void	*mov;
}				t_movement;

typedef struct	s_assets
{
	int		x;
	int		y;
	int		len;
	char	*map;
	
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
}				t_assets;

char		*ft_join(char *str1, char *str2);
char		*nw_pth(char *PATH, char *xpm);
t_assets	*ft_init_xpm(void *screen);
void    	ft_put_grid(void *screen, void *window, t_assets *assets);
char		*ft_get_map(int fd);
void		ft_free_to_destroy(void *screen, t_assets *assets);
#endif
