/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agougaut <agougaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:58:46 by agougaut          #+#    #+#             */
/*   Updated: 2016/08/11 14:31:57 by agougaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int tab[10];
	int i;
	int a;

	i = 0;
	tab[0] = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			nb = nb + 1;
			a = a + 1;
		}
		nb = -nb;
		ft_putchar('-');
	}
	while (nb > 0)
	{
		tab[i++] = nb % 10;
		nb = nb / 10;
	}
	if (a == 1)
		tab[0] = tab[0] + 1;
	while (i > 0)
		ft_putchar(tab[--i] + '0');
}