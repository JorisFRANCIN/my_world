/*
** EPITECH PROJECT, 2021
** csfml.h
** File description:
** .h file
*/



#ifndef CSFML_H_
    #define CSFML_H_

    #include "my.h"
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>

    #define MAP_X 6
    #define MAP_Y 6
    #define ANGLE_X 45
    #define ANGLE_Y 35
    #define PIXEL 128
    #define HEIGHT 1920
    #define WIDTH 1080

    #define ERROR_FILE 84
    #define ERROR_ARG 84
    #define UNCORRECT_SIZE 84
    #define UNCORRECT_DIMENSION 84
    #define ERROR_PID 84
    #define UNCORRECT_FORMAT 84


typedef struct button_s {
    sfRectangleShape *rect;
    sfIntRect hitbox;
} button_t;

typedef struct board_s {
    button_t **buttons;
} board_t;

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
} asset;

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfClock *clock;
    sfMusic *music;
    asset *background;
    int tile_button;
    int corner_button;
    sfVector2i mouse;
} window_t;

typedef struct world_map_s {
    int **map;
    sfVector2f **projected_map;
    sfVector2f **original_map;
    int map_size;
    int pixel;
    sfConvexShape ***tiles;
    sfColor **color;
} world_map_t;

typedef struct scene_s {
    struct game_object_s *objs;
    struct button_s *buttons;
} scene_t;

int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
button_t *init_button(sfVector2f position, sfVector2f size, char *filename);
window_t *window_init(int height, int width);
void launch_game(window_t *this_one, int map_size);
sfMouseButtonEvent analyse_events(window_t *this_one, board_t *panel,
world_map_t *content);
int button_is_clicked(window_t *this_one, button_t *button,
sfVector2f click_position);
board_t *init_board(window_t *this_one);
void render(window_t *this_one, board_t *panel, world_map_t *map_content);
int **rand_map(int map_size);
struct game_object *create_object(const char *p, sfVector2f po,
sfIntRect rect);
world_map_t *rotate_left(world_map_t *content, int map_size, int map_size2);
world_map_t *rotate_right(world_map_t *content, int map_size, int map_size2);
sfVector2f **create_2d_map(world_map_t *map_content);
world_map_t *init_map(int map_size, window_t *this_one);
int draw_2d_map(window_t *this_one, world_map_t *content);
void update(window_t *this_one, board_t *panel, world_map_t *map_content);
world_map_t *center_it(world_map_t *map_content, window_t *this_one);
sfConvexShape ***create_tile(world_map_t *content);
world_map_t *transformation(window_t *this_one, world_map_t *content,
board_t *panel);
world_map_t *movement_ctrl(world_map_t *map_content, window_t *this_one);
world_map_t *move(world_map_t *content, int mx, int my);
int **default_gen(int **map, int map_size);
world_map_t *advance_events(window_t *this_one, world_map_t *content);
world_map_t *tile_event(window_t *this_one, world_map_t *content);
world_map_t *in_this_tile(world_map_t *content, window_t *this_one,
int i, int j);
sfColor color_index(window_t *this_one);
sfColor **color_select(int map_size);
void help(void);
#endif /* !CSFML_H_ */
