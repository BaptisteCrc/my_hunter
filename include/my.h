/*
** EPITECH PROJECT, 2017
** my
** File description:
** my
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>

struct background_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *music;
}background;

struct target_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfMusic *sound;
}target;

struct target2_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
}target2;

struct target3_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
}target3;

struct aim_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfMusic *sound;
}aim;

struct death_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *sound;
	sfVector2f position; 
}death;


struct clock_s
{
	sfClock *clock;
	sfTime time;
	float seconds;
}clocker;

struct clock2_s
{
	sfClock *clock;
	sfTime time;
	float seconds;
}clocker2;

struct clock3_s
{
	sfClock *clock;
	sfTime time;
	float seconds;
}clocker3;

struct clock4_s
{
	sfClock *clock;
	sfTime time;
	float seconds;
}clocker4;

struct score_s
{
	int	nb;
	sfFont* font;
	sfText* text;
	sfVector2f position;
}score;

struct life_s
{
	sfFont* font;
	sfText* text;
	sfVector2f position;
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *music;
}life;

void	clean(sfRenderWindow* window);
void	draw(sfRenderWindow* window);
void	init_background();
void	init_target();
void	init_target2();
void	init_target3();
void	init_death();
void	init_aim();
void	init_gameover(int lives);
void    init_clock();
void	init_score();
void	move_rect(sfIntRect *rect, int offset, int max_value);
void	move_rect2(sfIntRect *rect, int offset, int max_value);
void	set_position();
void	move_position();
int	hitbox1(int miss);
int	hitbox2(int miss);
int	hitbox3(int miss);
int	hitbox(int lives);
int	alloc(int num);
char	*conv(int num, int len);
void	my_putchar(char c);
void	my_putstr(char *str);
