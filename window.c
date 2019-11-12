/*
** EPITECH PROJECT, 2017
** window
** File description:
** window_function
*/

#include "my.h"

void	init_background()
{
	background.texture = sfTexture_createFromFile("source/picture/background.png", NULL);
	background.sprite = sfSprite_create();
	sfSprite_setTexture(background.sprite, background.texture, sfTrue);
	background.music = sfMusic_createFromFile("source/sound/Castlevania_Symphony_of_the_Night_-_Dracula_s_Cast.ogg");
}

void	init_gameover(int lives)
{
	char	*str = conv(lives, alloc(lives));

	life.position.x = 1800;
	life.position.y = 100;
	life.texture = sfTexture_createFromFile("source/picture/game_over.png", NULL);
	life.sprite = sfSprite_create();
	sfSprite_setTexture(life.sprite, life.texture, sfTrue);
	life.music = sfMusic_createFromFile("source/sound/game_over_castlevania_symphony_of_the_nigh.ogg");
	life.font = sfFont_createFromFile("source/font/Ghost_Shadow.ttf");
	life.text = sfText_create();
	sfText_setString(life.text, str);
	sfText_setFont(life.text, life.font);
	sfText_setCharacterSize(life.text, 60);
	sfText_setPosition(life.text, life.position);
}

void	clean(sfRenderWindow* window)
{
	sfSprite_destroy(background.sprite);
	sfSprite_destroy(aim.sprite);
	sfSprite_destroy(target.sprite);
	sfSprite_destroy(target2.sprite);
	sfSprite_destroy(target3.sprite);
	sfSprite_destroy(death.sprite);
	sfTexture_destroy(aim.texture);
	sfTexture_destroy(background.texture);
	sfTexture_destroy(target.texture);
	sfTexture_destroy(target2.texture);
	sfTexture_destroy(target3.texture);
	sfTexture_destroy(death.texture);
	sfText_destroy(score.text);
	sfText_destroy(life.text);
	sfFont_destroy(score.font);
	sfFont_destroy(life.font);
	sfMusic_destroy(background.music);
	sfMusic_destroy(life.music);
	sfMusic_destroy(target.sound);
	sfMusic_destroy(death.sound);
	sfMusic_destroy(aim.sound);
	sfRenderWindow_destroy(window);
}

void	draw(sfRenderWindow* window)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, background.sprite, NULL);
	sfRenderWindow_drawText(window, score.text, NULL);
	sfRenderWindow_drawText(window, life.text, NULL);
	sfRenderWindow_drawSprite(window, target.sprite, NULL);
	sfRenderWindow_drawSprite(window, target2.sprite, NULL);
	sfRenderWindow_drawSprite(window, target3.sprite, NULL);
	sfRenderWindow_drawSprite(window, death.sprite, NULL);
	sfRenderWindow_drawSprite(window, aim.sprite, NULL);
	sfRenderWindow_display(window);
}
