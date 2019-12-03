/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:04:56 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/29 22:36:15 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ALLOC_LINE(line)		if(!(line = ft_strnew(0))) return (-1)
# define ALLOC_OVERFLOW(over)	if(!(over = ft_strnew(BUFF_SIZE))) return (-1)
# define BUFF_SIZE	32
# define FD_MAX	1024

# include <stdlib.h>
# include "../libft/libft.h"

int			get_next_line(int fd, char **line);
void		strjoinfree(char **s1, char *s2);
void		strdupfree(char **dst, char *src);
void		save_line(char **line, char **overflow, char *endl);
int			read_line(int fd, char *buff, char **line, char **overflow);

#endif
