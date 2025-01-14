/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:29:02 by geonwkim          #+#    #+#             */
/*   Updated: 2024/08/28 22:06:44 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	ft_do_command(char *line)
// {
// 	char	**argv;
// 	char	*command_path;
// 	t_token	*token;

// 	token = tokenizer(line);
// 	expand(token);
// 	argv = token_to_argv(token);
// 	command_path = find_path(argv[0]);
// 	if (!command_path)
// 	{
// 		perror("command not found");
// 		exit(1);
// 	}
// 	if (ve(command_path, argv, environ) < 0)
// 	{
// 		perror("execve");
// 		exit(1);
// 	}
// }

// int	ft_mlt_process(char *line)
// {
// 	int	pid;
// 	int	status;

// 	status = -1;
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	if (pid > 0)
// 	{
// 		if (wait(&status) < 0)
// 		{
// 			perror("wait");
// 			exit(1);
// 		}
// 	}
// 	else
// 		ft_do_command(line);
// 	return (status);
// }
