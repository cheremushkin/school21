#include "ft_eval_utils.h"

void	ft_process_number_(t_number *n, long long num)
{
	if (num >= 0)
	{
		n->u_num = num;
		n->sign = 1;
	}
	else
	{
		n->u_num = -num;
		n->sign = -1;
	}
}

int	ft_add_precision_(t_conv *conv)
{
	int		str_len;
	int		len;
	char	*tmp;

	str_len = ft_strlen(conv->out.c);
	len = FT_MAX(conv->precision - str_len, 0) + str_len;
	if (len == str_len)
		return (0);
	if (ft_malloc_((void **) &tmp, sizeof(char) * (len + 1)))
		return (1);
	ft_memset(tmp, '0', len - str_len);
	ft_strlcpy(tmp + len - str_len, conv->out.c, str_len + 1);
	free(conv->out.c);
	conv->out.c = tmp;
	conv->out.c_len = len;
	return (0);
}

int ft_set_prefix_(t_conv *conv, t_number n)
{
	if (ft_calloc_((void **) &(conv->out.p), 3, sizeof(char)))
		return (1);
	if (n.sign == -1)
	{
		conv->out.p[0] = '-';
		conv->out.p_len = 1;
	}
	else if (conv->flags.plus || conv->flags.space)
	{
		if (conv->flags.plus)
			conv->out.p[0] = '+';
		if (conv->flags.space)
			conv->out.p[0] = ' ';
		conv->out.p_len = 1;
	}
	return (0);
}

int ft_set_shift_(t_conv *conv)
{
	conv->out.s_len = FT_MAX(FT_MAX(conv->width, conv->out.c_len + conv->out.p_len) - (conv->out.c_len + conv->out.p_len), 0);
	if (ft_calloc_((void **) &(conv->out.s), sizeof(char), conv->out.s_len + 1))
		return (1);
	if (conv->flags.zero && !conv->flags.minus && conv->precision == -1)
		ft_memset(conv->out.s, '0', conv->out.s_len);
	else
		ft_memset(conv->out.s, ' ', conv->out.s_len);
	return (0);
}