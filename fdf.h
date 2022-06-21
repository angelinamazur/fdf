/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:14 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/21 18:39:58 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# define BUFFER_SIZE 10000
# define UP 126
# define DOWN 125 
# define LEFT 123
# define RIGHT 124 
# define ESC 53
# define ZOOM_OUT 24
# define ZOOM_IN 27
# define Z_DOWN 43
# define Z_UP 47
# define ISO_ON 18
# define ISO_OFF 19
# define W_WIDTH 1920
# define W_HEIGHT 1080

typedef struct s_elem
{
	int	color;
	int	value;
}	t_elem;

// typedef struct s_env
// {
// 	int		width;
// 	int		height;
// 	t_elem	**map;
// 	int		zoom;
// 	int		z_k;
// 	int		iso_flag;
// 	int		shift_x;
// 	int		shift_y;
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_env;

// typedef struct s_dots
// {
// 	int		x;
// 	int		y;
// 	int		x1;
// 	int		y1;
// }	t_dots;

typedef struct s_env
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		width;
	int		height;
	t_elem	**map;
	int		zoom;
	int		z_k;
	int		iso_flag;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_env;

size_t	ft_strlen(const char *c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
int		ft_ind_n(char *arr);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	read_file(char *file, t_env *env);
void	bresenham(float x, float y, float x1, float y1, t_env *env);
int		ft_hex_to_dec(char *hex);
int		get_width(char *line);
int		get_height(char *file);
void	draw(t_env *env);
void	free_map(t_elem **map, int height);
void	move(int key, t_env *env);
void	zoom(int key, t_env *env);
void	iso(int key, t_env *env);
void	flatten(int key, t_env *env);
// void	make_env(t_env **env, int height, int width);
void	make_env(t_env *env, int height, int width);

#endif