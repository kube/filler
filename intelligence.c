/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intelligence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:13:11 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 19:11:45 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <filler.h>

// FOR TESTING
#include <stdio.h>

void				intelligence(t_env *env)
{
	t_player_area	*area1;
	t_player_area	*area2;

	(void)env;
	area1 = &env->areas[0];
	area2 = &env->areas[1];
	printf(	"Player 1 :\nX %d, Y %d\nWidth %d, Height %d\n",
			area1->x, area1->y, area1->width, area1->height);
	printf(	"Player 2 :\nX %d, Y %d\nWidth %d, Height %d\n",
			area2->x, area2->y, area2->width, area2->height);
}
