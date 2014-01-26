/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 00:34:25 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 01:05:35 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

void	game_loop(int player_number);
int		begins_with(char *s1, char *s2);

typedef struct						s_player_area
{
	int								x;
	int								y;
	int								width;
	int								height;
}									t_player_area;

typedef struct						s_area
{
	t_player_area					p1_area;
	t_player_area					p2_area;
}									t_area;

#endif
