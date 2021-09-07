/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:44:21 by kbarahon          #+#    #+#             */
/*   Updated: 2021/09/07 17:44:24 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_zoom(t_breshman *brs, t_fdf **fdf)
{
	brs->x1 *= (*fdf)->map->zoom;
	brs->x2 *= (*fdf)->map->zoom;
	brs->y1 *= (*fdf)->map->zoom;
	brs->y2 *= (*fdf)->map->zoom;
}

void	set_move(t_breshman *brs, t_fdf **fdf)
{
	brs->x1 += (*fdf)->cam->dir_x;
	brs->y1 += (*fdf)->cam->dir_y;
	brs->x2 += (*fdf)->cam->dir_x;
	brs->y2 += (*fdf)->cam->dir_y;
}

double	max_n(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
