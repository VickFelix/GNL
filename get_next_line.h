/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfelix-d <vfelix-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:25:15 by vfelix-d          #+#    #+#             */
/*   Updated: 2025/01/01 19:19:51 by vfelix-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*free_and_return(char **buffer, char *ret);
int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(char *src);
char	*get_first_line(char *file);
char	*reading_buff(int fd);
char	*get_next_line(int fd);
#endif
