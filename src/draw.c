/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** draw
*/

#include "../include/file.h"

void draw_obstacle(game_t *game)
{
    for (int i = 0; i < 2077; i++){
      sfRenderWindow_drawRectangleShape(game->wdw, game->scene->object_map->
      rect[i], NULL);
    }
}

void draw_map(game_t *game)
{
    sfRenderWindow_drawSprite(game->wdw, game->scene->object_map->sprite[0],
    NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object_map->sprite[1],
    NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object->sprite, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object_map->sprite[2],
    NULL);
}

void draw_main(game_t *game)
{
    sfColor color = sfColor_fromInteger(65000);
    sfUint32 i = sfColor_toInteger(sfBlue);
    sfRenderWindow_clear(game->wdw, sfBlack);
    draw_map(game);
    draw_obstacle(game);
    sfRenderWindow_drawRectangleShape(game->wdw, game->scene->object->rect, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->scene->object[1].sprite, NULL);
    sfRenderWindow_display(game->wdw);
}