/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slazar <slazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:57:44 by slazar            #+#    #+#             */
/*   Updated: 2023/04/16 00:06:49 by slazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cnc;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	cnc = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cnc)
		return (0);
	while (*s1)
	{
		cnc[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		cnc[i] = *s2;
		s2++;
		i++;
	}
	cnc[i] = 0;
	return (cnc);
}

char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}

char	*my_filter(char *save)
{
	char	*fil;
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
		fil = malloc (i + 1);
	else
		fil = malloc (i + 2);
	if (!fil)
		return (0);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		fil[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		fil[i++] = '\n';
	fil[i] = '\0';
	return (fil);
}

char	*my_filter_cut(char *save)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	p = malloc(ft_strlen(save) - i + 1);
	while (save[i])
		p[j++] = save[i++];
	p[j] = '\0';
	free(save);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	int			readed;
	char		*fil;

	while (!my_strchr(save, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buffer[readed] = '\0';
		save = my_strjoin(save, buffer);
	}
	if (ft_strlen(save) > 0 && readed >= 0)
	{
		fil = my_filter(save);
		save = my_filter_cut(save);
		return (fil);
	}
	free(save);
	return (save = 0);
}
