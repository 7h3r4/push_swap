/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:07:16 by abukh             #+#    #+#             */
/*   Updated: 2026/08/22 15:31:23 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int fd = open("./testing", O_WRONLY);
// 	if (fd > 0)
// 		ft_putchar_fd('Z', fd);
// 	else
// 		write(1, "Couldn't open the file", 23);
// 	close(fd);
// 	return (0);
// }