#include "ft_strs_join.h"

char	*ft_strs_join(int n, ...)
{
	int		i;
	va_list	args;
	char	*str;
	char	*tmp;
	char	*out;

	va_start(args, n);
	out = ft_calloc(1, sizeof(char));
	i = 0;
	while (i < n)
	{
		str = va_arg(args, char *);
		if (str)
		{
			tmp = ft_strjoin(out, str);
			if (!tmp)
				return (NULL);
			free(out);
			free(str);
			out = tmp;
		}
		i++;
	}
	return (out);
}