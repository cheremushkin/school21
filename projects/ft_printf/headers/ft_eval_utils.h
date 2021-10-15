#ifndef FT_EVAL_UTILS_H
# define FT_EVAL_UTILS_H

# include "libft.h"
# include "ft_conv.h"

typedef	struct s_number
{
	unsigned int	u_num;
	int 			sign;
}	t_number;

void	ft_process_number_(t_number *n, long int num);
int		ft_add_precision_(t_conv *conv);
int 	ft_set_prefix_(t_conv *conv, t_number n);
int 	ft_set_shift_(t_conv *conv);

#endif
