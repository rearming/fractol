/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_term_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:57:13 by sleonard          #+#    #+#             */
/*   Updated: 2019/06/03 10:37:24 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		parse_key1(int key)
{
	if (key == A)
		return ('a');
	if (key == B)
		return ('b');
	if (key == C)
		return ('c');
	if (key == D)
		return ('d');
	if (key == E)
		return ('e');
	if (key == F)
		return ('f');
	if (key == G)
		return ('g');
	if (key == H)
		return ('h');
	if (key == I)
		return ('i');
	if (key == J)
		return ('j');
	if (key == K)
		return ('k');
	if (key == L)
		return ('l');
	return (key == M ? 'm' : 0);
}

char		parse_key2(int key)
{
	if (key == N)
		return ('n');
	if (key == O)
		return ('o');
	if (key == P)
		return ('p');
	if (key == Q)
		return ('q');
	if (key == R)
		return ('r');
	if (key == S)
		return ('s');
	if (key == T)
		return ('t');
	if (key == U)
		return ('u');
	if (key == V)
		return ('v');
	if (key == W)
		return ('w');
	if (key == X)
		return ('x');
	if (key == Y)
		return ('y');
	return (key == Z ? 'z' : 0);
}

char		parse_key3(int key)
{
	if (key == SPACE)
		return (' ');
	if (key == MINUS || key == NUM_MINUS)
		return ('-');
	if (key == T_0 || key == NUM_0)
		return ('0');
	if (key == T_1 || key == NUM_1)
		return ('1');
	if (key == T_2 || key == NUM_2)
		return ('2');
	if (key == T_3 || key == NUM_3)
		return ('3');
	if (key == T_4 || key == NUM_4)
		return ('4');
	if (key == T_5 || key == NUM_5)
		return ('5');
	if (key == T_6 || key == NUM_6)
		return ('6');
	if (key == T_7 || key == NUM_7)
		return ('7');
	if (key == T_8 || key == NUM_8)
		return ('8');
	if (key == T_9 || key == NUM_9)
		return ('9');
	return (key == COLON ? ':' : 0);
}

char		get_char(int key)
{
	char	c;

	c = parse_key1(key);
	if (c)
		return (c);
	c = parse_key2(key);
	if (c)
		return (c);
	c = parse_key3(key);
	if (c)
		return (c);
	return (0);
}

void		parse_term_input(t_mlx *mlx, int key)
{
	if (key == ENTER)
	{
		mlx->term.cmd_i = 0;
		update_backup(mlx);
		process_command(mlx);
		return ;
	}
	if (mlx->term.cmd.status == PREPARE)
		mlx->term.cmd.status = LISTEN;
	check_backup(mlx, key);
	bresen_line(mlx, (t_point){0, WIN_HEIGHT - 230, 0, WHITE},
				(t_point){WIN_WIDTH, WIN_HEIGHT - 230, 0, 0});
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx->term.buff[mlx->term.i] = get_char(key);
	if (mlx->term.i == 0)
		mlx->term.buff[++mlx->term.i] = ' ';
	if (key == DEL && mlx->term.i >= 3)
		del_char(mlx);
	if (mlx->term.buff[mlx->term.i])
		mlx->term.i++;
	mlx_string_put(mlx->mlx, mlx->win, 50, WIN_HEIGHT - 200, WHITE,
				mlx->term.buff);
	screen_info(mlx);
}
