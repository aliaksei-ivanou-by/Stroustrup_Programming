#ifndef TASK_14_14_STDAFX_H
#include "Task_14_14_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Binary_tree tree(Point(500, 200), 4, 10);
	tree.set_label("1", "lll"); 
	tree.set_label("2", "ll"); 
	tree.set_label("3", "llr"); 
	tree.set_label("4", "l"); 
	tree.set_label("5", "lrl"); 
	tree.set_label("6", "lr"); 
	tree.set_label("7", "lrr"); 
	tree.set_label("8", ""); 
	tree.set_label("9", "rll"); 
	tree.set_label("10", "rl"); 
	tree.set_label("11", "rlr"); 
	tree.set_label("12", "r"); 
	tree.set_label("13", "rrl"); 
	tree.set_label("14", "rr"); 
	tree.set_label("15", "rrr"); 
	win.attach(tree);
	win.wait_for_button();
	return 0;
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}