/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 00:34:25 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 19:02:06 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct						s_piece
{
	int								**piece;
	int								*data;
	int								offsetX;
	int								offsetY;
	int								width;
	int								height;
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

void	game_loop(t_env *env);
int		begins_with(char *s1, char *s2);
t_piece	*get_piece();
void	intelligence(t_env *env);

#endif
