/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:09:16 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 19:25:19 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <filler.h>
#include <get_next_line.h>



// TO REMOVE
#include <stdio.h>


static int				is_board_case(char c)
{
	if (c == '.' || c == 'X' || c == 'x' || c == 'O' || c == 'o')
		return (1);
	return (0);
}

static void				update_player_area(t_player_area *area, int x, int y)
{
	if (!area->width)
	{
		area->width = 1;
		area->height = 1;
		area->x = x;
		area->y = y;
	}
	else
	{
		if (x < area->x)
		{
			printf("TOTO\n");
			area->width += area->x - x;
			area->x = x;
		}
		else if (x >= area->x + area->width)
			area->width = x - area->x + 1;
		if (y < area->y)
		{
			area->height += area->y - y;
			area->y = y;
		}
		else if (y >= area->y + area->height)
			area->height = y - area->y + 1;
	}
}

static void				update_board_case(t_env *env, int x, int y, int player)
{
	t_player_area		*area;

	env->board[y][x] = player;
	area = &env->areas[player - 1];
	update_player_area(area, x, y);
}

static int				*update_board_line(	t_env *env, char *line,
											int *board_line, int y)
{
	int					i;
	int					k;

	i = 0;
	while (!is_board_case(line[i]))
		i++;
	k = 0;
	while (is_board_case(line[i + k]) && k < env->width)
	{
		if (line[i + k] == 'O' || line[i + k] == 'o')
		{
			if (!board_line[k])
				update_board_case(env, k, y, 1);
		}
		else if (line[i + k] == 'X' || line[i + k] == 'x')
		{
			if (!board_line[k])
				update_board_case(env, k, y, 2);
		}
		k++;
	}
	if (line[i + k] != 0 || k != env->width)
		exit(1);
	return (0);
}

static void				update_board(t_env *env)
{
	int					j;
	char				*line;
	int					gnl_result;

	j = 0;
	while (j < env->height)
	{
		if ((gnl_result = get_next_line(0, &line)) < 1)
			exit(1);
		update_board_line(env, line, env->board[j], j);
		free(line);
		j++;
	}
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

static void				clear_piece(t_piece *piece)
{
	free(piece->data);
	free(piece->piece);
	free(piece);
}

void					game_loop(t_env *env)
{
	char				*line;
	int					gnl_result;

	while ((gnl_result = get_next_line(0, &line)) > 0)
	{
		if (env->board == NULL)
		{
			get_board_size(line, &env->width, &env->height);
			env->board = create_board(env->width, env->height);
		}
		free(line);
		get_next_line(0, &line);
		free(line);
		update_board(env);
		if (env->piece)
			clear_piece(env->piece);
		env->piece = get_piece();
		intelligence(env);
	}
}
