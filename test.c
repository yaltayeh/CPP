#include <stdio.h>

void	handle_bracket(char *s)
{
	int		nb_brackets;
	int		last_status;
	char	*open_br[2];
	char	*close_br[2];
	char	*p;

	p = s;
	nb_brackets = 0;
	last_status = 0;
	open_br[0] = NULL;
	open_br[1] = NULL;
	close_br[0] = NULL;
	close_br[1] = NULL;
	while (*p)
	{
		if (*p == '(')
			nb_brackets++;
		else if (*p == ')')
			nb_brackets--;
		if (last_status < 0 && last_status < nb_brackets)
		{
			printf("%s | %s: %d, %d\n", open_br[0], open_br[1], last_status, nb_brackets);
		}
		if (*p == '(')
			open_br[1] = p;
		else if (*p == ')')
			close_br[1] = p;
		if (*p == '(' && !open_br[0])
			open_br[0] = p;
		else if (*p == ')' && !close_br[0])
			close_br[0] = p;
		p++;
		last_status = nb_brackets;
	}
	if (nb_brackets < 0)
		printf("%s | %s: %d, %d ----\n", open_br[1], close_br[0], last_status, nb_brackets);

	if (nb_brackets > 0)
		printf("%s | %s: %d, %d ----\n", open_br[0], close_br[1], last_status, nb_brackets);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	handle_bracket(argv[1]);
}