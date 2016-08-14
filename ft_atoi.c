/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agougaut <agougaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 11:29:03 by agougaut          #+#    #+#             */
/*   Updated: 2016/08/13 09:24:19 by agougaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Version de atoi modifier...
int		ft_atoi_char(char str)
{
        if(str >= '0' && str <= '9')
            return (str - '0');
        else if (str == '.')
            return (0);
        else
            return (str);
}