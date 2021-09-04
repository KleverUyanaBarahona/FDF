/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 01:21:03 by klever            #+#    #+#             */
/*   Updated: 2021/09/05 01:27:18 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	check_map(char *file, t_fdf **fdf)
{
	char	*line;
	char	**words;
	int		fd;

	words = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1 || ft_strnstr(file, ".fdf", 4))
		p_error("Fail map");
	(*fdf)->map->y = 0;
	(*fdf)->map->x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		words = ft_split(line, ' ');
		//check_line_x(fdf, word_count(words));
		(*fdf)->map->y++;
		free(line);
		free_matrix(words);
	}
	free(line);
	close(fd);
}
