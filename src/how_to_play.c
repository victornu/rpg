/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** how_to_play
*/

#include "../include/file.h"

void draw_how_menu(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->menu->htp, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->menu->main, NULL);
    sfRenderWindow_display(game->wdw);
}

void event_how_menu(game_t *game)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow
    (game->wdw);

    while (sfRenderWindow_pollEvent(game->wdw, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->wdw);
        if (game->event.type == sfEvtMouseButtonPressed &&
        cursor.x >= 525 && cursor.x <= 762 &&
        cursor.y >= 600 && cursor.y <= 666)
            game->menu->menu = 0;
    }
}

void how_menu(game_t *game)
{
    sfSprite_setPosition(game->menu->main, (sfVector2f) {525, 600});
    event_how_menu(game);
    draw_how_menu(game);
}

void make_sprite_htp(game_t *game)
{
    game->menu->texth = sfTexture_createFromFile
    ("./assets/main_menu/how_to_play.jpg", NULL);
    game->menu->htp = sfSprite_create();
    sfSprite_setTexture(game->menu->htp, game->menu->texth, sfTrue);
    game->menu->textg = sfTexture_createFromFile
    ("./assets/main_menu/game.png", NULL);
    game->menu->game = sfSprite_create();
    sfSprite_setTexture(game->menu->game, game->menu->textg, sfTrue);
    sfSprite_setPosition(game->menu->game, (sfVector2f) {525, 200});
    game->menu->textm = sfTexture_createFromFile
    ("./assets/main_menu/main.png", NULL);
    game->menu->main = sfSprite_create();
    sfSprite_setTexture(game->menu->main, game->menu->textm, sfTrue);
}
