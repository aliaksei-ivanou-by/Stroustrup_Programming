#ifndef TASK_21_12_WINDOW_ORDER_REQUEST_H
#define TASK_21_12_WINDOW_ORDER_REQUEST_H

#ifndef TASK_21_12_STDAFX_H
#include "Task_21_12_stdafx.h"
#endif

class Window_Order_request : public Window
{
public:
	Window_Order_request();
private:
	In_box inboxFileName;
	In_box inboxClientName;

	Out_box outboxTotalValue;
	Out_box outboxMessages;

	Button buttonDisplayOrders;
	Button buttonDisplayOrdersByClientName;
	Button buttonDisplayTotalValue;
	Button buttonDisplayOrdersByClientNameOK;
	Button buttonNextClient;
	Button buttonPreviousClient;

	static void cbDisplayOrders(Address, Address pw);
	static void cbDisplayOrdersByClientName(Address, Address pw);
	static void cbDisplayOrdersByClientNameOK(Address, Address pw);
	static void cbDisplayTotalValue(Address, Address pw);
	static void cbClientPrevious(Address, Address pw);
	static void cbClientNext(Address, Address pw);

	void displayOrders();
	void displayOrdersByClientName();
	void displayOrdersByClientNameOK();
	void displayTotalValue();
	void clientPrevious();
	void clientNext();

	int clientCurrent = 0;
	std::vector<Order> orders;

	Out_box outboxClientName;
	Out_box outboxClientAddress;
	Out_box outboxClientBirthday;
	std::vector<Out_box*> clientPurchaseNameVector;
	std::vector<Out_box*> clientPurchaseUnitPriceVector;
	std::vector<Out_box*> clientPurchaseCountVector;

	void clearAll();
	void showPuchases();
};

#endif
