#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define FOV_ANGLE (60 * (M_PI / 180))
#define NUM_RAYS 300

typedef struct s_texture
{
    char *path;
} t_texture;

typedef struct s_color
{
    int r;
    int g;
    int b;
} t_color;

typedef struct s_ray
{
    double angle;
    double distance;
} t_ray;

typedef struct s_player
{
    double x;
    double y;
    double angle;
    double fov;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    int map[MAP_HEIGHT][MAP_WIDTH];
    t_texture no_texture;
    t_texture so_texture;
    t_texture we_texture;
    t_texture ea_texture;
    t_color floor_color;
    t_color ceiling_color;
    t_player player;
    t_ray rays[NUM_RAYS];
} t_game;

void parse_error(char *message)
{
    printf("Error\n%s\n", message);
    exit(EXIT_FAILURE);
}

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

void skip_whitespace(char **line)
{
    while (is_whitespace(**line))
        (*line)++;
}

void parse_resolution(char *line, t_game *game)
{
    int width, height;
    if (sscanf(line, "R %d %d", &width, &height) != 2)
        parse_error("Invalid resolution format");
    // Set the game window resolution with the obtained width and height
    // ...
}

void parse_texture(char *line, t_texture *texture)
{
    skip_whitespace(&line);
    texture->path = strdup(line);
    // Validate and handle the texture path
    // ...
}

void parse_color(char *line, t_color *color)
{
    int r, g, b;
    if (sscanf(line, "%*c %d,%d,%d", &r, &g, &b) != 3)
        parse_error("Invalid color format");
    color->r = r;
    color->g = g;
    color->b = b;
}

void parse_map(char *line, t_game *game)
{
    // Implement map parsing logic
    // ...
}

void parse_line(char *line, t_game *game)
{
    if (line[0] == 'R' && is_whitespace(line[1]))
        parse_resolution(line + 1, game);
    else if ((line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E') && line[1] == 'O' && is_whitespace(line[2]))
        parse_texture(line + 2, &game->no_texture);
    else if (line[0] == 'S' && line[1] == 'O' && is_whitespace(line[2]))
        parse_texture(line + 2, &game->so_texture);
    else if (line[0] == 'W' && line[1] == 'E' && is_whitespace(line[2]))
        parse_texture(line + 2, &game->we_texture);
    else if (line[0] == 'E' && line[1] == 'A' && is_whitespace(line[2]))
        parse_texture(line + 2, &game->ea_texture);
    else if (line[0] == 'F' && is_whitespace(line[1]))
        parse_color(line + 1, &game->floor_color);
    else if (line[0] == 'C' && is_whitespace(line[1]))
        parse_color(line + 1, &game->ceiling_color);
    else if (line[0] == '1' || line[0] == '0' || line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
        parse_map(line, game);
    else if (*line != '\0' && *line != '\n')
        parse_error("Invalid line in the map file");
}

void parse_game_file(char *filename, t_game *game)
{
    int fd;
    char *line = NULL;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        parse_error("Failed to open the file.");

    while (get_next_line(fd, &line) > 0)
    {
        parse_line(line, game);
        free(line);
    }

    close(fd);
}

void initialize_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, /*window_size*/, "cub3d");

    // Initialize other game state variables
    game->player.x = 2.0;
    game->player.y = 2.0;
    game->player.angle = 0.0;
    game->player.fov = FOV_ANGLE;

    // Initialize rays
    double ray_angle = game->player.angle - (game->player.fov / 2);
    for (int i = 0; i < NUM_RAYS; i++)
    {
        game->rays[i].angle = fmod((ray_angle + i * (FOV_ANGLE / NUM_RAYS)), 2 * M_PI);
        game->rays[i].distance = 0.0;
    }

    // Parse the game file and update the game structure accordingly.
    parse_game_file("example.game", game);
}

void cast_rays(t_game *game)
{
    // Implement raycasting logic
    // ...
}

void update_game(t_game *game)
{
    // Handle user input and update the game logic
    // ...

    // Cast rays and render the scene using Ray-Casting principles
    cast_rays(game);

    // Display the updated frame
    mlx_put_image_to_window(game->mlx, game->win, /*image_data*/, 0, 0);
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        parse_error("Usage: ./cub3d <filename.game>");

    initialize_game(&game);

    while (1)
    {
        update_game(&game);
    }

    return 0;
}
