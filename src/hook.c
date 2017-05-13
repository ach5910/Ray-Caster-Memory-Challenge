/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <ach5910@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:02:32 by ahunt             #+#    #+#             */
/*   Updated: 2017/05/12 11:02:45 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		expose_hook(t_env *e)
{
	redraw_game(e);
	return (0);
}

int		exit_hook(t_env *e)
{
	free_environment(e);
	free_image(e);
	ft_memdel((void **)&e);
	exit(EXIT_SUCCESS);
	return (0); 
}
