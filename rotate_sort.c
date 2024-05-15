/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:30:15 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/15 21:49:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexvalue(t_stack *lst, int num)
{
	if (lst == NULL || lst->next == NULL)
		return (0);
	if (num <= lst->num && num >= lst->next->num)
		return (1);
	return (0);
}

void	rotate_sort_b(t_stack **a, t_stack **b)
{
	t_stack	*cur;
	t_stack	*lst;
	int		index;

	cur = *b;
	lst = *a;
	index = 0;
	while (cur != NULL && !(indexvalue(cur, lst->num)))
	{
		cur = cur->next;
		index++;
	}
	index++;
	if (index <= (ft_lstsize(*b) - index))
		anticlockwise(a, b, index);
	else
		clockwise(a, b, index, ft_lstsize(*b));
}

void	cyclic_rotate(t_stack **a, t_stack **b, int index)
{
	ft_rrb(b, ft_lstsize(*b) - index);
	ft_pb(a, b, 1);
	if ((ft_lstsize(*b) - index) > 1)
	{
		ft_rr(a, b, 1);
		ft_rb(b, (ft_lstsize(*b) - index - 1));
	}
	else
		ft_rb(b, (ft_lstsize(*b) - index) + 1);
}

void	double_rotate_sort(t_stack **a, t_stack **b)
{
	t_stack	*cur;
	t_stack	*lst;
	int		index;

	cur = *b;
	lst = *a;
	index = 0;
	while (cur != NULL && !(indexvalue(cur, lst->num)))
	{
		cur = cur->next;
		index++;
	}
	index++;
	if (index <= (ft_lstsize(*b) - index))
	{
		ft_rb(b, index);
		ft_pb(a, b, 1);
		ft_rrb(b, index);
	}
	else
		cyclic_rotate(a, b, index);
}
