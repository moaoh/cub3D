/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:48:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/11 09:31:56 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// WASD
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// KEYBOARD ESC
# define K_ESC 53

// EVENT KEY
#define X_EVENT_KEY_PRESS   2
#define X_EVENT_KEY_EXIT    17

// (c == 'E' || c == 'W' || c == 'N' || c == 'S')
static void			player_dir(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->dir_Y = 0;
		info->dir_X = +1;
	}
	else if (dir == 'W')
	{
		info->dir_Y = 0;
		info->dir_X = -1;
	}
	else if (dir == 'N')
	{
		info->dir_Y = -1;
		info->dir_X = 0;
	}
	else if (dir == 'S')
	{
		info->dir_Y = +1;
		info->dir_X = 0;
	}
}

static void			player_plane(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->plane_Y = -0.66;
		info->plane_X = 0;
	}
	else if (dir == 'W')
	{
		info->plane_Y = 0.66;
		info->plane_X = 0;
	}
	else if (dir == 'N')
	{
		info->plane_Y = 0;
		info->plane_X = -0.66;
	}
	else if (dir == 'S')
	{
		info->plane_Y = 0;
		info->plane_X = +0.66;
	}
}

static void			ray_putin_info(t_ray_info *info, t_map *map)
{
	info->screen_Y = map->screen.Y;
	info->screen_X = map->screen.X;
	info->playerposition_Y = map->player.y;
	info->playerposition_X = map->player.x;
	player_dir(info, map->player.dir);
	player_plane(info, map->player.dir);
	info->map = map->map.map;
}

// int key_press(int key, t_ray_info *info)
// {
// 	printf("key : %d", key);
//     // WS
//     if (key == KEY_W)
//     {
//         if (!info->map[(int)(info->playerposition_X + info->dir_X * info->moveSpeed)][(int)(info->playerposition_Y)])
//             info->playerposition_X += info->dir_X * info->moveSpeed;
//         if (!info->map[(int)(info->playerposition_X)][(int)(info->playerposition_Y + info->dir_Y * info->moveSpeed)])
//             info->playerposition_Y += info->dir_Y * info->moveSpeed;
//     }

//     if (key == KEY_S)
//     {
//         /*  
//             S키를 누르면 뒤로 이동한다.
//             이때, 이동하고자 하는 위치는 맵 상에서 무조건 0이어야 한다.
//             왜냐하면 맵 위에서 1~4가 의미하는 바는 통과할 수 없는 장애물이기 때문이다.
//             만약 [2][2]맵이 있다고 할 때,
//             위치의 오른쪽 위 지점에서 오른쪽 위를 바라보고 s키를 누르면
//             왼쪽 아래 지점으로 이동해야 한다.
//             이를 위해서는 x를 한칸 왼쪽으로 이동시키고,
//             y를 한칸 아래로 이동시키면 된다.
//             아래는 다음을 구체적으로 구현한 것이다.
//         */
//         if (!info->map[(int)(info->playerposition_X - info->dir_X * info->moveSpeed)][(int)(info->playerposition_Y)])
//             info->playerposition_X -= info->dir_X * info->moveSpeed;
//         if (!info->map[(int)(info->playerposition_X)][(int)(info->playerposition_Y - info->dir_Y * info->moveSpeed)])
//             info->playerposition_Y -= info->dir_Y * info->moveSpeed;
//     }

//     // AD
//     if (key == KEY_A)
//     {
//         double oldDirectionX = info->dir_X;
//         info->dir_X = info->dir_X * cos(info->rotSpeed) - info->dir_Y * sin(info->rotSpeed);
//         info->dir_Y = oldDirectionX * sin(info->rotSpeed) + info->dir_Y * cos(info->rotSpeed);
//         double oldPlaneX = info->plane_X;
//         info->plane_X = info->plane_X * cos(info->rotSpeed) - info->plane_Y * sin(info->rotSpeed);
//         info->plane_Y = oldPlaneX * sin(info->rotSpeed) + info->plane_Y * cos(info->rotSpeed);
//     }

//     // https://github.com/ChoiKanghun/images/blob/master/1024_1.jpg?raw=true 
//     // 위 이미지를 브라우저에 검색하자. 핵심이 되는 공식이다. 이 공식에 대한 자세한 설명은
//     // https://github.com/minckim0/cub3d_lect 해당 깃 레포 내 pdf 62~66 페이지 참고.
//     if (key == KEY_D)
//     {
//         double oldDirectionX = info->dir_X;
//         info->dir_X = info->dir_X * cos(-info->rotSpeed) - info->dir_Y * sin(-info->rotSpeed);
//         info->dir_Y = oldDirectionX * sin(-info->rotSpeed) + info->dir_Y * cos(-info->rotSpeed);
//         double oldPlaneX = info->plane_X;
//         info->plane_X = info->plane_X * cos(-info->rotSpeed) - info->plane_Y * sin(-info->rotSpeed);
//         info->plane_Y = oldPlaneX * sin(-info->rotSpeed) + info->plane_Y * cos(-info->rotSpeed);
//     }
//     if (key == K_ESC)
//         exit(0);
//     return (0);
// }

int		key_press(int key, t_ray_info *info)
{
	printf("key : %d", key);
}

int					cub3d(t_map map)
{
	t_ray_info	info;

	ray_putin_info(&info, &map);
	info.mlx = mlx_init();

	info.win = mlx_new_window(info.mlx, map.screen.X, map.screen.Y, "cub3d");
	mlx_loop_hook(info.mlx, &main_loop, &info);

	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
	
	return (0);
}

// 로데브
