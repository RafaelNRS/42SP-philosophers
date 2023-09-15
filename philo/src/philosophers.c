/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:20:58 by ranascim          #+#    #+#             */
/*   Updated: 2023/09/14 18:26:10 by ranascim         ###   ########.fr       */
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

int	*routine(void *data_pointer)
{
	printf("1\n");
}

int	main(int argc, char *argv[])
{
	pthread_t	tid;
	
	if (argc < 5 || argc > 6)
		return (1);
	if (! validate(argv))
		return (1);
	printf("ok\n");
	pthread_create(&tid, NULL, &routine, &data_pointer);
}
