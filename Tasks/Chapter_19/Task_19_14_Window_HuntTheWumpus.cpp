#include "Task_19_14_Window_HuntTheWumpus.h"

Window_HuntTheWumpus::Window_HuntTheWumpus() :
	Window{ Point{ 10, 10 }, 620, 530, "Hunt the Wumpus" },
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
	boxMap01{ Point{10, 330}, 150, 30, "" },
	boxMap02{ Point{160, 330}, 150, 30, "" },
	boxMap03{ Point{310, 330}, 150, 30, "" },
	boxMap04{ Point{460, 330}, 150, 30, "" },
	boxMap05{ Point{10, 370}, 150, 30, "" },
	boxMap06{ Point{160, 370}, 150, 30, "" },
	boxMap07{ Point{310, 370}, 150, 30, "" },
	boxMap08{ Point{460, 370}, 150, 30, "" },
	boxMap09{ Point{10, 410}, 150, 30, "" },
	boxMap10{ Point{160, 410}, 150, 30, "" },
	boxMap11{ Point{310, 410}, 150, 30, "" },
	boxMap12{ Point{460, 410}, 150, 30, "" },
	boxMap13{ Point{10, 450}, 150, 30, "" },
	boxMap14{ Point{160, 450}, 150, 30, "" },
	boxMap15{ Point{310, 450}, 150, 30, "" },
	boxMap16{ Point{460, 450}, 150, 30, "" },
	boxMap17{ Point{10, 490}, 150, 30, "" },
	boxMap18{ Point{160, 490}, 150, 30, "" },
	boxMap19{ Point{310, 490}, 150, 30, "" },
	boxMap20{ Point{460, 490}, 150, 30, "" }
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
	attach(boxMap01);
	boxMap01.hide();
	attach(boxMap02);
	boxMap02.hide();
	attach(boxMap03);
	boxMap03.hide();
	attach(boxMap04);
	boxMap04.hide();
	attach(boxMap05);
	boxMap05.hide();
	attach(boxMap06);
	boxMap06.hide();
	attach(boxMap07);
	boxMap07.hide();
	attach(boxMap08);
	boxMap08.hide();
	attach(boxMap09);
	boxMap09.hide();
	attach(boxMap10);
	boxMap10.hide();
	attach(boxMap11);
	boxMap11.hide();
	attach(boxMap12);
	boxMap12.hide();
	attach(boxMap13);
	boxMap13.hide();
	attach(boxMap14);
	boxMap14.hide();
	attach(boxMap15);
	boxMap15.hide();
	attach(boxMap16);
	boxMap16.hide();
	attach(boxMap17);
	boxMap17.hide();
	attach(boxMap18);
	boxMap18.hide();
	attach(boxMap19);
	boxMap19.hide();
	attach(boxMap20);
	boxMap20.hide();
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

