/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:14:45 by klever            #+#    #+#             */
/*   Updated: 2021/09/06 00:16:30 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line_bonus.h"
# include "../srcs/minilibx/mlx.h"
# include <math.h>

# define KEY_UP					13
# define KEY_DOWN				1
# define KEY_RIGHT				2
# define KEY_LEFT				0

# define KEY_UP_ZOOM			126
# define KEY_DOWM_ZOOM			125
# define KEY_RIGHT_VISION		124
# define KEY_LEFT_VISION		123
# define KEY_PLANE_VISION		35
# define KEY_ISO_VISION			34
# define KEY_ANGLE_Q_VISION		12
# define KEY_ANGLE_E_VISION		14
# define KEY_UNIVER_VISION		49
# define KEY_ELE_C_VISION		8
# define KEY_ELE_X_VISION		7
# define KEY_SCREEN_SHOT		40

# define ESC					53

/* Struct data map */
typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	int				winx;
	int				winy;
	int				color;
	int				arg;
}					t_data;

typedef struct s_map
{
	int			**color;
	int			**table;
	int			x;
	int			y;
	double		zoom;
	double		eleva;
}				t_map;

typedef struct s_breshman
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		x_step;
	double		y_step;
	double		i;
	double		j;	
}				t_breshman;

typedef struct s_aux_map
{
	char	*line;
	char	**val;
	char	**color;
	int		fd;
	int		x;
	int		y;
}			t_aux_map;

typedef struct s_keycode
{
	int				w;
	int				s;
	int				d;
	int				a;
	int				rr;
	int				rl;
	int				zu;
	int				zd;
	int				p;
	int				i;
	int				q;
	int				e;
	int				sp;
	int				c;
	int				x;

	int				esc;
}					t_keycode;

typedef struct s_cam
{
	t_keycode		*keycode;
	int				dir_x;
	int				dir_y;
	double			angle;
	double			rotspeed;
	int				plane;	
}				t_cam;

/* Data center */

typedef struct s_fdf
{
	t_map		*map;
	t_data		*data;
	t_cam		*cam;
	double		lst_x;
	double		lst_y;
}				t_fdf;

/* Utils*/
void	p_error(char *s);
void	free_matrix(char **matrix);
int		str_hexa_to_int(char *str);

/* start */
void	set_var(t_fdf	**fdf);
void	fill_check(t_fdf **fdf, char *str);
void	create_windows(t_fdf **fdf);

/* Map */
int		word_count(char **str);
void	check_map(char *file, t_fdf **fdf);
void	fiil_map(char *file, t_fdf **fdf);

#endif