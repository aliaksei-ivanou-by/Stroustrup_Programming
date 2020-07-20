#ifndef BOOK_16_04_STDAFX_H
#define BOOK_16_04_STDAFX_H

#include <iostream>
#include "GUI.h"
#include "Simple_window.h"
#include "Point.h"

void cb_flood(Address, Address);
void cb_fire(Address, Address);

void load_disaster_menu(Menu& m)
{
	Point orig(0, 0);
	m.attach(new Button(orig, 0, 0, "flood", cb_flood));
	m.attach(new Button(orig, 0, 0, "fire", cb_fire));
}

#endif
