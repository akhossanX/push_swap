/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:03:34 by akhossan          #+#    #+#             */
/*   Updated: 2019/12/01 19:26:46 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Joins s2 to s1 and frees the old s1
*/

void		strjoinfree(char **s1, char *s2)
{
	char	*tmp;

	if (s1 && *s1 && s2)
	{
		tmp = *s1;
		*s1 = ft_strjoin(*s1, s2);
		ft_strdel(&tmp);
	}
}

/*
** Duplicates the string src into dst,
** and frees the old dst
*/

void		strdupfree(char **dst, char *src)
{
	char	*tmp;

	if (dst && *dst && src)
	{
		tmp = *dst;
		*dst = ft_strdup(src);
		ft_strdel(&tmp);
	}
}

/*
** Joins the line form previous overflow, to first param
** then update overflow from endl up to the end of overflow
*/

void		save_line(char **line, char **overflow, char *endl)
{
	endl[0] = 0;
	strjoinfree(line, *overflow);
	strdupfree(overflow, endl + 1);
}

/*
** Reads a line and stores it to line arg
** if there is overflow from previous reading
** it's taken into consideration by joining it with line
*/

int			read_line(int fd, char *buff, char **line, char **overflow)
{
	int		flag;
	char	*endl;

	while ((flag = read(fd, buff, BUFF_SIZE)) > 0 || (flag == 0 && **overflow))
	{
		strjoinfree(overflow, buff);
		if ((endl = ft_strchr(*overflow, '\n')))
		{
			save_line(line, overflow, endl);
			return (1);
		}
		else
		{
			strjoinfree(line, *overflow);
			ft_strclr(buff);
			ft_strclr(*overflow);
		}
	}
	if (!**overflow)
		ft_strdel(overflow);
	if (flag == 0 && **line)
		return (1);
	return (flag < 0 ? -1 : 0);
}

/*
** Reads from a file descriptor a hole line
** we consider a line a series of characters
** ending with '\n' (line break character)
** it returns (1) when a line has been read,
** (0) if EOF (END OF FILE) has been read
** (-1) if an error occured when reading
*/

int			get_next_line(int fd, char **line)
{
	static char		*overflow[FD_MAX];
	char			buff[BUFF_SIZE + 1];
	char			*endl;
	int				flag;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > FD_MAX)
		return (-1);
	ALLOC_LINE(*line);
	if (!overflow[fd])
		ALLOC_OVERFLOW(overflow[fd]);
	if (*overflow[fd] && (endl = ft_strchr(overflow[fd], '\n')))
	{
		save_line(line, &overflow[fd], endl);
		return (1);
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	flag = read_line(fd, buff, line, &overflow[fd]);
	if (flag <= 0)
		ft_strdel(line);
	return (flag);
}
