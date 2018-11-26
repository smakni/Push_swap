#include <push_swap.h>

void	ft_swap_p(s_pile *tab, char *line)
{
	if (line[1] == 's')
		tab->ret = ft_memjoin(tab->ret, "ss\n", ft_strlen(tab->ret), 3);
	else if (line[1] == 'a')
		tab->ret = ft_memjoin(tab->ret, "sa\n", ft_strlen(tab->ret), 3);
	else if (line[1] == 'b')
		tab->ret = ft_memjoin(tab->ret, "sb\n", ft_strlen(tab->ret), 3);
}

void	ft_push_p(s_pile *tab, char *line)
{
	if (line[1] == 'a')
		tab->ret = ft_memjoin(tab->ret, "pa\n", ft_strlen(tab->ret), 3);
	else if (line[1] == 'b')
		tab->ret = ft_memjoin(tab->ret, "pb\n", ft_strlen(tab->ret), 3);
}

void	ft_rotate_p(s_pile *tab, char *line)
{
	if (line[1] == 'r')
		tab->ret = ft_memjoin(tab->ret, "rr\n", ft_strlen(tab->ret), 3);
	else if (line[1] == 'a')
		tab->ret = ft_memjoin(tab->ret, "ra\n", ft_strlen(tab->ret), 3);
	else if (line[1] == 'b')
		tab->ret = ft_memjoin(tab->ret, "rb\n", ft_strlen(tab->ret), 3);
}

void	ft_rotate_r_p(s_pile *tab, char *line)
{
	if (line[2] == 'r')
		tab->ret = ft_memjoin(tab->ret, "rr\n", ft_strlen(tab->ret), 3);
	else if (line[2] == 'a')
		tab->ret = ft_memjoin(tab->ret, "ra\n", ft_strlen(tab->ret), 3);
	else if (line[2] == 'b')
		tab->ret = ft_memjoin(tab->ret, "rb\n", ft_strlen(tab->ret), 3);
}
