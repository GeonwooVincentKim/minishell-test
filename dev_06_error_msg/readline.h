#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SINGLE_QUOTE_CHAR '\''

void						fatal_error(const char *msg) __attribute__((noreturn));

void						assert_error(const char *message);
void						fatal_error(const char *msg);

enum						e_token_kind
{
	TK_WORD,
	TK_RESERVED,
	TK_OP,
	TK_EOF,
};

typedef enum e_token_kind	t_token_kind;

typedef struct s_token		t_token;

struct						s_token
{
	t_token_kind			kind;
	char					*word;
	t_token					*next;
};

//main function 
t_token						*tokenizer(char *input_p);
int							ft_mlt_process(char *line);

//expand
void	expand(t_token *tok);

//utils
bool	is_metacharacter(char c);
