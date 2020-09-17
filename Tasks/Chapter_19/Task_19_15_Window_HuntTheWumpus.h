#ifndef TASK_19_15_WINDOW_HUNTTHEWUMPUS_H
#define TASK_19_15_WINDOW_HUNTTHEWUMPUS_H

#ifndef TASK_19_15_STDAFX_H
#include "Task_19_15_stdafx.h"
#endif

enum class stateShootMove
{
	none,
	shoot,
	move
};

const std::string gameOverPit = "You fell in pit! You lose! Press 'New game'";
const std::string gameOverWumpusKilledYou = "Wumpus killed you! Press 'New game'";
const std::string gameOverNoArrows = "No arrows! Press 'New game'";
const std::string gameOverYouKilledWumpus = "You killed Wumpus! Press 'New game'";
const std::string gameOverYouDead = "You are dead";
const std::string gameOverWumpusDead = "Wumpus is dead";

const std::string gameContinueBat = "The bat threw you into another room!";

class Window_HuntTheWumpus : public Window
{
public:
	Window_HuntTheWumpus();
	stateShootMove state;
private:
	Button buttonNewGame;

	Out_box boxMyRoomNumber;
	Out_box boxConnectedRooms;
	Out_box boxFeelings;
	Out_box boxBat;
	Out_box boxPit;
	Out_box boxWumpus;
	Out_box boxArrowsNumber;

	Button buttonShoot;
	Button buttonMove;
	Button buttonEnterRoom;
	In_box boxRoom;
	Out_box boxInstructions;
	Out_box boxError;

	In_box boxShootRoom1;
	In_box boxShootRoom2;
	In_box boxShootRoom3;
	In_box boxShootRoom4;
	In_box boxShootRoom5;

	Button buttonArrowFire;

	static void cbButtonNewGame(Address, Address pw);
	static void cbButtonShoot(Address, Address pw);
	static void cbButtonMove(Address, Address pw);
	static void cbButtonEnterRoom(Address, Address pw);
	static void cbButtonArrowFire(Address, Address pw);
	
	void newGame();
	void shootPressed();
	void movePressed();
	void enterRoom();
	void updateBoxes();
	void arrowFire();

	int roomsArrowFire;
	HuntTheWumpus::States gameState;
	bool checkArrowRoute(std::vector<HuntTheWumpus::Room*> rooms);

	HuntTheWumpus::GameWumpus* game;

	std::vector<Out_box*> map;
	std::vector<Out_box*> mapHasBat;
	std::vector<Out_box*> mapHasPit;

	Button buttonAddRoomHasBat;
	Button buttonAddRoomHasPit;
	Button buttonRemoveRoomHasBat;
	Button buttonRemoveRoomHasPit;
	In_box boxRoomHasBat;
	In_box boxRoomHasPit;

	static void cbButtonAddRoomHasBat(Address, Address pw);
	static void cbButtonAddRoomHasPit(Address, Address pw);
	static void cbButtonRemoveRoomHasBat(Address, Address pw);
	static void cbButtonRemoveRoomHasPit(Address, Address pw);

	void roomAddBat();
	void roomAddPit();
	void roomRemoveBat();
	void roomRemovePit();
};

#endif