/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:36:40 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/12 20:53:27 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_data
{
	char	c;
	int		count;
	int		buflen;
	char	*buf;
}	t_data;

void	ft_putnbr(unsigned long nb);
int		ft_atoi(char *str);
int		ft_pow(int n, int pow);
char	*ft_strjoin(char *str, char c, int j);

#endif
