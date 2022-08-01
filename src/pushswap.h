/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:38:48 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/26 16:50:12 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl1/get_next_line.h"

typedef struct s_mas
{
	int		*mas;
	int		size;
}			t_mas;

typedef struct s_stack
{
	long			number;
	int				index;
	int				flag;

	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
}				t_data;

t_stack	*perevod_ake_provirka(int argc, char **argv);
void	ft_lstadd_back1(t_stack **stack, int number, int f);
t_stack	*ft_lstnew1(int number);
int		ft_lstsize1(t_stack *lst);
void	sorting(t_data *data);
int		privirka(int argc, char **argv);
void	rra(t_stack **stack, char *str);
void	sa(t_stack **stack, char *str);
int		sort_check(t_stack	*a);
void	sort_low(t_data *data, int size);
void	ra(t_stack **stack, char *str);
void	push(t_stack **a, t_stack **b, char *str);
t_stack	*mid_search(t_stack *a);
void	sort_full(t_data *data, int i);
void	sort_osn(int max, int min, int mid, t_data *data);
void	sort_tresh(t_data *data, int size);
void	search_mid(long *p, t_data *data, int size);
int		mas_size(t_mas *mas);
void	sort_mas(t_mas *mas);
void	order_fill(t_mas *mas, t_data *data);
t_mas	*mas_fill(t_stack *stack, t_mas *mas);
void	full_sort(t_data *data);
t_mas	*mas_fill1(t_stack *stack, int flag);
void	rotate_lst(t_data *data, int min);
void	fill_flag(t_data *data);
void	free_data(t_data *data);
void	sort_3(t_data *data);
void	rr(t_data *data, char *str);
void	rrr(t_data *data, char *str);
void	ss(t_data *data, char *str);
int		ft_lstsize2(t_stack *stack, int flag);
int		ra_size(t_stack *stack, int min, int c);
int		rra_size(t_stack *stack, int min, int c);
int		ra_size1(t_stack *stack, int mid);
int		rra_size1(t_stack *stack, int mid);
int		push_sort_a1(t_data *data, t_mas *mas, int min, int c);
int		pus(t_data *data, int *min, int *c);
int		pus2(t_data *data, int *min, int *c);
int		sz_lst(t_data *data);
void	next(t_data *data, int flag);
void	full_sort2(t_mas *mas, t_data *data, int mid);
void	full_sort3(t_data *data, int min);
int		full_sort4(t_data *data, int min);
int		push_sort_b1(t_data *data, int min);
int		push_sort_a_step2(t_data *data, int min);
int		push_sort_b(t_data *data, int min);
int		push_sort_a(t_data *data, int min);
void	provirka2(t_data *data);
int		check_comands(char *command, t_data *data);
void	free_mass(char **str);
void	help_main(char **commands, t_data *data);

#endif
