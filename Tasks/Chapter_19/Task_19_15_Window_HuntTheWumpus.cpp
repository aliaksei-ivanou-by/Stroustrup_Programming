#include "Task_19_15_Window_HuntTheWumpus.h"

Window_HuntTheWumpus::Window_HuntTheWumpus() :
	Window{ Point{ 10, 10 }, 800, 530, "Hunt the Wumpus" },
	buttonNewGame{ Point{10, 10}, 300, 30, "New Game 'Hunt the Wumpus'", cbButtonNewGame },
	boxMyRoomNumber{ Point{10, 50}, 300, 30, "" },
	boxConnectedRooms{ Point{10, 90}, 300, 30, "" },
	boxArrowsNumber{ Point{10, 130}, 300, 30, "" },
	boxFeelings{ Point{10, 170}, 300, 30, "" },
	boxBat{ Point{10, 210}, 300, 30, "" },
	boxPit{ Point{10, 250}, 300, 30, "" },
	boxWumpus{ Point{10, 290}, 300, 30, "" },
	buttonShoot{ Point{x_max() - 210, 10}, 100, 30, "Shoot?", cbButtonShoot },
	buttonMove{ Point{x_max() - 110, 10}, 100, 30, "Move?", cbButtonMove },
	boxInstructions{ Point{x_max() - 210, 50}, 200, 30, "" },
	boxRoom{ Point{x_max() - 150, 90}, 100, 30, "Room" },
	buttonEnterRoom{ Point{x_max() - 40, 90}, 30, 30, "OK", cbButtonEnterRoom },
	boxError{ Point{x_max() - 210, 130}, 200, 30, "" },
	state{ stateShootMove::none },
	buttonArrowFire{ Point{x_max() - 250, 290}, 180, 30, "Arrow fire", cbButtonArrowFire },
	boxShootRoom1{ Point{x_max() - 250, 170}, 50, 30, "Room 1" },
	boxShootRoom2{ Point{x_max() - 120, 170}, 50, 30, "Room 2" },
	boxShootRoom3{ Point{x_max() - 250, 210}, 50, 30, "Room 3" },
	boxShootRoom4{ Point{x_max() - 120, 210}, 50, 30, "Room 4" },
	boxShootRoom5{ Point{x_max() - 185, 250}, 50, 30, "Room 5" },
	boxRoomHasBat{ Point{x_max() / 2 - 30, 10}, 50, 30, "Room" },
	buttonAddRoomHasBat{ Point{x_max() / 2 - 30, 50}, 100, 30, "Add Bat", cbButtonAddRoomHasBat },
	buttonRemoveRoomHasBat{ Point{x_max() / 2 - 30, 90}, 100, 30, "Remove Bat", cbButtonRemoveRoomHasBat },
	boxRoomHasPit{ Point{x_max() / 2 - 30, 150}, 50, 30, "Room" },
	buttonAddRoomHasPit{ Point{x_max()/ 2 - 30, 190}, 100, 30, "Add Pit", cbButtonAddRoomHasPit },
	buttonRemoveRoomHasPit{ Point{x_max() / 2 - 30, 230}, 100, 30, "Remove Pit", cbButtonRemoveRoomHasPit }
{
	attach(buttonNewGame);
	attach(boxMyRoomNumber);
	boxMyRoomNumber.hide();
	attach(boxConnectedRooms);
	boxConnectedRooms.hide();
	attach(boxArrowsNumber);
	boxArrowsNumber.hide();
	attach(boxFeelings);
	boxFeelings.hide();
	attach(boxBat);
	boxBat.hide();
	attach(boxPit);
	boxPit.hide();
	attach(boxWumpus);
	boxWumpus.hide();
	attach(buttonShoot);
	buttonShoot.hide();
	attach(boxRoom);
	boxRoom.hide();
	attach(buttonEnterRoom);
	buttonEnterRoom.hide();
	attach(buttonMove);
	buttonMove.hide();
	attach(boxError);
	boxError.put("");
	boxError.hide();
	attach(boxInstructions);
	boxInstructions.put("");
	boxInstructions.hide();
	attach(boxShootRoom1);
	boxShootRoom1.hide();
	attach(boxShootRoom2);
	boxShootRoom2.hide();
	attach(boxShootRoom3);
	boxShootRoom3.hide();
	attach(boxShootRoom4);
	boxShootRoom4.hide();
	attach(boxShootRoom5);
	boxShootRoom5.hide();
	attach(buttonArrowFire);
	buttonArrowFire.hide();
	int mapHeight = 30;
	int mapWidth = 100;
	map.push_back(new Out_box{ Point{10, 330}, mapWidth, mapHeight, "" }); // 1
	map.push_back(new Out_box{ Point{210, 330}, mapWidth, mapHeight, "" }); // 2
	map.push_back(new Out_box{ Point{410, 330}, mapWidth, mapHeight, "" }); // 3
	map.push_back(new Out_box{ Point{610, 330}, mapWidth, mapHeight, "" }); // 4

	map.push_back(new Out_box{ Point{10, 370}, mapWidth, mapHeight, "" }); // 5
	map.push_back(new Out_box{ Point{210, 370}, mapWidth, mapHeight, "" }); // 6
	map.push_back(new Out_box{ Point{410, 370}, mapWidth, mapHeight, "" }); // 7
	map.push_back(new Out_box{ Point{610, 370}, mapWidth, mapHeight, "" }); // 8

	map.push_back(new Out_box{ Point{10, 410}, mapWidth, mapHeight, "" }); // 9
	map.push_back(new Out_box{ Point{210, 410}, mapWidth, mapHeight, "" }); // 10
	map.push_back(new Out_box{ Point{410, 410}, mapWidth, mapHeight, "" }); // 11
	map.push_back(new Out_box{ Point{610, 410}, mapWidth, mapHeight, "" }); // 12

	map.push_back(new Out_box{ Point{10, 450}, mapWidth, mapHeight, "" }); // 13
	map.push_back(new Out_box{ Point{210, 450}, mapWidth, mapHeight, "" }); // 14
	map.push_back(new Out_box{ Point{410, 450}, mapWidth, mapHeight, "" }); // 15
	map.push_back(new Out_box{ Point{610, 450}, mapWidth, mapHeight, "" }); // 16

	map.push_back(new Out_box{ Point{10, 490}, mapWidth, mapHeight, "" }); // 17
	map.push_back(new Out_box{ Point{210, 490}, mapWidth, mapHeight, "" }); // 18
	map.push_back(new Out_box{ Point{410, 490}, mapWidth, mapHeight, "" }); // 19
	map.push_back(new Out_box{ Point{610, 490}, mapWidth, mapHeight, "" }); // 20
	for (auto& i : map)
	{
		attach(*i);
		i->hide();
	}
	attach(buttonAddRoomHasBat);
	buttonAddRoomHasBat.hide();
	attach(buttonAddRoomHasPit);
	buttonAddRoomHasPit.hide();
	attach(buttonRemoveRoomHasBat);
	buttonRemoveRoomHasBat.hide();
	attach(buttonRemoveRoomHasPit);
	buttonRemoveRoomHasPit.hide();
	attach(boxRoomHasBat);
	boxRoomHasBat.hide();
	attach(boxRoomHasPit);
	boxRoomHasPit.hide();

	int mapHasBatHeight = 30;
	int mapHasBatWidth = 30;
	mapHasBat.push_back(new Out_box{ Point{110, 330}, mapHasBatWidth, mapHasBatHeight, "" }); // 1
	mapHasBat.push_back(new Out_box{ Point{310, 330}, mapHasBatWidth, mapHasBatHeight, "" }); // 2
	mapHasBat.push_back(new Out_box{ Point{510, 330}, mapHasBatWidth, mapHasBatHeight, "" }); // 3
	mapHasBat.push_back(new Out_box{ Point{710, 330}, mapHasBatWidth, mapHasBatHeight, "" }); // 4

	mapHasBat.push_back(new Out_box{ Point{110, 370}, mapHasBatWidth, mapHasBatHeight, "" }); // 5
	mapHasBat.push_back(new Out_box{ Point{310, 370}, mapHasBatWidth, mapHasBatHeight, "" }); // 6
	mapHasBat.push_back(new Out_box{ Point{510, 370}, mapHasBatWidth, mapHasBatHeight, "" }); // 7
	mapHasBat.push_back(new Out_box{ Point{710, 370}, mapHasBatWidth, mapHasBatHeight, "" }); // 8

	mapHasBat.push_back(new Out_box{ Point{110, 410}, mapHasBatWidth, mapHasBatHeight, "" }); // 9
	mapHasBat.push_back(new Out_box{ Point{310, 410}, mapHasBatWidth, mapHasBatHeight, "" }); // 10
	mapHasBat.push_back(new Out_box{ Point{510, 410}, mapHasBatWidth, mapHasBatHeight, "" }); // 11
	mapHasBat.push_back(new Out_box{ Point{710, 410}, mapHasBatWidth, mapHasBatHeight, "" }); // 12

	mapHasBat.push_back(new Out_box{ Point{110, 450}, mapHasBatWidth, mapHasBatHeight, "" }); // 13
	mapHasBat.push_back(new Out_box{ Point{310, 450}, mapHasBatWidth, mapHasBatHeight, "" }); // 14
	mapHasBat.push_back(new Out_box{ Point{510, 450}, mapHasBatWidth, mapHasBatHeight, "" }); // 15
	mapHasBat.push_back(new Out_box{ Point{710, 450}, mapHasBatWidth, mapHasBatHeight, "" }); // 16

	mapHasBat.push_back(new Out_box{ Point{110, 490}, mapHasBatWidth, mapHasBatHeight, "" }); // 17
	mapHasBat.push_back(new Out_box{ Point{310, 490}, mapHasBatWidth, mapHasBatHeight, "" }); // 18
	mapHasBat.push_back(new Out_box{ Point{510, 490}, mapHasBatWidth, mapHasBatHeight, "" }); // 19
	mapHasBat.push_back(new Out_box{ Point{710, 490}, mapHasBatWidth, mapHasBatHeight, "" }); // 20
	for (auto& i : mapHasBat)
	{
		attach(*i);
		i->hide();
	}
	int mapHasPitHeight = 30;
	int mapHasPitWidth = 30;
	mapHasPit.push_back(new Out_box{ Point{140, 330}, mapHasPitWidth, mapHasPitHeight, "" }); // 1
	mapHasPit.push_back(new Out_box{ Point{340, 330}, mapHasPitWidth, mapHasPitHeight, "" }); // 2
	mapHasPit.push_back(new Out_box{ Point{540, 330}, mapHasPitWidth, mapHasPitHeight, "" }); // 3
	mapHasPit.push_back(new Out_box{ Point{740, 330}, mapHasPitWidth, mapHasPitHeight, "" }); // 4

	mapHasPit.push_back(new Out_box{ Point{140, 370}, mapHasPitWidth, mapHasPitHeight, "" }); // 5
	mapHasPit.push_back(new Out_box{ Point{340, 370}, mapHasPitWidth, mapHasPitHeight, "" }); // 6
	mapHasPit.push_back(new Out_box{ Point{540, 370}, mapHasPitWidth, mapHasPitHeight, "" }); // 7
	mapHasPit.push_back(new Out_box{ Point{740, 370}, mapHasPitWidth, mapHasPitHeight, "" }); // 8

	mapHasPit.push_back(new Out_box{ Point{140, 410}, mapHasPitWidth, mapHasPitHeight, "" }); // 9
	mapHasPit.push_back(new Out_box{ Point{340, 410}, mapHasPitWidth, mapHasPitHeight, "" }); // 10
	mapHasPit.push_back(new Out_box{ Point{540, 410}, mapHasPitWidth, mapHasPitHeight, "" }); // 11
	mapHasPit.push_back(new Out_box{ Point{740, 410}, mapHasPitWidth, mapHasPitHeight, "" }); // 12

	mapHasPit.push_back(new Out_box{ Point{140, 450}, mapHasPitWidth, mapHasPitHeight, "" }); // 13
	mapHasPit.push_back(new Out_box{ Point{340, 450}, mapHasPitWidth, mapHasPitHeight, "" }); // 14
	mapHasPit.push_back(new Out_box{ Point{540, 450}, mapHasPitWidth, mapHasPitHeight, "" }); // 15
	mapHasPit.push_back(new Out_box{ Point{740, 450}, mapHasPitWidth, mapHasPitHeight, "" }); // 16

	mapHasPit.push_back(new Out_box{ Point{140, 490}, mapHasPitWidth, mapHasPitHeight, "" }); // 17
	mapHasPit.push_back(new Out_box{ Point{340, 490}, mapHasPitWidth, mapHasPitHeight, "" }); // 18
	mapHasPit.push_back(new Out_box{ Point{540, 490}, mapHasPitWidth, mapHasPitHeight, "" }); // 19
	mapHasPit.push_back(new Out_box{ Point{740, 490}, mapHasPitWidth, mapHasPitHeight, "" }); // 20
	for (auto& i : mapHasPit)
	{
		attach(*i);
		i->hide();
	}
}

