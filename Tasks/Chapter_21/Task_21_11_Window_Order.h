#ifndef TASK_21_11_WINDOW_ORDER_H
#define TASK_21_11_WINDOW_ORDER_H

#ifndef TASK_21_11_STDAFX_H
#include "Task_21_11_stdafx.h"
#endif

class Window_Order : public Window
{
public:
	Window_Order();
private:
	In_box boxFileName;
	In_box boxClientName;
	In_box boxClientAddress;
	In_box boxClientBirthdayDate;
	In_box boxPurchaseName;
	In_box boxPurchaseUnitPrice;
	In_box boxPurchaseCount;

	Button buttonAdd;

	static void cbButtonAdd(Address, Address pw);

	void Add();
};

#endif
