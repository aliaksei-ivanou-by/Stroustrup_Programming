#ifndef TASK_25_00_01_ADDITIONAL_H
#define TASK_25_00_01_ADDITIONAL_H

#ifndef TASK_25_00_01_STDAFX_H
#include "Task_25_00_01_stdafx.h"
#endif

struct Node
{
	Node* next;
	Node* prev;
	Node(Node* n, Node* p) :
		next{ n },
		prev{ p }
	{}
	Node() :
		next{ nullptr },
		prev{ nullptr }
	{}
};

struct Device
{
	std::string nameDevice;
	Device(const std::string& n) :
		nameDevice{ n }
	{}
};

struct Message
{
	std::string deviceMessage;
};

Message* get_input(Device& device)
{
	Message* message = new Message;
	message->deviceMessage = device.nameDevice;
	return message;
}

#endif