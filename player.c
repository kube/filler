/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 23:00:20 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/26 17:19:47 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <get_next_line.h>
#include <filler.h>

static int			get_player_info(char **player_name)
{
	int				i;
	int				gnl_result;
	char			*line;

	gnl_result = get_next_line(0, &line);
	if (gnl_result > 0 && begins_with("$$$ exec p", line)
		&& ft_isdigit((int)line[10]))
	{
		i = 11;
		while (ft_isdigit((int)line[i]))
			i++;
		if (!begins_with(" : ", line + i))
			exit(1);
		*player_name = line + i + 3;
		return (ft_atoi(line + 10));
	}
	else
		exit(1);
	return (0);
}

int					main(void)
{
	t_env			*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->player_number = get_player_info(&env->player_name);
	env->board = NULL;
	env->piece = NULL;
	/* Need to initialize players areas */
	game_loop(env);
	return (0);
}
