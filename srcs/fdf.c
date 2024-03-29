/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:55:47 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/12 20:36:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pr_error(char *err_msg)
{
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	char	*name;

	if (argc != 2)
		pr_error("Usage : ./fdf <filename>\n");
	if (!(name = ft_strrchr(argv[1], '/')))
		name = argv[1];
	else
		++name;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		pr_error("Open error");
	read_map(fd, &map);
	if ((close(fd)) < 0)
		pr_error("Close error");
	draw_space(&map, name);
	exit(EXIT_SUCCESS);
}
