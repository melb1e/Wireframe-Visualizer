/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:34:24 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 14:34:01 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *message)
{
	if (message == 0)
		ft_putstr_fd("Error [Debug]\n", 1);
	else
		ft_putstr_fd(message, 1);
	exit (1);
}
