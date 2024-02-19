/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:25 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/19 12:01:23 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_env(char **envp)
{
	const char	*env;
	char		*val_va;
	int			i;

	env = "USER";
	val_va = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}

void	start_game(t_game *game)
{
	init_game_data(game);
	check_map(game->av[1], game);
	init_window(game);
	check_window(game);
	init_sprites(game);
	draw_map(game);
	mlx_hook(game->window, DESTROY_NOTIF, NO_EVENT_MASK, red_cross, game);
	mlx_key_hook(game->window, key_handler, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av, char **nv)
{
	t_game	game;

	if (!check_env(nv))
		display_errors(ENV);
	if (ac == 1)
		display_errors(ARG_ERROR1);
	if (ac > 2)
		display_errors(ARG_ERROR2);
	init_game(&game, av);
	start_game(&game);
}
