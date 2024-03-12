/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 15:31:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Allocate memory for pixel structure
*/
t_px *init_pixel(t_plane *plane)
{
	t_px	*pixel;

	pixel = (t_px *)malloc(sizeof(t_px));
	if (pixel == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
	return (pixel);
}
