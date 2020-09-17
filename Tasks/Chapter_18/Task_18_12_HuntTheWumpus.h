#ifndef TASK_18_12_HUNTTHEWUMPUS_H
#define TASK_18_12_HUNTTHEWUMPUS_H

#ifndef TASK_18_12_STDAFX_H
#include "Task_18_12_stdafx.h"
#endif

namespace HuntTheWumpus
{
	class Room
	{
	public:
		Room();
		Room(int room_id, Room* connected_room1, Room* connected_room2, Room* connected_room3);
		int id;
		std::vector<Room*> connected_rooms;
		bool has_pit;
		bool has_bat;
	};

	bool is_connected(std::vector<Room*> connected_rooms, Room* room);

	class Player
	{
	public:
		Player(Room* room);
		Room* location;
		int arrows_number;
	};

	class Wumpus
	{
	public:
		Wumpus(Room* room);
		Room* location;
	};

	enum class States
	{
		game_continue,
		no_arrows,
		player_dead,
		wumpus_dead
	};

	class Cave
	{
	public:
		Cave();
		Room* get_player_location();
		Room* get_wumpus_location();
		size_t get_rooms_number();
		bool player_move(int room);
		void bat_move();
		void wumpus_move();
		void warnings();
		void room_description();
		States arrow_shoot();
	private:
		std::vector<Room> rooms;
		Player player;
		Wumpus wumpus;
		Room* room_by_number(int room);
	};

	bool check_arrow_route(std::vector<Room*> connected_rooms);
}

void game_hunt_the_wumpus();

#endif