void Window_HuntTheWumpus::cbButtonNewGame(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).newGame();
}

void Window_HuntTheWumpus::cbButtonShoot(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).shootPressed();
}

void Window_HuntTheWumpus::cbButtonMove(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).movePressed();
}

void Window_HuntTheWumpus::cbButtonEnterRoom(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).enterRoom();
}

void Window_HuntTheWumpus::cbButtonArrowFire(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).arrowFire();
}

void Window_HuntTheWumpus::cbButtonAddRoomHasBat(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).roomAddBat();
}

void Window_HuntTheWumpus::cbButtonAddRoomHasPit(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).roomAddPit();
}

void Window_HuntTheWumpus::cbButtonRemoveRoomHasBat(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).roomRemoveBat();
}

void Window_HuntTheWumpus::cbButtonRemoveRoomHasPit(Address, Address pw)
{
	reference_to<Window_HuntTheWumpus>(pw).roomRemovePit();
}

void Window_HuntTheWumpus::newGame()
{
	for (auto& i : map)
	{
		i->put("");
	}
	for (auto& i : mapHasBat)
	{
		i->put("");
	}
	for (auto& i : mapHasPit)
	{
		i->put("");
	}
	delete game;
	game = new HuntTheWumpus::GameWumpus();
	boxMyRoomNumber.show();
	boxConnectedRooms.show();
	boxArrowsNumber.show();
	boxFeelings.show();
	boxPit.show();
	boxBat.show();
	boxWumpus.show();
	buttonShoot.show();
	buttonMove.show();
	boxError.hide();
	boxInstructions.hide();
	boxRoom.hide();
	buttonArrowFire.hide();
	buttonEnterRoom.hide();
	updateBoxes();
	for (auto& i : map)
	{
		i->show();
	}
	for (auto& i : mapHasBat)
	{
		i->hide();
	}
	for (auto& i : mapHasPit)
	{
		i->hide();
	}
	boxRoomHasBat.show();
	boxRoomHasPit.show();
	buttonAddRoomHasBat.show();
	buttonAddRoomHasPit.show();
	buttonRemoveRoomHasBat.show();
	buttonRemoveRoomHasPit.show();
}

