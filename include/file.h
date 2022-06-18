/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** file
*/

#ifndef FILE_H_
    #define FILE_H_

    #include "struct.h"
    #include "my.h"

int main(int ac, char **av);
/*INITIALIZE*/
game_t *initialize_main(void);
void initialize_view(game_t *game);
void initialize_scene_one(game_t *game);
void initialize_timer_one(game_t *game, int nb, int scene);
void initialize_obj_map(game_t *game, int nb, int scene);
void initialize_obj_map_one(game_t *game, int nb, int scene);
void initialize_obj_map_hitbox(object_map_t *object_map);
void initialize_obj_map_rect(object_map_t *object_map);
void initialize_obj_particuls(game_t *game, int nb, int scene);
void initialize_obj_charactere(game_t *game, int nb, int scene);
void initialize_obj_charactere_one(game_t *game, int nb, int scene);
void initialize_obj_charactere_stat(game_t *game, int nb, int scene);
/*EVENTS*/
int events_main(game_t *game);
void events_charactere_mooving(game_t *game);
void events_charactere_mooving_set(game_t *game);
void events_charactere_hitting(game_t *game);
void events_charactere_running(game_t *game);
/*DRAW*/
void draw_main(game_t *game);
void draw_map(game_t *game);
/*MOVEMENT*/
void movement_charactere(game_t *game, int mode);
void movement_charactere_falling(game_t *game);
void movement_charactere_hitting(game_t *game);
void movement_charactere_running(game_t *game);
void movement_charactere_standing(game_t *game);

void movements_particul(game_t *game);

int is_the_charactere_in_hitbox(sfIntRect *animation, sfVector2f player);

void draw_main_menu(game_t *game);
void event_main_menu(game_t *game);
void main_menu(game_t *game);
void check_menu(game_t *game);
void make_sprite_menu(game_t *game);
void draw_how_menu(game_t *game);
void event_how_menu(game_t *game);
void how_menu(game_t *game);
void make_sprite_htp(game_t *game);
void draw_break_menu(game_t *game);
void event_break_menu(game_t *game);
void break_menu(game_t *game);
#endif/* !FILE_H_ */
