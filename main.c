/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "include/my.h"

void	main_function()
{
	sfVideoMode	mode = {1920, 1080, 32};
	sfRenderWindow	*window;
	sfEvent	event;
	sfIntRect	rect;
	sfIntRect	*ptrrect = &rect;
	sfVector2f	scale;
	sfVector2f	origin;
	sfIntRect	rect2;
	sfIntRect	*ptrrect2 = &rect2;
	sfVector2f	scale2;
	int	reload = 0;
	char	*str;
	char	*str2;
	int	lives = 3;

	clocker.clock = sfClock_create();
	clocker2.clock = sfClock_create();
	clocker3.clock = sfClock_create();
	clocker4.clock = sfClock_create();
	rect.top = 0;
	rect.left = 0;
	rect.width = 109;
	rect.height = 110;
	rect2.top = 0;
	rect2.left = 0;
	rect2.width = 34;
	rect2.height = 30;
	window = sfRenderWindow_create(mode, "My_Casltevania_Hunter", sfResize | sfClose, NULL);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	sfRenderWindow_setFramerateLimit(window, 60);
	init_background();
	init_target();
	init_target2();
	init_target3();
	init_aim();
	init_death();
	init_score();
	init_gameover(lives);
	scale.x = 0.4;
	scale.y = 0.4;
	scale2.x = 2;
	scale2.y = 2;
	sfSprite_setScale(aim.sprite, scale);
	sfSprite_setScale(death.sprite, scale2);
	sfMusic_setVolume(background.music, 30);
	sfMusic_play(background.music);
	sfMusic_play(target.sound);
	origin.x = 220;
	origin.y = 220;
	sfSprite_setOrigin(aim.sprite, origin);
	while (sfRenderWindow_isOpen(window)) {
		aim.position.x = sfMouse_getPositionRenderWindow(window).x;
		aim.position.y = sfMouse_getPositionRenderWindow(window).y;
		set_position();
		move_position();
		init_clock();
		if (clocker.seconds > 0.05) {
			move_rect(ptrrect, 120, 354);
			sfClock_restart(clocker.clock);
		}
		if (clocker2.seconds > 0.07) {
			move_rect2(ptrrect2, 31, 80);
			sfClock_restart(clocker2.clock);
		}
		sfSprite_setTextureRect(target.sprite, rect);
		sfSprite_setTextureRect(target2.sprite, rect);
		sfSprite_setTextureRect(target3.sprite, rect);
		sfSprite_setTextureRect(death.sprite, rect2);
		str = conv(score.nb, alloc(score.nb));
		str2 = conv(lives, alloc(lives));
		sfText_setString(score.text, str);
		sfText_setString(life.text, str2);
		if (lives <= 0) {
			sfRenderWindow_clear(window, sfBlack);
			sfRenderWindow_drawSprite(window, life.sprite, NULL);
			sfRenderWindow_display(window);
			sfMusic_pause(background.music);
			while (sfRenderWindow_pollEvent(window, &event)){
				if (event.type == sfEvtMouseButtonPressed)
					sfMusic_play(life.music);
				if (event.type == sfEvtClosed)
					sfRenderWindow_close(window);
			}
		} else {
			while (sfRenderWindow_pollEvent(window, &event)) {
				death.position.x = -200;
				sfSprite_setPosition(death.sprite, death.position);
				if (reload == 1) {
					if (clocker4.seconds > 1){
						reload = 0;
					}
				} else {
					if (event.type == sfEvtMouseButtonPressed) {
						sfMusic_play(aim.sound);
						lives = hitbox(lives);
						reload = 1;
						sfClock_restart(clocker4.clock);
					}			
				}
				if (event.type == sfEvtClosed)
					sfRenderWindow_close(window);
			}
			draw(window);
		}
	}
	clean(window);
	free(str);
	free(str2);
}

int	main(int ac, char **av)
{
	if (ac >= 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			my_putstr("Usage : ./my_hunter\n\nDescription :\nThis is a mini-game based on the rule of Duck Hunt and the theme is a Casltevania theme.\nYou have to shoot the bats by clicking on it, but watch out you only have 3 life.\n");
		}
	}
	else
		main_function();
	return(0);
}
