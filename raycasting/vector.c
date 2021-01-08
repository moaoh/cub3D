/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:15:08 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/08 23:39:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vec		vec_new(double x, double y)
{
	t_vec	result;
	
	result.x = x;
	result.y = y;
	return (result);
}

t_vec		vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec		vec_sub(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec		vec_mul(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	return (a);
}
