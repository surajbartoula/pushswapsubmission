/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:11:44 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/15 18:54:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_after_four(t_stack **a, t_stack **b)
{
	int	size;

	fill_postion_index(a);
	while (ft_lstsize(*a) > 4)
		ft_divideconquer(a, b, ft_lstsize(*a));
	size = ft_lstsize(*a);
	if (size == 2 && ((*a)->num > (*a)->next->num))
		ft_sa(a, 1);
	else if (size == 3)
		ft_tiny_sort(a);
	else if (size == 4)
	{
		fill_postion_index(a);
		ft_sortfour(a, b);
	}
	ft_pa(a, b, ft_lstsize(*b));
}

void	filter_sort(t_stack **a, t_stack **b, int size)
{
	if (!a || duplicate(*a))
	{
		ft_free_stack(a);
		ft_error("Duplicate number or stack doesn't exist.");
	}
	else if (size == 1 || (size == 2 && ((*a)->num < (*a)->next->num)))
	{
		ft_free_stack(a);
		exit (0);
	}
	else if (size == 2 && ((*a)->num > (*a)->next->num))
		ft_sa(a, 1);
	else if (size == 3)
		ft_tiny_sort(a);
	else if (size == 4)
	{
		fill_postion_index(a);
		ft_sortfour(a, b);
	}
	else
		sort_after_four(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	returnlsta(argc, argv, &a);
	size = ft_lstsize(a);
	filter_sort(&a, &b, size);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
