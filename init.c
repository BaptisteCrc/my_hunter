/*
** EPITECH PROJECT, 2017
** init
** File description:
** initialize_the_variable
*/

#include "include/my.h"

void	init_target()
{
	target.texture = sfTexture_createFromFile("source/sprite_sheet/sprite_target.png", NULL);
	target.sprite = sfSprite_create();
	sfSprite_setTexture(target.sprite, target.texture, sfTrue);
	target.sound = sfMusic_createFromFile("source/sound/bat_noise.ogg");
}

void	init_target2()
{
	sfVector2f	position;

	position.y = 520;
	target2.texture = sfTexture_createFromFile("source/sprite_sheet/sprite_target2.png", NULL);
	target2.sprite = sfSprite_create();
	sfSprite_setTexture(target2.sprite, target2.texture, sfTrue);
	sfSprite_setPosition(target2.sprite, position);
}

void	init_target3()
{
	sfVector2f	position;
	
	position.y = 1080;
	target3.texture = sfTexture_createFromFile("source/sprite_sheet/sprite_target3.png", NULL);
	target3.sprite = sfSprite_create();
	sfSprite_setTexture(target3.sprite, target3.texture, sfTrue);
	sfSprite_setPosition(target3.sprite, position);
}

void	init_death()
{
	death.texture = sfTexture_createFromFile("source/sprite_sheet/sprite_death.png", NULL);
	death.sprite = sfSprite_create();
	sfSprite_setTexture(death.sprite, death.texture, sfTrue);
	death.sound = sfMusic_createFromFile("source/sound/Small_Fireball.ogg");
}

void	init_aim()
{
	aim.texture = sfTexture_createFromFile("source/picture/cross_casltevania.png", NULL);
	aim.sprite = sfSprite_create();
	sfSprite_setTexture(aim.sprite, aim.texture, sfTrue);
	aim.sound = sfMusic_createFromFile("source/sound/Whip_Crack.ogg");

}