void Window_HuntTheWumpus::shootPressed()
{
	state = stateShootMove::shoot;
	boxInstructions.put("Enter number of rooms - 1...5");
	boxInstructions.show();
	boxRoom.show();
	buttonEnterRoom.show();
}

void Window_HuntTheWumpus::movePressed()
{
	state = stateShootMove::move;
	boxInstructions.put("Enter room number");
	boxInstructions.show();
	boxRoom.show();
	buttonEnterRoom.show();
}

void Window_HuntTheWumpus::enterRoom()
try
{
	boxError.hide();
	int roomNumber = std::stoi(boxRoom.get_string());
	switch (state)
	{
	case stateShootMove::move:
	{
		if ((roomNumber > 20) || (roomNumber < 1))
		{
			boxError.put("Number must be 1 ...20!");
			boxError.show();
		}
		else
		{
			bool isContains = false;
			for (auto& i : game->cave.get_player_location()->connected_rooms)
			{
				if (roomNumber == i->id)
				{
					isContains = true;
				}
			}
			if (isContains)
			{
				game->cave.player_move(roomNumber);
				updateBoxes();
				if (game->cave.get_player_location() == game->cave.get_wumpus_location())
				{
					boxWumpus.put("Wumpus!");
					game->cave.wumpus_move();
					if (game->cave.get_player_location() == game->cave.get_wumpus_location())
					{
						boxMyRoomNumber.put(gameOverWumpusKilledYou);
						boxWumpus.hide();
						boxPit.hide();
						boxConnectedRooms.hide();
						boxArrowsNumber.hide();
						boxFeelings.hide();
						boxWumpus.hide();
						boxBat.hide();
						buttonEnterRoom.hide();
						boxError.hide();
						boxInstructions.hide();
						boxRoom.hide();
						buttonMove.hide();
						buttonShoot.hide();
					}
				}
				while (game->cave.get_player_location()->has_bat)
				{
					boxBat.put(gameContinueBat);
					game->cave.bat_move();
				}
				if (game->cave.get_player_location()->has_pit)
				{
					boxMyRoomNumber.put(gameOverPit);
					boxWumpus.hide();
					boxPit.hide();
					boxConnectedRooms.hide();
					boxArrowsNumber.hide();
					boxFeelings.hide();
					boxWumpus.hide();
					boxBat.hide();
					buttonEnterRoom.hide();
					boxError.hide();
					boxInstructions.hide();
					boxRoom.hide();
					buttonMove.hide();
					buttonShoot.hide();
				}
			}
			else
			{
				size_t i;
				std::string connectedRooms = "";
				for (i = 0; i < game->cave.get_player_location()->connected_rooms.size() - 1; ++i)
				{
					connectedRooms +=
						std::to_string(game->cave.get_player_location()->connected_rooms[i]->id) + ", ";
				}
				connectedRooms +=
					std::to_string(game->cave.get_player_location()->connected_rooms[i]->id);
				boxError.put("Only to " + connectedRooms + " rooms");
				boxError.show();
			}
		}
		break;
	}
	case stateShootMove::shoot:
	{
		roomsArrowFire = std::stoi(boxRoom.get_string());
		switch (roomsArrowFire)
		{
		case (1):
		{
			boxShootRoom1.show();
			buttonArrowFire.show();
			break;
		}
		case (2):
		{
			boxShootRoom1.show();
			boxShootRoom2.show();
			buttonArrowFire.show();
			break;
		}
		case (3):
		{
			boxShootRoom1.show();
			boxShootRoom2.show();
			boxShootRoom3.show();
			buttonArrowFire.show();
			break;
		}
		case (4):
		{
			boxShootRoom1.show();
			boxShootRoom2.show();
			boxShootRoom3.show();
			boxShootRoom4.show();
			buttonArrowFire.show();
			break;
		}
		case (5):
		{
			boxShootRoom1.show();
			boxShootRoom2.show();
			boxShootRoom3.show();
			boxShootRoom4.show();
			boxShootRoom5.show();
			buttonArrowFire.show();
			break;
		}
		default:
		{
			boxShootRoom1.hide();
			boxShootRoom2.hide();
			boxShootRoom3.hide();
			boxShootRoom4.hide();
			boxShootRoom5.hide();
			boxError.put("Number 1...5!");
			boxError.show();
		}
		}
	}
	}
}
catch (...)
{
	boxError.put("Enter room number");
	boxError.show();
}

