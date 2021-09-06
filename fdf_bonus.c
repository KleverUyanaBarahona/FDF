/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:30:36 by klever            #+#    #+#             */
/*   Updated: 2021/09/06 14:09:07 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	loop_fdf(t_fdf **fdf)
{
	//draw(fdf);
	mlx_put_image_to_window((*fdf)->data->mlx,
		(*fdf)->data->win, (*fdf)->data->img, 0, 0);
	//print_menu(fdf);
	//mlx_hook((*fdf)->data->win, 2, (1L << 0), ft_keypress, fdf);
	//mlx_hook((*fdf)->data->win, 3, (1L << 0), ft_keyrelease, fdf);
	mlx_hook((*fdf)->data->win, 17, (17L << 0), ft_exit, fdf);
	mlx_loop((*fdf)->data->mlx);
}

int	main(int argc, char *argv[])
{
	t_keycode	keycode;
	t_fdf		*fdf;
	t_map		map;
	t_data		data;
	t_cam		cam;

	if (argc != 2)
		p_error("Usage : ./test_maps/fdf <filename>");
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		p_error("Fail malloc");
	fdf->map = &map;
	fdf->cam = &cam;
	fdf->cam->keycode = &keycode;
	fdf->data = &data;
	fdf->data->winx = 2048;
	fdf->data->winy = 1080;
	set_var(&fdf);
	fill_check(&fdf, argv[1]);
	create_windows(&fdf);
	//loop_fdf(&fdf);
	return (0);
}
