#ifndef TASK_18_11_STDAFX
#include "Task_18_11_stdafx.h"
#include "Task_18_11_Skip_List.h"
#endif

Skip_List::Skip_List()
	: begin{ 0, level_max },
	end{ NIL, level_max },
	level{ 0 }
{
	for (size_t i = 0; i < begin.nodes.size(); ++i)
	{
#ifdef DEBUG
		std::cout << "begin.nodes[i] = " << i << ' ' << begin.nodes[i] << ", ";
		std::cout << "&begin.nodes[i] = " << &begin.nodes[i] << ", ";
		std::cout << "&end = " << &end << '\n';
#endif
		begin.nodes[i] = &end;
	}
}

void Skip_List::insert(int value)
{
	std::vector<Node*> list_temp(level_max + 1);
	Node* temp = &begin;
	for (int i = level; i >= 0; --i)
	{
		while ((temp->nodes[i]->value) < value)
		{
			temp = temp->nodes[i];
		}
		list_temp[i] = temp;
	}
	temp = temp->nodes[0];
	if (temp->value == value)
	{
		return;
	}
	int level_new = get_level();
	if (level_new > level)
	{
		for (int i = level + 1; i <= level_new; ++i)
		{
			list_temp[i] = &begin;
		}
		level = level_new;
	}
	temp = new Node(value, level_new);
	for (int i = 0; i <= level_new; ++i)
	{
		temp->nodes[i] = list_temp[i]->nodes[i];
		list_temp[i]->nodes[i] = temp;
	}
}

void Skip_List::remove(int value)
{
	std::vector<Node*> list_temp(level_max + 1);
	Node* temp = &begin;
	for (int i = level; i >= 0; --i)
	{
		while ((temp->nodes[i]->value) < value)
		{
			temp = temp->nodes[i];
		}
		list_temp[i] = temp;
	}
	temp = temp->nodes[0];
	if (temp->value == value)
	{
		for (size_t i = 0; i < temp->nodes.size(); ++i)
		{
			list_temp[i]->nodes[i] = temp->nodes[i];
		}
		while ((level >= 1) && (begin.nodes[level]->value == NIL))
		{
			--level;
		}
		delete temp;
	}
}

void Skip_List::print()
{
	for (int i = 0; i <= level; ++i)
	{
		Node* n = begin.nodes[0];
		std::cout << "Level " << i << ":\t";
		while (n->value != NIL)
		{
			if (n->nodes.size() > i)
			{
				std::cout << ' ' << std::setw(3) << n->value;
			}
			else
			{
				std::cout << "    ";
			}
			n = n->nodes[0];
		}
		std::cout << '\n';
	}
}

int Skip_List::get_level()
{
	int level_gen = 0;
	while ((rand() % 10000 < 5000) && (level_gen < level_max))
	{
		++level_gen;
	}
	return level_gen;
}

Skip_List::Node::Node(int v, int l)
	: value{ v },
	nodes(l + 1)
{
}
