/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:09:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/15 21:51:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

typedef struct push_swap
{
	struct push_swap	*next;
	struct push_swap	*prev;
	int					num;
	int					p_index;
}				t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new_lst);
t_stack	*ft_lstnew(int num);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_atoi(const char *str);
void	ft_swap(int *a, int *b);
void	returnlsta(int argc, char *argv[], t_stack **a);
void	fill_postion_index(t_stack **a);
void	ft_free(char **argv);
void	ft_error(char *str);
void	ft_free_stack(t_stack **lst);
int		stack_sorted(int *arr, int len);
int		duplicate(t_stack *a);
size_t	ft_strlen(const char *str);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
int		ft_lstsize(t_stack *lst);
void	ft_sort(t_stack **a, t_stack **b, int median);
void	ft_tiny_sort(t_stack **a);
void	ft_rotate(t_stack **a, t_stack **b);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_divideconquer(t_stack **a, t_stack **b, int len);
void	ft_doublerotate(t_stack **a, t_stack **b);
void	ft_sortfour(t_stack **a, t_stack **b);
void	rotate_sort_b(t_stack **a, t_stack **b);
void	double_rotate_sort(t_stack **a, t_stack **b);
void	anticlockwise(t_stack **a, t_stack **b, int index);
void	clockwise(t_stack **a, t_stack **b, int index, int size);

#endif