void Window_HuntTheWumpus::arrowFire()
{
	buttonArrowFire.hide();
	std::vector<int> roomsArrow;
	switch (roomsArrowFire)
	{
	case (1):
	{
		boxShootRoom1.hide();
		roomsArrow.push_back(std::stoi(boxShootRoom1.get_string()));
		break;
	}
	case (2):
	{
		boxShootRoom1.hide();
		boxShootRoom2.hide();
		roomsArrow.push_back(std::stoi(boxShootRoom1.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom2.get_string()));
		break;
	}
	case (3):
	{
		boxShootRoom1.hide();
		boxShootRoom2.hide();
		boxShootRoom3.hide();
		roomsArrow.push_back(std::stoi(boxShootRoom1.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom2.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom3.get_string()));
		break;
	}
	case (4):
	{
		boxShootRoom1.hide();
		boxShootRoom2.hide();
		boxShootRoom3.hide();
		boxShootRoom4.hide();
		roomsArrow.push_back(std::stoi(boxShootRoom1.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom2.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom3.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom4.get_string()));
		break;
	}
	case (5):
	{
		boxShootRoom1.hide();
		boxShootRoom2.hide();
		boxShootRoom3.hide();
		boxShootRoom4.hide();
		boxShootRoom5.hide();
		roomsArrow.push_back(std::stoi(boxShootRoom1.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom2.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom3.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom4.get_string()));
		roomsArrow.push_back(std::stoi(boxShootRoom5.get_string()));
		break;
	}
	}
	int roomNumber;
	std::vector<HuntTheWumpus::Room*> route(roomsArrowFire);
	while (true)
	{
		for (int i = 0; i < roomsArrowFire; ++i)
		{
			roomNumber = 0;
			while ((roomNumber < 1) || (roomNumber > game->cave.get_rooms_number()))
			{
				roomNumber = roomsArrow[i];
				if ((roomNumber > game->cave.get_rooms_number()) || (roomNumber < 1))
				{
					boxError.put("Number must be 1 ...20!");
					return;
				}
			}
			route[i] = game->cave.room_by_number(roomNumber);
		}
		if (checkArrowRoute(route))
		{
			break;
		}
		if (!checkArrowRoute(route))
		{
			return;
		}
	}
	HuntTheWumpus::Room* arrow_loc = game->cave.get_player_location();
	for (size_t i = 0; i < route.size(); ++i)
	{
		if (is_connected(arrow_loc->connected_rooms, route[i]))
		{
			arrow_loc = route[i];
		}
		else
		{
			arrow_loc = arrow_loc->connected_rooms[(rand() % 2)];
		}
		if (arrow_loc == game->cave.get_wumpus_location())
		{
			gameState = HuntTheWumpus::States::wumpus_dead;
			boxMyRoomNumber.put(gameOverWumpusDead);
			boxWumpus.hide();
			boxPit.hide();
			boxConnectedRooms.hide();
			boxArrowsNumber.hide();
			boxFeelings.hide();
			boxWumpus.hide();
			boxBat.hide();
			buttonEnterRoom.hide();
			boxError.hide();
			boxInstructions.hide();
			boxRoom.hide();
			buttonMove.hide();
			buttonShoot.hide();
			return;
		}
		if (arrow_loc == game->cave.get_player_location())
		{
			gameState = HuntTheWumpus::States::player_dead;
			boxMyRoomNumber.put(gameOverYouDead);
			boxWumpus.hide();
			boxPit.hide();
			boxConnectedRooms.hide();
			boxArrowsNumber.hide();
			boxFeelings.hide();
			boxWumpus.hide();
			boxBat.hide();
			buttonEnterRoom.hide();
			boxError.hide();
			boxInstructions.hide();
			boxRoom.hide();
			buttonMove.hide();
			buttonShoot.hide();
			return;
		}
	}
	game->cave.arrows_reduce();
	if (game->cave.get_arrows_number() == 0)
	{
		gameState = HuntTheWumpus::States::no_arrows;
		boxMyRoomNumber.put(gameOverNoArrows);
		boxWumpus.hide();
		boxPit.hide();
		boxConnectedRooms.hide();
		boxArrowsNumber.hide();
		boxFeelings.hide();
		boxWumpus.hide();
		boxBat.hide();
		buttonEnterRoom.hide();
		boxError.hide();
		boxInstructions.hide();
		boxRoom.hide();
		buttonMove.hide();
		buttonShoot.hide();
		return;
	}
	gameState = HuntTheWumpus::States::game_continue;
	updateBoxes();
	return;
}

