/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfour.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:56:02 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/16 07:52:31 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortfwo(t_stack **a, t_stack **b)
{
	ft_pb(a, b, 1);
	ft_tiny_sort(a);
	ft_pa(a, b, 1);
}

void	ft_sortfour(t_stack **a, t_stack **b)
{
	if ((*a)->p_index == 1)
		sortfwo(a, b);
	else if ((*a)->p_index == 2)
	{
		sortfwo(a, b);
		ft_sa(a, 1);
	}
	else if ((*a)->p_index == 3)
	{
		ft_pb(a, b, 1);
		ft_tiny_sort(a);
		ft_rra(a, 1);
		ft_pa(a, b, 1);
		ft_ra(a, 2);
	}
	else if ((*a)->p_index == 4)
	{
		sortfwo(a, b);
		ft_ra(a, 1);
	}
	else
		ft_printf("Neither condition was met\n");
}
