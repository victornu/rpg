/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** events
*/

#include "../include/file.h"

void events_charactere_running(game_t *game)
{
    if (game->event.key.code == sfKeyQ ||
    game->event.key.code == sfKeyZ || game->event.key.code == sfKeyS ||
    game->event.key.code == sfKeyD){
        game->scene->object->stat.stat = 2;
    }

    if (game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyQ
    || game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyZ
    || game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyS
    || game->event.type == sfEvtKeyReleased && game->event.key.code == sfKeyD){
        if (sfKeyboard_isKeyPressed(sfKeyZ) == sfFalse &&
        sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse &&
        sfKeyboard_isKeyPressed(sfKeyS) == sfFalse &&
        sfKeyboard_isKeyPressed(sfKeyD) == sfFalse){
            game->scene->object->stat.stat = 1;
        }
    }
}

void events_charactere_hitting(game_t *game)
{
    if (game->event.key.code == sfKeySpace){
        game->scene->object->stat.stat = 3;
    }
}

void events_charactere_mooving(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && is_the_charactere_in_hitbox
    (game->scene->object_map->animation, (sfVector2f) {game->scene->object->
    position_hitbox.x, (game->scene->object->position_hitbox.y - 5.0)}) == 0){
        game->scene->object->position.y -= 1.5;
        game->scene->object->position_hitbox.y -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && is_the_charactere_in_hitbox
    (game->scene->object_map->animation, (sfVector2f) {(game->scene->object->
    position_hitbox.x - 5.0), (game->scene->object->position_hitbox.y)}) == 0){
        game->scene->object->scale.x = -1;
        game->scene->object->position.x -= 1.5;
        game->scene->object->position_hitbox.x -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && is_the_charactere_in_hitbox
    (game->scene->object_map->animation, (sfVector2f) {(game->scene->object->
    position_hitbox.x), (game->scene->object->position_hitbox.y + 6.5)}) == 0){
        game->scene->object->position.y += 1.5;
        game->scene->object->position_hitbox.y += 1.5;
    }
    events_charactere_mooving_set(game);
}

void events_charactere_mooving_set(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) && is_the_charactere_in_hitbox
    (game->scene->object_map->animation, (sfVector2f) {(game->scene->object->
    position_hitbox.x + 5.0), (game->scene->object->position_hitbox.y)}) == 0){
        game->scene->object->scale.x = 1;
        game->scene->object->position.x += 1.5;
        game->scene->object->position_hitbox.x += 1.5;
    }
    sfSprite_setScale(game->scene->object->sprite, game->scene->object->scale);
    
    if (game->scene->object->scale.x == 1){
    sfSprite_setPosition(game->scene->object->sprite,
    game->scene->object->position);
    sfRectangleShape_setPosition(game->scene[0].object->rect,
    game->scene->object->position_hitbox);
    } else {
        sfSprite_setPosition(game->scene->object->sprite, (sfVector2f) {game->
        scene->object->position.x + game->scene->object->animation.width, game
        ->scene->object->position.y});
        sfRectangleShape_setPosition(game->scene[0].object->rect, (sfVector2f) 
        {game->scene->object->position_hitbox.x + game->scene->object->
        animation.width, game->scene->object->position_hitbox.y});
    }
}
int events_main(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->wdw, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->wdw);
        events_charactere_running(game);
        events_charactere_hitting(game);
    }
}