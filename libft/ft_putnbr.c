/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:40:42 by adstan            #+#    #+#             */
/*   Updated: 2018/02/22 19:41:26 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void		idk(int nb)
{
	if (!nb)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
}

void			ft_putnbr(int nb)
{
	char	v[12];
	int		i;

	i = 0;
	if (!nb || nb == -2147483648)
	{
		idk(nb);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (nb)
	{
		v[i++] = nb % 10;
		nb /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar(v[i--] + '0');
}
