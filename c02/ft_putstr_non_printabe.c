#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	m;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			if (((unsigned char)str[i] / 16) > 9)
				m = 'a' + (((unsigned char)str[i] / 16) - 10);
			else
				m = (((unsigned char)str[i]) / 16) + '0';
			write(1, "\\", 1);
			write(1, &m, 1);
			if (((unsigned char)str[i] % 16) > 9)
				m = 'a' + (((unsigned char)str[i] % 16) - 10);
			else
				m = ((unsigned char)str[i] % 16) + '0';
			write(1, &m, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
