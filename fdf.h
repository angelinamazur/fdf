/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:14 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/04/19 22:38:33 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# define BUFFER_SIZE 100

typedef struct s_map
{
	int		width;
	int		height;
	int		**values;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_map;

size_t	ft_strlen(const char *c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_ind_n(char *arr);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	read_file(char *file, t_map *map);
void	bresenham(int x1, int y1, int x2, int y2, t_map *map);

#endif