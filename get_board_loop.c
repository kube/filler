/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:09:16 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/25 19:02:28 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
static int				*get_board_line(char *line, int **board)
{
	char				*line;

	while ()
	{

	}

	return (0);
}

static int				**get_board(unsigned width, unsigned height)
{
	int					j;
	int					**board;
	char				*line;

	j = 0;
	while ((gnl_result = get_next_line(0, &line)) > 0)
	{
		get_board_line(line, board);
		j++;
	}
	return (board);
}


static void				get_board_size(unsigned int *width, unsigned int *height)
{
	char				*line;
	int					i;

	gnl_result = get_next_line(0, &line);
	if (gnl_result > 0 && begins_with("Plateau ", line))
	{
		i = 8;
		if (!(*width = ft_atoi(line + i)))
			exit (1);
		while (ft_isdigit((int)line[i]))
			i++;
		if (!begins_with(" ", line + i))
			exit(1);
		i++;
		*height = ft_atoi(line + i + 3);
		if (!(*height = ft_atoi(line + i)))
			exit (1);
		while (ft_isdigit((int)line[i]))
			i++;
		if (!begins_with(":", line + i))
			exit(1);
	}
	else
		exit(1);
}

void					game_loop(int player_number, char *player_name)
{
	unsigned int		*width;
	unsigned int		*height;
	int					**board;
	char				*line;

	board = NULL;
	while ((gnl_result = get_next_line(0, &line)) > 0)
	{
		get_board_size(width, height);
		board = get_board();
	}
}
