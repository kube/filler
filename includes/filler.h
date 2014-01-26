/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 00:34:25 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 23:25:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct						s_point
{
	float							x;
	float							y;
}									t_point;

typedef struct						s_piece
{
	int								**piece;
	int								*data;
	int								offset_x;
	int								offset_y;
	int								width;
	int								height;
	int								real_width;
	int								real_height;
}									t_piece;

typedef struct						s_player_area
{
	int								x;
	int								y;
	int								width;
	int								height;
}									t_player_area;

typedef struct						s_env
{
	int								player_number;
	char							*player_name;
	int								**board;
	int								width;
	int								height;
	t_piece							*piece;
	t_player_area					areas[2];
}									t_env;

int			begins_with(char *s1, char *s2);
void		game_loop(t_env *env);
t_piece		*get_piece();
int			intelligence(t_env *env);

#endif
