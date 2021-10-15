#include "ft_strings.h"

char	*ft_strs_join(int n, ...)
{
	int		i;
	va_list	args;
	char	*str;
	char	*tmp;
	char	*out;

	va_start(args, n);
	out = ft_calloc(1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str = va_arg(args, char *);
		if (str)
		{
			tmp = ft_strjoin(out, str);
			free(out);
			free(str);
			out = tmp;
		}
		i++;
	}
	return (out);
}
