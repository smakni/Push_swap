
#include <push_swap.h>

int		check_pile_a(s_pile *tab)
{
	int i;

	i = tab->la - 1;
	while (i > 0)
	{
		if (tab->a[i] < tab->a[i - 1])
			i--;
		else
			return (-1);
	}
	return (0);
}

int		check_pile_b(s_pile *tab)
{
	int i;

	i = tab->lb - 1;
	while (i > 0)
	{
		if (tab->b[i] > tab->b[i - 1])
			i--;
		else
			return (-1);
	}
	return (0);
}
