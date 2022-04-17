/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:20:01 by orbiay            #+#    #+#             */
/*   Updated: 2021/11/25 13:29:47 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*after_new_line( char *buf)
{
	char	*remind;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(buf);
	while (buf[j])
	{
		if (buf[j] == '\n')
		{
			remind = ft_substr(buf, j + 1, ft_strlen(buf) - j + 1);
			free(buf);
			return (remind);
		}
		j++;
	}
	free(buf);
	return (NULL);
}

char	*cut(char *buf)
{
	int	j;

	j = 0;
	if (!buf[0])
		return (NULL);
	while (buf[j] && buf[j] != '\n')
		j++;
	return (ft_substr(buf, 0, j + 1));
}

char	*get_line(int fd, char *buf)
{
	char	*rsv;
	int		i;

	rsv = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while (!ft_strchr(buf) && i)
	{
		i = read(fd, rsv, BUFFER_SIZE);
		if (i == -1)
		{
			free(rsv);
			return (NULL);
		}
		rsv[i] = '\0';
		buf = ft_strjoin(buf, rsv);
	}
	free (rsv);
	return (buf);
}

char	*get_next_line(int fd)
{
	int				i;
	static char		*buf [MAX_FD];
	char			*line;

	i = 0;
	buf[fd] = get_line(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = cut(buf[fd]);
	buf[fd] = after_new_line(buf[fd]);
	return (line);
}
/*int main()
{
    int fd = open("lo.txt", 0);
    int fd1 = open("lo1.txt", 0);
    int fd2 = open("lo2.txt", 0);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));
    //printf("%s", get_next_line(fd));
}*/