bool Window_HuntTheWumpus::checkArrowRoute(std::vector<HuntTheWumpus::Room*> rooms)
{
	if (rooms.size() < 1 || rooms.size() > 5)
	{
		boxError.put("Route is wrong");
		return false;
	}
	else
	{
		for (int i = 2; i < rooms.size(); ++i)
		{
			if (rooms[i] == rooms[i - 2])
			{
				boxError.put("Route is wrong");
				return false;
			}
		}
	}
	return true;
}

void Window_HuntTheWumpus::updateBoxes()
{
	// Default
	boxMyRoomNumber.put("");
	boxConnectedRooms.put("");
	boxFeelings.put("");
	boxBat.put("");
	boxPit.put("");
	boxWumpus.put("");
	boxArrowsNumber.put("");

	// My Room
	boxMyRoomNumber.put("You are in room " + std::to_string(game->cave.get_player_location()->id));

	// Connected Rooms
	std::string connectedRooms = "";
	size_t i;
	for (i = 0; i < game->cave.get_player_location()->connected_rooms.size() - 1; ++i)
	{
		connectedRooms +=
			std::to_string(game->cave.get_player_location()->connected_rooms[i]->id) + ", ";
	}
	connectedRooms +=
		std::to_string(game->cave.get_player_location()->connected_rooms[i]->id);
	boxConnectedRooms.put("This room is connected with " + connectedRooms);

	map[game->cave.get_player_location()->id - 1]->put(
		std::to_string(game->cave.get_player_location()->id) + "->" + connectedRooms);

	// Arrows Number
	boxArrowsNumber.put("Arrows number is " + std::to_string(game->cave.get_arrows_number()));

	// Feelings
	for (auto& i : game->cave.get_player_location()->connected_rooms)
	{
		if (i == game->cave.get_wumpus_location())
		{
			boxWumpus.put("I smell a Wumpus!");
		}
	}
	for (auto& i : game->cave.get_player_location()->connected_rooms)
	{
		if (i->has_pit)
		{
			boxFeelings.put("I feel the breeze!");
		}
		if (i->has_bat)
		{
			boxFeelings.put("I hear the bat!");
		}
	}
}

void Window_HuntTheWumpus::roomAddBat()
try
{
	int room = std::stoi(boxRoomHasBat.get_string());
	if (room < 0 || room > 20)
	{
		return;
	}
	mapHasBat[room - 1]->put("Bat");
	mapHasBat[room - 1]->show();
}
catch (...)
{

}

void Window_HuntTheWumpus::roomAddPit()
try
{
	int room = std::stoi(boxRoomHasPit.get_string());
	if (room < 0 || room > 20)
	{
		return;
	}
	mapHasPit[room - 1]->put("Pit");
	mapHasPit[room - 1]->show();
}
catch (...)
{

}

void Window_HuntTheWumpus::roomRemoveBat()
try
{
	int room = std::stoi(boxRoomHasBat.get_string());
	if (room < 0 || room > 20)
	{
		return;
	}
	mapHasBat[room - 1]->put("");
	mapHasBat[room - 1]->hide();
}
catch (...)
{

}

void Window_HuntTheWumpus::roomRemovePit()
try
{
	int room = std::stoi(boxRoomHasPit.get_string());
	if (room < 0 || room > 20)
	{
		return;
	}
	mapHasPit[room - 1]->put("");
	mapHasPit[room - 1]->hide();
}
catch (...)
{

}