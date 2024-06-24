/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:09:14 by everolla          #+#    #+#             */
/*   Updated: 2023/02/08 16:14:34 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*clean_end(char *line_sporca);
char	*clean_start(char *line_sporca);
char	*ft_join(char *s1, char *s2);
char	*create_line(int fd, char *statica);

#endif