/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** initialize
*/

#include "../include/file.h"

void initialize_timer_one(game_t *game, int nb, int scene)
{
    game->scene[scene].horloge[nb].clock = sfClock_create();
}

void initialize_scene_one(game_t *game)
{
    game->scene = malloc(sizeof(scene_t) * 1);
    game->scene->object = malloc(sizeof(object_t) * 3);
    game->scene->object_map = malloc(sizeof(object_map_t) * 1);
    game->scene->horloge = malloc(sizeof(timer_t) * 2);
    initialize_obj_charactere(game, 0, 0);
    initialize_timer_one(game, 0, 0);
    initialize_obj_particuls(game, 1, 0);
    initialize_obj_map(game, 0, 0);
}

void initialize_view(game_t *game)
{
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f) {1280, 720});
    sfView_zoom(game->view, 0.37);
}

game_t *initialize_main(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->mode.width = 1280;
    game->mode.height = 720;
    game->mode.bitsPerPixel = 32;
    game->wdw = sfRenderWindow_create(game->mode, "my_rpg",
    sfDefaultStyle, NULL);
    initialize_scene_one(game);
    initialize_view(game);
    return game;
}
