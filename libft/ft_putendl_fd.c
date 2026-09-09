/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:19:01 by abukh             #+#    #+#             */
/*   Updated: 2026/08/22 16:19:45 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int	fd = open("./testing", O_WRONLY);

// 	ft_putendl_fd("Hello, World!", fd);
// 	close(fd);
// 	return (0);
// }