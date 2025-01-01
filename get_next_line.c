/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfelix-d <vfelix-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:22:48 by vfelix-d          #+#    #+#             */
/*   Updated: 2025/01/01 19:22:32 by vfelix-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first_line(char *file)
{
	int		i;
	char	*res;

	i = 0;
	if (!file)
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	res = (char *)malloc((i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		res[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*reading_buff(int fd)
{
	char	*buffer;
	int		sz;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	sz = read(fd, buffer, BUFFER_SIZE);
	if (sz <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[sz] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	char		*new_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = reading_buff(fd);
	if (!buffer)
		return (NULL);
	line = get_first_line(buffer);
	if (!line)
		return (free_and_return(&buffer, NULL));
	temp = ft_strstr(buffer, line);
	if (!temp || temp[ft_strlen(line)] == '\0')
		return (free_and_return(&buffer, line));
	new_buffer = ft_strdup(&temp[ft_strlen(line)]);
	if (!new_buffer)
		return (free_and_return(&buffer, line));
	free(buffer);
	buffer = new_buffer;
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("teste.txt", O_RDONLY); // Abra um arquivo chamado "test.txt"
    char *line;

    if (fd < 0)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Imprime a linha extraída
        free(line);         // Libera a memória da linha após uso
    }

    close(fd); // Fecha o arquivo
    return (0);
}
