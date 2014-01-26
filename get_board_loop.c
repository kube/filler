/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:09:16 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 01:05:27 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <filler.h>
#include <get_next_line.h>

static int				is_board_case(char c)
{
	if (c == '.' || c == 'X' || c == 'x' || c == 'O' || c == 'o')
		return (1);
	return (0);
}

static int				*update_board_line(char *line, int *board_line, int width)
{
	int					i;
	int					k;

	i = 0;
	while (!is_board_case(line[i]))
		i++;
	k = 0;
	while (is_board_case(line[i + k]) && k < width)
	{
		if (line[i + k] == 'O' || line[i + k] == 'o')
			board_line[k] = 1;
		else if (line[i + k] == 'X' || line[i + k] == 'x')
			board_line[k] = 2;
		k++;
	}
	if (line[i] != 0 || k != width)
	{
		ft_putnbr(k);
		ft_putendl(" ERROR HERE!");
		exit(1);
	}
	return (0);
}

static int				**update_board(int **board, int width, int height)
{
	int					j;
	char				*line;
	int					gnl_result;

	j = 0;
	while (j < height)
	{
		if ((gnl_result = get_next_line(0, &line)) < 1)
			exit(1);
		update_board_line(line, board[j], width);
		free(line);
		j++;
	}
	return (board);
}

static void				get_board_size(char *line, int *width, int *height)
{
	int					i;

	if (begins_with("Plateau ", line))
	{
		i = 8;
		if (!(*height = ft_atoi(line + i)))
			exit(1);
		while (ft_isdigit((int)line[i]))
			i++;
		if (!begins_with(" ", line + i))
			exit(1);
		i++;
		if (!(*width = ft_atoi(line + i)))
			exit (1);
		while (ft_isdigit((int)line[i]))
			i++;
		if (!begins_with(":", line + i))
			exit(1);
	}
	else
		exit(1);
}

static int				**create_board(int width, int height)
{
	int					j;
	int					**board;
	int					*data;

	board = (int**)malloc(height * sizeof(*board));
	data = (int*)malloc(width * height * sizeof(*data));
	ft_bzero(data, width * height);
	j = 0;
	while (j < height)
	{
		board[j] = data + j * width;
		j++;
	}
	return (board);
}



/*
**	FOR TESTS ONLY !
*/

static void				TEST_display_board(int **board, int width, int height)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (j < height)
	{
		while (i < width)
		{
			ft_putchar(board[j][i] + '0');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}



void					game_loop(int player_number)
{
	int					width;
	int					height;
	int					**board;
	char				*line;
	int					gnl_result;

	(void)player_number;

	board = NULL;
	while ((gnl_result = get_next_line(0, &line)) > 0)
	{
		if (board == NULL)
		{
			get_board_size(line, &width, &height);
			board = create_board(width, height);
		}
		free(line);
		get_next_line(0, &line);
		free(line);
		board = update_board(board, width, height);
		free(line);

		TEST_display_board(board, width, height);
	}
}
