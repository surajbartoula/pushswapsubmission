/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divideconquer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:55:40 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/15 08:58:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	medianvalue(t_stack *lst, int len)
{
	t_stack	*cur;
	int		i;
	int		median;

	if (!lst)
		return (0);
	cur = lst;
	i = 0;
	median = 0;
	while (i < len)
	{
		median += cur->p_index;
		cur = cur->next;
		i++;
	}
	return (median / len);
}

void	ft_divideconquer(t_stack **a, t_stack **b, int len)
{
	int		median;
	int		i;
	t_stack	*cur;

	median = medianvalue(*a, len);
	if (median == 0)
		return ;
	i = 0;
	cur = *a;
	while (cur && i < len)
	{
		ft_sort(a, b, median);
		i++;
	}
}
