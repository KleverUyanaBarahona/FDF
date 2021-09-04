/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 00:51:03 by klever            #+#    #+#             */
/*   Updated: 2021/09/05 01:27:16 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_var(t_fdf	**fdf)
{
	(*fdf)->cam->keycode->w = 0;
	(*fdf)->cam->keycode->a = 0;
	(*fdf)->cam->keycode->s = 0;
	(*fdf)->cam->keycode->d = 0;
	(*fdf)->cam->keycode->zu = 0;
	(*fdf)->cam->keycode->zd = 0;
	(*fdf)->cam->keycode->rr = 0;
	(*fdf)->cam->keycode->rl = 0;
	(*fdf)->cam->keycode->p = 0;
	(*fdf)->cam->keycode->i = 0;
	(*fdf)->cam->keycode->sp = 0;
	(*fdf)->cam->rotspeed = 0.8;
	(*fdf)->cam->keycode->e = 0;
	(*fdf)->cam->keycode->q = 0;
	(*fdf)->cam->keycode->c = 0;
	(*fdf)->cam->plane = 0;
	(*fdf)->map->eleva = 1;
	(*fdf)->cam->keycode->x = 0;
	(*fdf)->cam->keycode->esc = 0;
	(*fdf)->map->zoom = 20;
}

void	fill_check(t_fdf **fdf, char *str)
{
	check_map(str, fdf);
	//fiil_map(str, fdf);
}
