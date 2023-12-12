/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:38 by fshields          #+#    #+#             */
/*   Updated: 2023/11/29 14:46:31 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	int				nl_i;
	ssize_t			read_return;

	str = NULL;
	read_return = BUFFER_SIZE;
	while (find_nl_i(str) == -1 && read_return != 0)
	{
		nl_i = find_nl_i(buffer);
		str = join(&str, buffer, nl_i);
		if (nl_i != -1)
		{
			trim_front(buffer);
			return (str);
		}
		ft_bzero(buffer, BUFFER_SIZE);
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(str);
			return (NULL);
		}
	}
	return (str);
}
