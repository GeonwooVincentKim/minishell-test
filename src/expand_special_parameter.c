/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_special_parameter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:08:49 by geonwkim          #+#    #+#             */
/*   Updated: 2024/08/03 23:52:04 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/readline.h"

bool	is_special_parameter(char *s)
{
	return (s[0] == '$' && s[1] == '?');
}

void	append_num(char **dest, unsigned int num)
{
	if (num == 0)
	{
		append_char(dest, '0');
		return ;
	}
	if (num / 10 != 0)
		append_num(dest, num / 10);
	append_char(dest, '0' + (num % 10));
}

// void	expand_special_parameter_str(
// 	char **dest, char **rest, char *p,
// 	unsigned int *last_status)
// {
// 	if (!is_special_parameter(p))
// 		assert_error("Expected special parameter");
// 	p += 2;
// 	append_num(dest, get_last_status(last_status));
// 	*rest = p;
// }

void	expand_special_parameter_str(char **dest, char **rest, char *p)
{
	if (!is_special_parameter(p))
		assert_error("Expected special parameter");
	p += 2;
	append_num(dest, last_status);
	*rest = p;
}