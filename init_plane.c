/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/01 17:00:22 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_view(t_plane plane, t_view *view)
{
	view->hor_rot = 0;
	view->vert_rot = 0;
	view->x_vect_abs = 0;
	view->x_vect_ord = 0;
	view->x_vect_angle_hor = 270;
	view->x_vect_angle_vert = 270;
	view->x_vect_hor_ax = false;
	view->x_vect_vert_ax = false;
	view->y_vect_abs = plane.y_scale;
	view->y_vect_ord = 0;
	view->y_vect_angle_hor = 0;
	view->y_vect_angle_vert = 0;
	view->y_vect_hor_ax = true;
	view->y_vect_vert_ax = false;
	view->z_vect_abs = 0;
	view->z_vect_ord = plane.z_scale;
	view->z_vect_angle_hor = 0;
	view->z_vect_angle_vert = 0;
	view->z_vect_hor_ax = false;
	view->z_vect_vert_ax = true;
}

void	init_plane(t_map map, t_plane *plane)
{
	t_view	*view;
	int		vertic_rot;
	int		hor_rot;

	plane->x_scale = 100;
	plane->y_scale = 100;
	plane->z_scale = 100;
	view = (t_view *)malloc(sizeof(t_view));
	if (view == NULL)
		exit (EXIT_FAILURE);
	init_view(*plane, view);
	plane->view = view;
	vertic_rot = 30;
	hor_rot = 30;
	ft_printf("---%?31s OF %?31d...\n", "STARTING VERTICAL ROTATION", vertic_rot);
	vertical_rotation(*plane, plane->view, vertic_rot);
	ft_printf("---%?31s OF %?31d...\n", "STARTING HORIZONTAL ROTATION", hor_rot);
	horizontal_rotation(*plane, plane->view, hor_rot);
	plane->margin_abs = (int)fmax((float)view->x_vect_abs, (float)view->y_vect_abs);
	if (plane->margin_abs > 20)
		plane->margin_abs = 20;
	plane->margin_ord = (int)fmin((float)view->z_vect_ord, 20);
	plane->height = init_plane_height(map, plane, *view);
	plane->width = init_plane_width(map, plane, *view);
}
