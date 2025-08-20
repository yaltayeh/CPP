/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:47:30 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/19 17:56:25 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <math.h>
#include "Point.hpp"

#define WIDTH 900
#define HEIGHT 500

bool bsp(Point const a, Point const b, Point const c, Point const point);


typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

void	draw_triangle(mlx_image_t *image, Point p[3])
{
	float sx = Fixed::min(p[0].x, Fixed::min(p[1].x, p[2].x)).toFloat();
	float sy = Fixed::min(p[0].y, Fixed::min(p[1].y, p[2].y)).toFloat();
	float ex = Fixed::max(p[0].x, Fixed::max(p[1].x, p[2].x)).toFloat();
	float ey = Fixed::max(p[0].y, Fixed::max(p[1].y, p[2].y)).toFloat();
	for (float y = sy; y <= ey; y++)
	{
		for (float x = sx; x <= ex; x++)
		{
			if (bsp(p[0], p[1], p[2], Point(x, y)))
				mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, 0xff0000ff);
		}
	}
}

int32_t main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Barycentric coordinate system", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	Point p[3] = {
		Point(Fixed(0.f), Fixed(0.f)),
		Point(Fixed((float)image->width), Fixed((float)image->height)),
		Point(Fixed(0.f), Fixed((float)image->height))
	};

	draw_triangle(image, p);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
