/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:30:36 by klever            #+#    #+#             */
/*   Updated: 2021/09/06 00:18:06 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"



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
