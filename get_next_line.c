/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 10:30:35 by srheede           #+#    #+#             */
/*   Updated: 2018/06/03 18:54:53 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				i;
    int             k;
	char			c;
	static char		*buffer;

    k = read(fd, &c, 1);
    if (fd < 0 || k == -1)
        return (-1);
    buffer = *line;
    i = BUFF_SIZE;
    while (c != '\n' && i > 0 && k == 1)
	{
        *buffer = c;
        k = read(fd, &c, BUFF_SIZE);
        if(!k)
        {
            k = 1;
            *buffer++ = c;
            break ;
        }
		i--;
        buffer++;
    }
    *buffer = '\0';
	return (k);
}
