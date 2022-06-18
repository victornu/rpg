/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** initialize_map
*/

#include "../include/file.h"

void initialize_obj_map_one(game_t *game, int nb, int scene)
{
    sfSprite_setTexture(game->scene[scene].object_map[nb].sprite[0], game->
    scene[scene].object_map[nb].texture[0], sfTrue);
    sfSprite_setTexture(game->scene[scene].object_map[nb].sprite[1], game->
    scene[scene].object_map[nb].texture[1], sfTrue);
    sfSprite_setTexture(game->scene[scene].object_map[nb].sprite[2], game->
    scene[scene].object_map[nb].texture[2], sfTrue);
    initialize_obj_map_hitbox(game->scene[scene].object_map);
    initialize_obj_map_rect(game->scene[scene].object_map);
    sfRectangleShape_setOutlineColor(game->scene[scene].object_map->rect[2],
    sfRed);
}

void initialize_obj_map(game_t *game, int nb, int scene)
{
    game->scene[scene].object_map[nb].sprite = malloc(sizeof(sfSprite*) * 3);
    game->scene[scene].object_map[nb].texture = malloc(sizeof(sfTexture*) *
    3);
    game->scene[scene].object_map[nb].animation = malloc(sizeof(sfIntRect) *
    2077);
    game->scene[scene].object_map[nb].rect = malloc(sizeof(sfRectangleShape*) *
    2077);
    game->scene[scene].object_map[nb].rectangle = malloc(sizeof(int*) * 2077);
    game->scene[scene].object_map[nb].str = load_file_in_mem
    ("./assets/calcques/obstacle.png.txt");
    game->scene[scene].object_map[nb].texture[0] = sfTexture_createFromFile
    ("./assets/calcques/ground.png", NULL);
    game->scene[scene].object_map[nb].texture[1] = sfTexture_createFromFile
    ("./assets/calcques/obstacle.png", NULL);
    game->scene[scene].object_map[nb].texture[2] = sfTexture_createFromFile
    ("./assets/calcques/travers.png", NULL);
    game->scene[scene].object_map[nb].sprite[0] = sfSprite_create();
    game->scene[scene].object_map[nb].sprite[1] = sfSprite_create();
    game->scene[scene].object_map[nb].sprite[2] = sfSprite_create();
    initialize_obj_map_one(game, nb, scene);
}

void initialize_obj_map_hitbox(object_map_t *object_map)
{
    object_map->rectangle[2077] = malloc(sizeof(int));
    object_map->rectangle[2077][0] = -1;
    char **tab = my_str_to_word_array(object_map->str, '\n');
    char **sous_tab;
    for (int i = 0; tab[i]; i++){
        sous_tab = my_str_to_word_array(tab[i], ',');
        object_map->rectangle[i] = malloc(sizeof(int) * 5);
        object_map->rectangle[i][4] = -1;
        for (int j = 0; sous_tab[j]; j++){
            object_map->rectangle[i][j] = my_getnbr(sous_tab[j]);
        }
    }
    free(sous_tab);
    free(tab);
}

void initialize_obj_map_rect(object_map_t *object_map)
{
    for (int i = 0; i < 2077; i++){
        object_map->animation[i] = (sfIntRect) {object_map->rectangle[i][0],
        object_map->rectangle[i][1], (object_map->rectangle[i][2] -
        object_map->rectangle[i][0]),
        (object_map->rectangle[i][3] - object_map->rectangle[i][1])};
        object_map->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(object_map->rect[i], (sfVector2f) {
            object_map->animation[i].left, object_map->animation[i].top});
        sfRectangleShape_setSize(object_map->rect[i], (sfVector2f) {object_map
        ->animation[i].width, object_map->animation[i].height});
        sfRectangleShape_setOutlineThickness(object_map->rect[i], 0.65);
        sfRectangleShape_setFillColor(object_map->rect[i], sfTransparent);
    }

}
