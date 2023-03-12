/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:14:44 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/10 19:38:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdbool.h>
#include <mlx.h>
#include <math.h>
#include "../core/core.h"

#define BUFFER_SIZE 1

/************* error msgs ***************/
#define ARG_ERR "Number of arguments is not valid"
#define AV_ERR "File should have a name"
#define EXT_EMPTY "File should have an extention"
#define EXT_ERR "Unvalid extention"
#define FILE_ERR "Unvalid file, check if it exist"
#define XPM_ERR "Textures should have an extention"
#define TYPE_ERR "Invalid extention"
#define EMP_PATH_ERR "Path is empty"
#define EMPTY_FILE "File is empty"
#define MAP_ERR "Map should not contain empty lines"

/************* libft ***************/
int     ft_strcmp(char *s1, char *s2);
char    *ft_strchr(char *str, int c);
int     ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char	*s, char c);
int     ft_atoi(char *str);
char	*ft_strrchr(char *s, int c);        

/************* getNextline ***************/
int     search(char *s, int c);
char	*restart(char **stock);
char	*create_line(char **stock);
char	*stock_in(int fd, char *stock, char *rest, int rd);
char	*get_next_line(int fd);

/************* printer ***************/
void    msg_printer(char *msg);
void    error_printer(char *err);

/************* leaks hunter ***************/
void    unvalid_game(t_game **g);

/************* primary checks ***************/
int     primary_checks(int ac, char *av);
void    arg_check(int ac, char *av);
void    ext_check(char *ext);
int     file_check(char *av);

/************* parse utils ***************/
bool    empty_line(char *line);
void    parse_config(char *line, t_game **g);

/************* parse file ***************/
void    parse_file(int fd, t_game **g);
void    check_empty_file(char *line, t_game **g);
void    raise_flag(int *flag, t_game **g);

/************* color ***************/
int encode_color(int t, int r, int g, int b);
int count_words(char **table);
void    check_valid_number(char *color);
void    check_numbers(char **colors);
int check_color(char **colors);
void    colors_parameters(char *content, t_game **g);

/************* texture ***************/
char    *compare_texture(char *content);
void    check_xpm(char *content);
void    check_valid_path(char *content);
void    textures_parameters(char *content, t_game **g);

/************* parse map ***************/
char    *create_map(char *map, char *line);
void    check_borderline(char *line);
void    parse_map(char *map, t_game **g);
void    check_player(char *map, t_game **g);
void    init_config_data(t_game **g);

#endif
