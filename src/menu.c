/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-gabriel.balcon
** File description:
** menu
*/

#include "../include/file.h"

void draw_main_menu(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->menu->back, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->menu->play, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->menu->quit, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->menu->option, NULL);
    sfRenderWindow_display(game->wdw);
}

void event_main_menu(game_t *game)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow
    (game->wdw);

    while (sfRenderWindow_pollEvent(game->wdw, &game->event)) {
        if (game->event.type == sfEvtClosed ||
        (game->event.type == sfEvtMouseButtonPressed &&
        cursor.x >= 525 && cursor.x <= 762 && cursor.y >= 400 &&
        cursor.y <= 466) || game->event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->wdw);
        if ((game->event.type == sfEvtMouseButtonPressed &&
        cursor.x >= 525 && cursor.x <= 762 && cursor.y >= 200 &&
        cursor.y <= 266) || game->event.key.code == sfKeyP)
            game->menu->menu = 1;
        if (game->event.type == sfEvtMouseButtonPressed &&
        cursor.x >= 525 && cursor.x <= 762 &&
        cursor.y >= 300 && cursor.y <= 366)
            game->menu->menu = 2;
    }
}

void main_menu(game_t *game)
{
    event_main_menu(game);
    draw_main_menu(game);
}

void check_menu(game_t *game)
{
    if (game->menu->menu == 0)
        main_menu(game);
    if (game->menu->menu == 2)
        how_menu(game);
    if (game->menu->menu == 3)
        break_menu(game);
}

void make_sprite_menu(game_t *game)
{
    game->menu->text = sfTexture_createFromFile
    ("./assets/main_menu/main_menu.jpg", NULL);
    game->menu->back = sfSprite_create();
    sfSprite_setTexture(game->menu->back, game->menu->text, sfTrue);
    game->menu->textp = sfTexture_createFromFile
    ("./assets/main_menu/play.png", NULL);
    game->menu->play = sfSprite_create();
    sfSprite_setTexture(game->menu->play, game->menu->textp, sfTrue);
    sfSprite_setPosition(game->menu->play, (sfVector2f) {525, 200});
    game->menu->texto = sfTexture_createFromFile
    ("./assets/main_menu/option.png", NULL);
    game->menu->option = sfSprite_create();
    sfSprite_setTexture(game->menu->option, game->menu->texto, sfTrue);
    sfSprite_setPosition(game->menu->option, (sfVector2f) {525, 300});
    game->menu->textq = sfTexture_createFromFile
    ("./assets/main_menu/quit.png", NULL);
    game->menu->quit = sfSprite_create();
    sfSprite_setTexture(game->menu->quit, game->menu->textq, sfTrue);
    sfSprite_setPosition(game->menu->quit, (sfVector2f) {525, 400});
    make_sprite_htp(game);
}
