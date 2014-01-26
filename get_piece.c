/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 13:38:04 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 17:12:44 by cfeijoo          ###   ########.fr       */
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

static int				*update_piece_line(char *line, int *piece_line, int width)
{
	int					k;

	k = 0;
	while (is_piece_case(line[k]) && k < width)
	{
		if (line[k] == '*')
			piece_line[k] = 1;
		else
			piece_line[k] = 0;
		k++;
	}
	if (line[k] != 0 || k != width)
		exit(1);
	return (0);
}

static int				**get_piece_data(int **piece, int width, int height)
{
	int					j;
	char				*line;
	int					gnl_result;

	j = 0;
	while (j < height)
	{
		if ((gnl_result = get_next_line(0, &line)) < 1)
			exit(1);
		update_piece_line(line, piece[j], width);
		free(line);
		j++;
	}
	return (piece);
}

static void				create_piece(t_piece *piece, int width, int height)
{
	int					j;

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
		get_piece_data(piece->piece, piece->width, piece->height);
	}
	return (piece);
}
