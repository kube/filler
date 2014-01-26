/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intelligence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:13:11 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 23:35:50 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <filler.h>

static int			get_case(t_env *env, int x, int y)
{
	x = (x + env->width) % env->width;
	y = (y + env->height) % env->height;
	return (env->board[y][x]);
}

static int			can_place_piece(t_env *env, int x, int y)
{
	int				i;
	int				j;
	int				over;

	i = 0;
	j = 0;
	over = 0;
	if (x + env->piece->width > env->width || y + env->piece->height > env->height)
		return (0);
	while (j < env->piece->height)
	{
		i = 0;
		while (i < env->piece->width)
		{
			if (get_case(env, x + i, y + j) == env->player_number)
				over++;
			else if (get_case(env, x + i, y + j) == (env->player_number % 2) + 1)
				return (0);
			i++;
		}
		j++;
	}
	if (over == 1)
		return (1);
	return (0);
}

static int			try_place(t_env *env, int x, int y)
{
	int				offset_x;
	int				offset_y;

	offset_x = env->piece->offset_x + env->piece->real_width / 2;
	offset_y = env->piece->offset_y + env->piece->real_height / 2;
	if (can_place_piece(env, x - offset_x, y - offset_y))
	{
		ft_putnbr(x - offset_x);
		ft_putchar(' ');
		ft_putnbr(y - offset_y);
		ft_putendl("");
		return (1);
	}
	return (0);
}

static int			throw_ray(t_env *env, t_point center, float angle)
{
	float			cosa;
	float			sina;
	t_point			particle;

	particle.x = center.x;
	particle.y = center.y;
	sina = ft_sin(angle);
	cosa = ft_cos(angle);
	while (!((particle.x < 0 || particle.x > env->width)
		|| (particle.y < 0 || particle.y > env->width)))
	{
		particle.x += cosa;
		particle.y += sina;
	}
	while ((int)particle.x != (int)center.x && (int)particle.y != (int)center.y)
	{
		if (try_place(env, (int)particle.x, (int)particle.y))
			return (1);
		particle.x -= cosa;
		particle.y -= sina;
	}
	return (0);
}

int					intelligence(t_env *env)
{
	t_player_area	*area;
	t_point			center;
	float			angle;
	int				i;

	area = &env->areas[env->player_number - 1];
	center.x = (float)area->x + (float)area->width / 2;
	center.y = (float)area->y + (float)area->height / 2;
	i = 0;
	angle = ((float)(rand() % 360) * 3.14f) / 360;
	while (i < 360)
	{
		if (throw_ray(env, center, angle))
			return (1);
		angle += 3.14159265359 / 360;
		i++;
	}
	return (0);
}
