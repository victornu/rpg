/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main
*/

#include "../include/file.h"

// void detecte_collision(sfIntRect *rect_one, sfIntRect *rect_two)
// {
//     if (abs((rect_one->left + (rect_one->width / 2)) - (rect_two->left + (rect_one->width / 2))) < rect_two->width
//     && ((rect_one->top + (rect_one->height / 2)) - (rect_two->top + (rect_one->height / 2))) < rect_two->height){
//         printf("collision\n");
//         return 1;
//     }
//     return 0;
// }

void animation_charactere(game_t *game, int mode)
{
    game->scene->horloge->time = sfClock_getElapsedTime(game->scene->horloge->
    clock);
    game->scene->horloge->seconds = game->scene->horloge->time.microseconds /
    10000;
    if (game->scene->horloge->seconds > 9){
        movement_charactere(game, mode);
        movements_particul(game);
        sfClock_restart(game->scene->horloge->clock);
    }
}

int is_the_charactere_in_hitbox(sfIntRect *animation, sfVector2f player)
{
    for (int i = 0; i < 2077; i++){
        if (player.x >= animation[i].left && player.x <=
        (animation[i].width + animation[i].left) && player.y >=
        animation[i].top && player.y <=
        (animation[i].height + animation[i].top)){
            return 1;
        }
    }
    return 0;
}

int rpg(int ac, char **av)
{
    game_t *game = initialize_main();
    game->menu = malloc(sizeof(menu_t));
    game->menu->menu = 0;
    make_sprite_menu(game);
    sfRenderWindow_setFramerateLimit(game->wdw, 60);
    while (sfRenderWindow_isOpen(game->wdw)){
        if (game->menu->menu == 1){
            events_charactere_mooving(game);
            events_main(game);
            sfView_setCenter(game->view, game->scene->object->position);
            sfRenderWindow_setView(game->wdw, game->view);
            animation_charactere(game, game->scene->object->stat.stat);
            // detecte_collision(game->scene->object->rect, (sfIntRect) {game->scene->object[0].position_hitbox.x, game->scene->object->position_hitbox.y, game->scene->object->animation.width - 32, game->scene->object->animation.height - 22});
            draw_main(game);
        } else
            check_menu(game);
    }
}

char *load_file_in_mem(char const *filepath)
{
    int fd;
    char *buffer;
    int size = 0;

    struct stat *size_buff = malloc(sizeof(struct stat));
    stat(filepath, size_buff);
    buffer = malloc(sizeof(char) * size_buff->st_size + 1);
    buffer[size_buff->st_size] = '\0';
    fd = open(filepath, O_RDONLY);
    size = read(fd, buffer, size_buff->st_size);
    close(fd);
    free(size_buff);
    return (buffer);
}

int main(int ac, char **av)
{
    rpg(ac, av);
    return 0;
}
