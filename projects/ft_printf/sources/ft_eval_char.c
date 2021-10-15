#include "ft_eval_char.h"

int	ft_eval_char(va_list args, t_conv *conv)
{
	 int	width;

	 width = FT_MAX(conv->width, 1);
	 conv->out.str = (char *) malloc(sizeof(char) * (width + 1));
	 if (!conv->out.str)
	 	return (1);
	 if (conv->flags.zero)
	 	ft_memset(conv->out.str, '0', width);
	 else
	 	ft_memset(conv->out.str, ' ', width);
	 if (conv->flags.minus)
		 conv->out.str[0] = va_arg(args, int);
	 else
		 conv->out.str[width - 1] = va_arg(args, int);
	 conv->out.len = width;
	return (0);
}
