/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:13:57 by adstan            #+#    #+#             */
/*   Updated: 2018/01/07 15:11:58 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_sqrt1(int n)
{
	int		st;
	int		dr;
	int		mij;
	int		sol;

	if (n == 1)
		return (1);
	st = 1;
	dr = n / 2;
	while (st <= dr)
	{
		mij = (st + dr) / 2;
		if (mij * mij <= n)
		{
			if (mij * mij == n)
				sol = mij;
			else
				sol = mij + 1;
			st = mij + 1;
		}
		else if (mij * mij > n)
			dr = mij - 1;
	}
	return (sol);
}
