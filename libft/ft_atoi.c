/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:44:17 by adstan            #+#    #+#             */
/*   Updated: 2017/12/16 17:57:37 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	long long	nr;
	long long	sign;

	nr = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		if (nr > 922337203685477580 && sign == 1)
			return (-1);
		else if (nr < -922337203685477580 && sign == -1)
			return (0);
		nr = nr * 10 + sign * (*str++ - '0');
		if (nr < 0 && sign == 1)
			return (-1);
		else if (nr > 0 && sign == -1)
			return (0);
	}
	return (nr);
}
