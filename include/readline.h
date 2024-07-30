/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:04:25 by geonwkim          #+#    #+#             */
/*   Updated: 2024/07/30 19:27:25 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "error.h"
# include "../libft/libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>

/* Tokenizer Enumeration */
typedef struct s_token		t_token;
enum	e_token_kind
{
	TK_WORD,
	TK_RESERVED,
	TK_OP,
	TK_EOF,
};
typedef enum e_token_kind	t_token_kind;

/* Struct for Tokenizer */
struct						s_token
{
	t_token_kind			kind;
	char					*word;
	t_token					*next;
};

enum	e_node_kind
{
	ND_SIMPLE_CMD,
	ND_REDIR_OUT
};
typedef enum e_node_kind	t_node_kind;

/* 
	Struct for Node
	Redirecting output example
	- comamnd: "echo hello 1 > out"
	- target_fd: 1
	- file_name: "out"
	- file_fd: open("out")
	- stashed_target_fd: dup(target_fd)
*/
typedef struct s_node		t_node;
struct						s_node
{
	t_token					*args;
	t_node					*redirects;
	t_token					*file_name;
	t_node_kind				kind;
	t_node					*next;
	int						target_fd;
	int						file_fd;
	int						stashed_target_fd;
};

# define ERROR_PARSE 258

// Environment
extern char					**environ;

/* Quotes */
# define SINGLE_QUOTE_CHAR '\''
# define DOUBLE_QUOTE_CHAR '"'
# define TK_WORD 1
# define TK_GREATER 2

/* Tokenizer Quotes */
void	skip_single_quote(char **line);
void	skip_double_quote(char **line);

/* Tokenizer Utils */
bool	is_blank(char c);
bool	is_metacharacter(char c);
bool	operators_cmp(char *str, char *key_op);
bool	is_control_operator(char *input_p);
bool	is_word(char *s);
bool	consume_blank(char **rest, char *line);

/* Tokenizer Redirection */
bool	is_redirection_operator(const char *s);

/* Error */
// void	fatal_error(const char *msg) __attribute__((noreturn));
// void	assert_error(const char *message);
// void	fatal_error(const char *msg);

/* tokenizer.c */
// t_token	*new_token(char *word, t_token_kind kind, t_token *current);
t_token	*new_token(char *word, t_token_kind kind);
// t_token	*operator(t_token *current, char **input_p);
t_token	*operator(char **rest, char *line);
// t_token	*word(t_token *current, char **input_p);
t_token	*word(char **rest, char *line);
t_token	*tokenizer(char *input_p);

/* destructor.c */
void	free_node(t_node *node);
void	free_token(t_token *token);
void	free_argv(char **argv);

/* do_command.c */
char	*abs_path_get(void);
char	*check_path(char *abs_path, const char *line);
char	*find_path(const char *line);
char	**subsequent_argv_recursive(t_token *tok, int nargs, char **argv);
char	**token_to_argv(t_token *tok);

/* do_command_utils.c */
// void	ft_do_command(char *line);
// int		ft_mlt_process(char *line);

/* expand.c */
void	append_char(char **s, char c);
void	remove_quote(t_token *token);
void	expand_quote_removal(t_node *node);
void	expand(t_node *token);

/* expand_quote.c */
void	remove_single_quote(char **dst, char **rest, char *p);
void	remove_double_quote(char **dst, char **rest, char *p);

/* parse.c */
t_node	*parse(t_token *token);
bool	at_eof(t_token *token);
t_node	*new_node(t_node_kind kind);
t_token	*token_dup(t_token *token);
void	append_token(t_token **token, t_token *element);

/* parse_command.c */
bool	equal_op(t_token *tok, char *op);
t_node	*redirect_out(t_token **rest, t_token *tok);
void	append_commend_element(t_node *command, t_token **rest, t_token *token);
void	append_node(t_node **node, t_node *element);

/* redirect.c */
int		stashfd(int fd);
void	open_redir_file(t_node *redir);
void	do_redirect(t_node *redir);
void	reset_redirect(t_node *redir);

#endif
