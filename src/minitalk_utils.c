/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:12:39 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/12 19:52:41 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(unsigned long nb)
{
	char	x;

	if (nb > 9)
		ft_putnbr(nb / 10);
	x = '0' + (nb % 10);
	write(1, &x, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

int	ft_pow(int n, int pow)
{
	int	powofn;

	powofn = 1;
	while (pow--)
		powofn *= n;
	return (powofn);
}

char	*ft_strjoin(char *str, char c, int j)
{
	int		i;
	char	*strjoin;

	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	strjoin = malloc(sizeof(char) * j + 2);
	if (!strjoin)
		return (0);
	i = 0;
	while (str[i])
	{
		strjoin[i] = str[i];
		i++;
	}
	strjoin[i++] = c;
	strjoin[i] = '\0';
	return (free(str), strjoin);
}
