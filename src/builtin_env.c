/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:30:02 by geonwkim          #+#    #+#             */
/*   Updated: 2024/09/08 19:18:20 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/builtin.h"
#include <stdio.h>

// if (cur->value)
// map_get(envmap, cur->name);
int	builtin_env(char **argv, t_map *envmap)
{
	t_item	*cur;

	(void)argv;
	cur = envmap->item_head.next;
	while (cur)
	{
		if (cur->value)
			printf("%s=%s\n", cur->name, cur->value);
		cur = cur->next;
	}
	printf("_=/usr/bin/env\n");
	return (0);
}
