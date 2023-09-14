/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:58 by ranascim          #+#    #+#             */
/*   Updated: 2023/09/14 18:08:15 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	validate(char **argv)
{
	int		i;
	char		*c;

	i = 1;
	while (argv[i])
	{
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

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (1);
	if (! validate(argv))
		return (1);
	printf("ok\n");
}
