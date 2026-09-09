/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:19:09 by abukh             #+#    #+#             */
/*   Updated: 2026/08/22 16:19:37 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int	fd = open("./testing", O_WRONLY);

// 	ft_putstr_fd("Hello, World!", fd);
// 	close(fd);
// 	return (0);
// }