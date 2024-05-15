/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/15 21:50:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	ft_rb(b, index);
	ft_pb(a, b, 1);
	ft_rrb(b, index);
}

void	clockwise(t_stack **a, t_stack **b, int index, int size)
{
	ft_rrb(b, size - index);
	ft_pb(a, b, 1);
	ft_rb(b, (size - index) + 1);
}

void	ft_rotate(t_stack **a, t_stack **b)
{
	t_stack	*cur;

	if ((*a) == NULL)
		return ;
	else if ((*b) == NULL)
	{
		ft_pb(a, b, 1);
		return ;
	}
	fill_postion_index(b);
	cur = *b;
	while (cur->next != NULL)
		cur = cur->next;
	if ((*a)->num > (*b)->num)
		ft_pb(a, b, 1);
	else if ((*a)->num < cur->num)
	{
		ft_pb(a, b, 1);
		ft_rb(b, 1);
	}
	else
		rotate_sort_b(a, b);
}

void	ft_doublerotate(t_stack **a, t_stack **b)
{
	t_stack	*cur;

	if ((*a) == NULL)
		return ;
	else if ((*b) == NULL)
	{
		ft_pb(a, b, 1);
		return ;
	}
	fill_postion_index(b);
	cur = *b;
	while (cur->next != NULL)
		cur = cur->next;
	if ((*a)->num > (*b)->num)
		ft_pb(a, b, 1);
	else if ((*a)->num < cur->num)
	{
		ft_pb(a, b, 1);
		ft_rr(a, b, 1);
	}
	else
		double_rotate_sort(a, b);
}
