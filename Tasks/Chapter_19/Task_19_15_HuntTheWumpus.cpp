#ifndef TASK_19_15_STDAFX
#include "Task_19_15_stdafx.h"
#include "Task_19_15_HuntTheWumpus.h"
#include "Task_19_15_Window_HuntTheWumpus.h"
#endif

namespace HuntTheWumpus
{
	Room::Room()
		: id{ 0 },
		has_pit{ false },
		has_bat{ false }
	{
	}

	Room::Room(int room_id, Room* connected_room1, Room* connected_room2, Room* connected_room3)
		: id{ room_id },
		connected_rooms{ 3 },
		has_pit{ false },
		has_bat{ false }
	{
		connected_rooms[0] = connected_room1;
		connected_rooms[1] = connected_room2;
		connected_rooms[2] = connected_room3;
	}

	bool is_connected(std::vector<Room*> connected_rooms, Room* room)
	{
		for (int i = 0; i < connected_rooms.size(); ++i)
		{
			if (connected_rooms[i] == room)
			{
				return true;
			}
		}
		return false;
	}

	Player::Player(Room* room)
		: location{ room },
		arrows_number{ 5 }
	{
	}

	Wumpus::Wumpus(Room* room)
		: location{ room }
	{
	}

	Cave::Cave()
		: rooms{ 20 },
		player{ 0 },
		wumpus{ 0 }
	{
		// generate cave
		srand(static_cast<int>(time(NULL)));
		std::vector<int> rooms_labels;
		for (size_t i = 0; i < rooms.size(); ++i)
		{
			rooms_labels.push_back(static_cast<int>(i + 1));
		}
		random_shuffle(rooms_labels.begin(), rooms_labels.end());
		rooms[0] = Room(rooms_labels[0], &rooms[1], &rooms[7], &rooms[19]);
		rooms[1] = Room(rooms_labels[1], &rooms[0], &rooms[2], &rooms[14]);
		rooms[2] = Room(rooms_labels[2], &rooms[1], &rooms[3], &rooms[6]);
		rooms[3] = Room(rooms_labels[3], &rooms[2], &rooms[4], &rooms[13]);
		rooms[4] = Room(rooms_labels[4], &rooms[3], &rooms[5], &rooms[11]);
		rooms[5] = Room(rooms_labels[5], &rooms[4], &rooms[6], &rooms[9]);
		rooms[6] = Room(rooms_labels[6], &rooms[2], &rooms[5], &rooms[7]);
		rooms[7] = Room(rooms_labels[7], &rooms[0], &rooms[6], &rooms[8]);
		rooms[8] = Room(rooms_labels[8], &rooms[7], &rooms[9], &rooms[18]);
		rooms[9] = Room(rooms_labels[9], &rooms[5], &rooms[8], &rooms[10]);
		rooms[10] = Room(rooms_labels[10], &rooms[9], &rooms[11], &rooms[17]);
		rooms[11] = Room(rooms_labels[11], &rooms[4], &rooms[10], &rooms[12]);
		rooms[12] = Room(rooms_labels[12], &rooms[11], &rooms[13], &rooms[16]);
		rooms[13] = Room(rooms_labels[13], &rooms[3], &rooms[12], &rooms[14]);
		rooms[14] = Room(rooms_labels[14], &rooms[1], &rooms[13], &rooms[15]);
		rooms[15] = Room(rooms_labels[15], &rooms[14], &rooms[16], &rooms[19]);
		rooms[16] = Room(rooms_labels[16], &rooms[12], &rooms[15], &rooms[17]);
		rooms[17] = Room(rooms_labels[17], &rooms[10], &rooms[16], &rooms[18]);
		rooms[18] = Room(rooms_labels[18], &rooms[8], &rooms[17], &rooms[19]);
		rooms[19] = Room(rooms_labels[19], &rooms[0], &rooms[15], &rooms[18]);
		std::vector<int> temp;
		for (size_t i = 0; i < rooms.size(); ++i)
		{
			temp.push_back(static_cast<int>(i));
		}
		random_shuffle(temp.begin(), temp.end());
		// add 1 player, 4 pits, 1 wumpus
		player.location = &rooms[temp[0]];
		rooms[temp[3]].has_pit = true;
		rooms[temp[7]].has_pit = true;
		rooms[temp[11]].has_bat = true;
		rooms[temp[15]].has_bat = true;
		wumpus.location = &rooms[temp[19]];
	}