void Window_HuntTheWumpus::newGame()
{
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
	boxMap01.hide();
	boxMap02.hide();
	boxMap03.hide();
	boxMap04.hide();
	boxMap05.hide();
	boxMap06.hide();
	boxMap07.hide();
	boxMap08.hide();
	boxMap09.hide();
	boxMap10.hide();
	boxMap11.hide();
	boxMap12.hide();
	boxMap13.hide();
	boxMap14.hide();
	boxMap15.hide();
	boxMap16.hide();
	boxMap17.hide();
	boxMap18.hide();
	boxMap19.hide();
	boxMap20.hide();
	boxError.hide();
	boxInstructions.hide();
	boxRoom.hide();
	buttonArrowFire.hide();
	buttonEnterRoom.hide();
	updateBoxes();
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
						boxMap01.hide();
						boxMap02.hide();
						boxMap03.hide();
						boxMap04.hide();
						boxMap05.hide();
						boxMap06.hide();
						boxMap07.hide();
						boxMap08.hide();
						boxMap09.hide();
						boxMap10.hide();
						boxMap11.hide();
						boxMap12.hide();
						boxMap13.hide();
						boxMap14.hide();
						boxMap15.hide();
						boxMap16.hide();
						boxMap17.hide();
						boxMap18.hide();
						boxMap19.hide();
						boxMap20.hide();
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
					boxMap01.hide();
					boxMap02.hide();
					boxMap03.hide();
					boxMap04.hide();
					boxMap05.hide();
					boxMap06.hide();
					boxMap07.hide();
					boxMap08.hide();
					boxMap09.hide();
					boxMap10.hide();
					boxMap11.hide();
					boxMap12.hide();
					boxMap13.hide();
					boxMap14.hide();
					boxMap15.hide();
					boxMap16.hide();
					boxMap17.hide();
					boxMap18.hide();
					boxMap19.hide();
					boxMap20.hide();
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
			boxMap01.hide();
			boxMap02.hide();
			boxMap03.hide();
			boxMap04.hide();
			boxMap05.hide();
			boxMap06.hide();
			boxMap07.hide();
			boxMap08.hide();
			boxMap09.hide();
			boxMap10.hide();
			boxMap11.hide();
			boxMap12.hide();
			boxMap13.hide();
			boxMap14.hide();
			boxMap15.hide();
			boxMap16.hide();
			boxMap17.hide();
			boxMap18.hide();
			boxMap19.hide();
			boxMap20.hide();
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
			boxMap01.hide();
			boxMap02.hide();
			boxMap03.hide();
			boxMap04.hide();
			boxMap05.hide();
			boxMap06.hide();
			boxMap07.hide();
			boxMap08.hide();
			boxMap09.hide();
			boxMap10.hide();
			boxMap11.hide();
			boxMap12.hide();
			boxMap13.hide();
			boxMap14.hide();
			boxMap15.hide();
			boxMap16.hide();
			boxMap17.hide();
			boxMap18.hide();
			boxMap19.hide();
			boxMap20.hide();
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
		boxMap01.hide();
		boxMap02.hide();
		boxMap03.hide();
		boxMap04.hide();
		boxMap05.hide();
		boxMap06.hide();
		boxMap07.hide();
		boxMap08.hide();
		boxMap09.hide();
		boxMap10.hide();
		boxMap11.hide();
		boxMap12.hide();
		boxMap13.hide();
		boxMap14.hide();
		boxMap15.hide();
		boxMap16.hide();
		boxMap17.hide();
		boxMap18.hide();
		boxMap19.hide();
		boxMap20.hide();
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

	mapUpdate(std::move(game->cave.get_player_location()->id), std::move(connectedRooms));

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

void Window_HuntTheWumpus::mapUpdate(const int& room, const std::string& connectedRooms)
{
	switch (room)
	{
	case (1):
	{
		boxMap01.put(std::to_string(room) + " -> " +connectedRooms);
		boxMap01.show();
		break;
	}
	case (2):
	{
		boxMap02.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap02.show();
		break;
	}
	case (3):
	{
		boxMap03.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap03.show();
		break;
	}
	case (4):
	{
		boxMap04.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap04.show();
		break;
	}
	case (5):
	{
		boxMap05.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap05.show();
		break;
	}
	case (6):
	{
		boxMap06.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap06.show();
		break;
	}
	case (7):
	{
		boxMap07.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap07.show();
		break;
	}
	case (8):
	{
		boxMap08.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap08.show();
		break;
	}
	case (9):
	{
		boxMap09.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap09.show();
		break;
	}
	case (10):
	{
		boxMap10.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap10.show();
		break;
	}
	case (11):
	{
		boxMap11.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap11.show();
		break;
	}
	case (12):
	{
		boxMap12.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap12.show();
		break;
	}
	case (13):
	{
		boxMap13.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap13.show();
		break;
	}
	case (14):
	{
		boxMap14.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap14.show();
		break;
	}
	case (15):
	{
		boxMap15.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap15.show();
		break;
	}
	case (16):
	{
		boxMap16.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap16.show();
		break;
	}
	case (17):
	{
		boxMap17.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap17.show();
		break;
	}
	case (18):
	{
		boxMap18.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap18.show();
		break;
	}
	case (19):
	{
		boxMap19.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap19.show();
		break;
	}
	case (20):
	{
		boxMap20.put(std::to_string(room) + " -> " + connectedRooms);
		boxMap20.show();
		break;
	}
	}
}