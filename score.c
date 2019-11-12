/*
** EPITECH PROJECT, 2017
** score
** File description:
** score_functions
*/

#include "include/my.h"

int	hitbox1(int miss)
{
	if (aim.position.x >= target.position.x && aim.position.x <= target.position.x + 100 &&
	    aim.position.y >= target.position.y && aim.position.y <= target.position.y + 120) {
		death.position = target.position;
		sfSprite_setPosition(death.sprite, death.position);
		target.position.x = -354;
		sfMusic_play(death.sound);
		score.nb += 1;
		miss = 0;
	}
	return(miss);
}

int	hitbox2(int miss)
{
	if (aim.position.x >= target2.position.x && aim.position.x <= target2.position.x + 100 &&
	    aim.position.y >= target2.position.y && aim.position.y <= target2.position.y + 120) {
		death.position = target2.position;
		sfSprite_setPosition(death.sprite, death.position);
		target2.position.x = -354;
		sfMusic_play(death.sound);
		score.nb += 2;
		miss = 0;
	}
	return(miss);

}

int	hitbox3(int miss)
{
	if (aim.position.x >= target3.position.x && aim.position.x <= target3.position.x + 100 &&
	    aim.position.y >= target3.position.y && aim.position.y <= target3.position.y + 120) {
		death.position = target3.position;
		sfSprite_setPosition(death.sprite, death.position);
		target3.position.x = -220;
		sfMusic_play(death.sound);
		score.nb += 3;
		miss = 0;
	}
	return(miss);
}

int	hitbox(int lives)
{
	int	miss = 1;

	miss = hitbox1(miss);
	miss = hitbox2(miss);
	miss = hitbox3(miss);
	if (miss == 1)
		lives -= 1;
	return(lives);

}
void	init_score()
{
	char	*str = conv(score.nb, alloc(score.nb));

	score.nb = 0;
	score.position.x = 920;
	score.position.y = 900;
	score.font = sfFont_createFromFile("source/font/Ghost_Shadow.ttf");
	score.text = sfText_create();
	sfText_setString(score.text, str);
	sfText_setFont(score.text, score.font);
	sfText_setCharacterSize(score.text, 60);
	sfText_setPosition(score.text, score.position);
}
