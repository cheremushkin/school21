#include "libft.h"

char	*ft_strrev(char *str)
{
	unsigned int	i;
	size_t			str_len;
	char			tmp;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len - i)
	{
		tmp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = tmp;
		i++;
	}
	return (str);
}
