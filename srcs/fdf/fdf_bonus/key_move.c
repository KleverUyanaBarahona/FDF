/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:54:09 by kbarahon          #+#    #+#             */
/*   Updated: 2021/09/08 13:59:01 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdf.h"

static void	key_move_two(t_fdf **fdf)
{
	if ((*fdf)->cam->keycode->p == 1)
		(*fdf)->cam->plane = 1;
	if ((*fdf)->cam->keycode->i == 1)
		(*fdf)->cam->plane = 0;
	if ((*fdf)->cam->keycode->q == 1)
		(*fdf)->cam->angle -= 0.5;
	if ((*fdf)->cam->keycode->e == 1)
		(*fdf)->cam->angle += 0.5;
	if ((*fdf)->cam->keycode->c == 1)
		(*fdf)->map->eleva += 0.5;
	if ((*fdf)->cam->keycode->x == 1)
		(*fdf)->map->eleva -= 0.5;
	if ((*fdf)->cam->keycode->esc == 1)
	{
		write(1, "\n\x1b[36m[you have pressed the esc key!]\n", 38);
		mlx_clear_window((*fdf)->data->mlx, (*fdf)->data->win);
		mlx_destroy_window((*fdf)->data->mlx, (*fdf)->data->win);
		exit(0);
	}
}

int	key_move(t_fdf **fdf)
{
	if ((*fdf)->cam->keycode->s == 1)
		(*fdf)->cam->dir_y += 50;
	if ((*fdf)->cam->keycode->w == 1)
		(*fdf)->cam->dir_y -= 50;
	if ((*fdf)->cam->keycode->a == 1)
		(*fdf)->cam->dir_x -= 50;
	if ((*fdf)->cam->keycode->d == 1)
		(*fdf)->cam->dir_x += 50;
	if ((*fdf)->cam->keycode->zu == 1)
		(*fdf)->map->zoom += 0.5;
	if ((*fdf)->cam->keycode->zd == 1 && (*fdf)->map->zoom > 0.5)
		(*fdf)->map->zoom -= 0.5;
	if ((*fdf)->cam->keycode->rl == 1)
		(*fdf)->cam->rotspeed -= 0.2;
	if ((*fdf)->cam->keycode->rr == 1)
		(*fdf)->cam->rotspeed += 0.2;
	key_move_two(fdf);
	return (0);
}
