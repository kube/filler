/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:09:16 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/24 14:27:59 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			*get_board_line(char *line, int **board)
{
	char			*line;

	while ()
	{

	}

	return (0);
}

static int			**get_board()
{
	int				j;
	int				**board;
	char			*line;

	j = 0;
	while ((gnl_result = get_next_line(0, &line)) > 0)
	{
		get_board_line(line, board);
		j++;
	}
	return (board);
}

void					game_loop(int player_number, char *player_name)
{
	while ()
	{
		get_grid_size;

		
	}
}
