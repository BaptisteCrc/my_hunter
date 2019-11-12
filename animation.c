/*
** EPITECH PROJECT, 2017
** animation
** File description:
** animation_function
*/

#include "include/my.h"

void	move_rect(sfIntRect *rect, int offset, int max_value)
{
	if (rect->left < max_value)
		rect->left += offset;
	else
		rect->left = 0;
}

void	move_rect2(sfIntRect *rect, int offset, int max_value)
{
	if (rect->left < max_value)
		rect->left += offset;
	else {
		if (rect->top < max_value) {
			rect->left = 0;
			rect->top += offset;
		} else {
			rect->top = 0;
			rect->left = 0;
		}
	}
}

void	set_position()
{
	sfSprite_setPosition(aim.sprite, aim.position);
	sfSprite_setPosition(target.sprite, target.position);
	sfSprite_setPosition(target2.sprite, target2.position);
	sfSprite_setPosition(target3.sprite, target3.position);
	target.position.x += 8;
	target2.position.x += 5;
	target2.position.y -= 6;
	target3.position.x += 7;
	target3.position.y -= 10;
}
void	move_position()
{
	if (target3.position.x > 600) {
		target3.position.x += 2;
		target3.position.y += 25;
	}
	if (target3.position.x > 1080) {
		target3.position.x = 0;
		target3.position.y = 1080;
	}
	if (target2.position.y < 0)
		target2.position.y = 1080;
	if (target2.position.x > 1920)
		target2.position.x = 0;
	if (target.position.x > 1920)
		target.position.x = 0;
}

void	init_clock()
{
	clocker.time = sfClock_getElapsedTime(clocker.clock);
	clocker.seconds = clocker.time.microseconds / 1000000.0;
	clocker2.time = sfClock_getElapsedTime(clocker2.clock);
	clocker2.seconds = clocker2.time.microseconds / 1000000.0;
	clocker3.time = sfClock_getElapsedTime(clocker3.clock);
	clocker3.seconds = clocker3.time.microseconds / 1000000.0;
	clocker4.time = sfClock_getElapsedTime(clocker4.clock);
	clocker4.seconds = clocker4.time.microseconds / 1000000.0;
}
