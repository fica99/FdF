/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:17:44 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 20:14:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handler(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 24)
		if (fdf->map->scale < INT_MAX)
			++fdf->map->scale;
	if (key == 27)
		if (fdf->map->scale > 1)
			--fdf->map->scale;
	key == 13 ? fdf->map->angle_x += 0.1 : 0;
	key == 1 ? fdf->map->angle_x -= 0.1 : 0;
	key == 0 ? fdf->map->angle_y -= 0.1 : 0;
	key == 2 ? fdf->map->angle_y += 0.1 : 0;
	if (key == 34)
	{
		fdf->map->proj_type = ISO;
		unset_angl(&fdf->map->angle_x, &fdf->map->angle_y, &fdf->map->angle_z);
	}
	if (key == 35)
	{
		fdf->map->proj_type = PARALLEL;
		unset_angl(&fdf->map->angle_x, &fdf->map->angle_y, &fdf->map->angle_z);
	}
	ft_bzero(fdf->mlx.data_addr, WIN_WIDTH * WIN_HEIGHT * 4);
	draw(fdf->map, &fdf->mlx);
}

void	close_window(t_fdf *fdf)
{
	(void)fdf;
	exit(EXIT_SUCCESS);
}