/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:49:40 by kbarahon          #+#    #+#             */
/*   Updated: 2021/09/06 19:01:17 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	set_pixel(t_breshman *brs, t_fdf **fdf)
{
	if (brs->j < (*fdf)->map->x - 1)
	{
		brs->x1 = brs->j;
		brs->y1 = brs->i;
		brs->y2 = brs->i;
		brs->x2 = (brs->x1 + 1);
		bresenham(brs, fdf);
	}
	if (brs->i < (*fdf)->map->y - 1)
	{
		brs->x1 = brs->j;
		brs->y1 = brs->i;
		brs->x2 = brs->j;
		brs->y2 = (brs->y1 + 1);
		bresenham(brs, fdf);
	}
}

void	draw(t_fdf **fdf)
{
	t_breshman	brs;

	brs.i = 0;
	while (brs.i < (*fdf)->map->y)
	{
		brs.j = 0;
		while (brs.j < (*fdf)->map->x)
		{	
			set_pixel(&brs, fdf);
			brs.j++;
		}
		brs.i++;
	}
}