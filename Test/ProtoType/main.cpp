#include <iostream>
#include "Monster.h"

int main()
{
	//Spawner* ghostSpawner = new Spawner(spawnGhost);

	//Monster* ghost1 = ghostSpawner->spawnMonster();
	//Monster* ghost2 = ghostSpawner->spawnMonster();
	//Monster* ghost3 = ghostSpawner->spawnMonster();
	//Monster* ghost4 = ghostSpawner->spawnMonster();

	//delete ghost1;
	//delete ghost2;
	//delete ghost3;
	//delete ghost4;
	//delete ghostSpawner;

	Spawner* ghostSpawner = new SpawnerFor<Ghost>();

	return 0;
}