	Room* Cave::get_player_location()
	{
		return player.location;
	}

	Room* Cave::get_wumpus_location()
	{
		return wumpus.location;
	}

	size_t Cave::get_rooms_number()
	{
		return rooms.size();
	}

	bool Cave::player_move(int room)
	{
		Room* n = room_by_number(room);
		if (is_connected(player.location->connected_rooms, n))
		{
			player.location = n;
			return true;
		}
		else
		{
			std::cout << "Not possible\n";
		}
		return false;
	}

	void Cave::arrows_reduce()
	{
		--player.arrows_number;
	}

	void Cave::bat_move()
	{
		player.location = &rooms[(rand() % rooms.size())];
	}

	void Cave::wumpus_move()
	{
		int n = rand() % 2;
		if (n == 0) // not move
		{
			return;
		}
		else // move to another room
		{
			wumpus.location = wumpus.location->connected_rooms[n];
		}
	}

	void Cave::warnings()
	{
		for (auto& i : player.location->connected_rooms)
		{
			if (i == wumpus.location)
			{
				std::cout << "I smell a Wumpus!\n";
			}
		}
		for (auto& i : player.location->connected_rooms)
		{
			if (i->has_pit)
			{
				std::cout << "I feel the breeze!\n";
			}
			if (i->has_bat)
			{
				std::cout << "I hear the bat!\n";
			}
		}
	}

	void Cave::room_description()
	{
		std::cout << "You are in room #" << player.location->id << '\n';
		std::cout << "This room is connected with ";
		for (auto& i : player.location->connected_rooms)
		{
			std::cout << "#" << i->id << ' ';
		}
		std::cout << '\n';
	}

	States Cave::arrow_shoot()
	{
		int n = 0;
		std::cout << "Number of rooms - #1 ... #5 :\n";
		while ((n < 1) || (n > 5))
		{
			std::cin >> n;
			if ((n > 5) || (n < 1))
			{
				std::cout << "Number must be 1 ...5!\n";
			}
		}
		std::vector<Room*> route(n);
		while (true)
		{
			for (int i = 0; i < n; ++i)
			{
				int n = 0;
				std::cout << "Room #" << i + 1 << '\n';
				std::cout << "Number of rooms - #1 ... #20 :\n";
				while ((n < 1) || (n > get_rooms_number()))
				{
					std::cin >> n;
					if ((n > get_rooms_number()) || (n < 1))
					{
						std::cout << "Number must be 1 ...20!\n";
					}
				}
				route[i] = room_by_number(n);
			}
			if (check_arrow_route(route))
			{
				break;
			}
		}
		Room* arrow_loc = get_player_location();
		for (size_t i = 0; i < route.size(); ++i)
		{
			if (is_connected(arrow_loc->connected_rooms, route[i]))
			{
				arrow_loc = route[i];
			}
			else
			{
				arrow_loc = arrow_loc->connected_rooms[(rand() % 3)];
			}
			if (arrow_loc == get_wumpus_location())
			{
				return States::wumpus_dead;
			}
			if (arrow_loc == get_player_location())
			{
				return States::player_dead;
			}
		}
		std::cout << '\n';
		--player.arrows_number;
		if (player.arrows_number == 0)
		{
			return States::no_arrows;
		}
		std::cout << '\n' << player.arrows_number << " arrows left\n";
		return States::game_continue;
	}

	int Cave::get_arrows_number()
	{
		return player.arrows_number;
	}

	Room* Cave::room_by_number(int room)
	{
		for (size_t i = 0; i < get_rooms_number(); ++i)
		{
			if (rooms[i].id == room)
			{
				return &rooms[i];
			}
		}
		return 0;
	}

	bool check_arrow_route(std::vector<Room*> r)
	{
		if (r.size() < 1 || r.size() > 5)
		{
			std::cout << "Route is wrong\n";
			return false;
		}
		else
		{
			for (int i = 2; i < r.size(); ++i)
			{
				if (r[i] == r[i - 2])
				{
					std::cout << "Route is wrong\n";
					return false;
				}
			}
		}
		return true;
	}
}