/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:10:02 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 14:04:04 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	validate(char **argv)
{
	int		i;
	char	*c;

	i = 1;
	if (ft_atoi(argv[i]) <= 0)
		return (0);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		c = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(c, argv[i], ft_strlen(argv[i])) == 0)
			i++;
		else
		{
			free(c);
			return (0);
		}
		free(c);
	}
	return (1);
}

void	ft_bzero(void *s, int n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		str[n] = '\0';
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_digit_count(long n)
{
	int	dc;

	dc = 1;
	while (n >= 10)
	{
		n = n / 10;
		dc++;
	}
	return (dc);
}
