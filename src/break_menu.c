/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** break_menu
*/

#include "../include/file.h"

void draw_break_menu(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->menu->back, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->menu->main, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->menu->game, NULL);
    sfRenderWindow_display(game->wdw);
}

void event_break_menu(game_t *game)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow
    (game->wdw);

    while (sfRenderWindow_pollEvent(game->wdw, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->wdw);
        if ((game->event.type == sfEvtMouseButtonPressed &&
        cursor.x >= 525 && cursor.x <= 762 && cursor.y >= 300 &&
        cursor.y <= 366))
            game->menu->menu = 0;
        if ((game->event.type == sfEvtMouseButtonPressed &&
        cursor.x >= 525 && cursor.x <= 762 && cursor.y >= 200 &&
        cursor.y <= 266) || game->event.key.code == sfKeyP)
            game->menu->menu = 1;
    }
}

void break_menu(game_t *game)
{
    event_break_menu(game);
    draw_break_menu(game);
}
