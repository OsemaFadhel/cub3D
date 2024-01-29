/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:48 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/29 12:36:34 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

function line(int x0, int x1, int y0, int y1)
{
	int deltax := abs(x1 - x0)
	int deltay := abs(y1 - y0)
	int error := 0
	int deltaerr := (deltay + 1)
	int y := y0
	int diry := y1 - y0
	if diry > 0
		diry = 1
	if diry < 0
		diry = -1
	for x from x0 to x1
	{
		plot(x,y)
		error := error + deltaerr
		if error >= (deltax + 1)
		{
			y := y + diry
			error := error - (deltax + 1)
		}
	}
}
