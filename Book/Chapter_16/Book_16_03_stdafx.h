#ifndef BOOK_16_03_STDAFX_H
#define BOOK_16_03_STDAFX_H

#include <iostream>
#include "GUI.h"
#include "Simple_window.h"
#include "Point.h"

void cb_flood(Address, Address);
void cb_fire(Address, Address);

void load_disaster_menu(Menu& m)
{
	Point orig(0, 0);
	Button b1(orig, 0, 0, "flood", cb_flood);
	Button b2(orig, 0, 0, "fire", cb_fire);
	m.attach(b1);
	m.attach(b2);
}

#endif
