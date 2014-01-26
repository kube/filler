/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 13:38:04 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 23:26:15 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <filler.h>
#include <get_next_line.h>

static int				is_piece_case(char c)
{
	if (c == '.' || c == '*')
		return (1);
	return (0);
}

static void				get_piece_size(char *line, int *width, int *height)
{
	int					i;

	if (begins_with("Piece ", line))
	{
		i = 6;
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

static void				update_piece_shape_size(t_piece *piece, int x, int y)
{
	if (!piece->real_width)
	{
		piece->real_width = 1;
		piece->real_height = 1;
		piece->offset_x = x;
		piece->offset_y = y;
	}
	else
	{
		if (x < piece->offset_x)
		{
			piece->real_width += piece->offset_x - x;
			piece->offset_x = x;
		}
		else if (x >= piece->offset_x + piece->real_width)
			piece->real_width = x - piece->offset_x + 1;
		if (y < piece->offset_y)
		{
			piece->real_height += piece->offset_y - y;
			piece->offset_y = y;
		}
		else if (y >= piece->offset_y + piece->real_height)
			piece->real_height = y - piece->offset_y + 1;
	}
}

static int				*update_piece_line(	t_piece *piece, char *line, int y,
											int width)
{
	int					k;

	k = 0;
	while (is_piece_case(line[k]) && k < width)
	{
		if (line[k] == '*')
		{
			piece->piece[y][k] = 1;
			update_piece_shape_size(piece, k, y);
		}
		else
			piece->piece[y][k] = 0;
		k++;
	}
	if (line[k] != 0 || k != width)
		exit(1);
	return (0);
}

static void				get_piece_data(t_piece *piece, int width, int height)
{
	int					j;
	char				*line;
	int					gnl_result;

	j = 0;
	while (j < height)
	{
		if ((gnl_result = get_next_line(0, &line)) < 1)
			exit(1);
		update_piece_line(piece, line, j, width);
		free(line);
		j++;
	}
}

static void				create_piece(t_piece *piece, int width, int height)
{
	int					j;

	piece->real_width = 0;
	piece->real_height = 0;
	piece->piece = (int**)malloc(height * sizeof(piece->piece));
	piece->data = (int*)malloc(width * height * sizeof(piece->data));
	ft_bzero(piece->data, width * height);
	j = 0;
	while (j < height)
	{
		piece->piece[j] = piece->data + j * width;
		j++;
	}
}

t_piece				*get_piece()
{
	int				gnl_result;
	char			*line;
	t_piece			*piece;

	piece = (t_piece*)malloc(sizeof(t_piece));
	if ((gnl_result = get_next_line(0, &line)) > 0)
	{
		get_piece_size(line, &piece->width, &piece->height);
		free(line);
		create_piece(piece, piece->width, piece->height);
		get_piece_data(piece, piece->width, piece->height);
	}
	return (piece);
}
