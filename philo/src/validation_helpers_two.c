/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helpers_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:11:24 by ranascim          #+#    #+#             */
/*   Updated: 2023/10/09 13:46:11 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	is_neg;

	i = 0;
	num = 0;
	is_neg = 1;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = is_neg * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + nptr[i] - 48;
		i++;
	}
	return ((int)(num * is_neg));
}

void	*ft_calloc(int nmemb, int size)
{
	int		max;
	void	*p;

	max = nmemb * size;
	if (nmemb != 0 && (max / nmemb != size))
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		number_size;
	int		is_neg;
	int		i;
	long	l;

	l = n;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		l = l * -1;
	}
	number_size = ft_digit_count(l);
	c = (char *) ft_calloc(number_size + is_neg + 1, sizeof(char));
	i = 0;
	while (i < number_size)
	{
		c[number_size + is_neg - i - 1] = (l % 10) + 48;
		l = l / 10;
		i++;
	}
	if (is_neg == 1)
		c[0] = '-';
	return (c);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < ft_strlen(s1) && i < ft_strlen(s2) && \
					s1[i] == s2[i] && n > i + 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
