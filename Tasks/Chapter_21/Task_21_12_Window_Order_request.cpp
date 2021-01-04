#ifndef TASK_21_12_STDAFX
#include "Task_21_12_stdafx.h"
#include "Task_21_12_Window_Order_request.h"
#endif

Window_Order_request::Window_Order_request() :
	Window{ Point{ 50, 50 }, 575, 700, "Orders" },
	inboxFileName{ Point{ 75, 20 }, 450, 30, "File" },
	buttonDisplayOrders{ Point{ 75, 60 }, 150, 30, "Orders", cbDisplayOrders },
	buttonDisplayOrdersByClientName{ Point{ 225, 60 }, 150, 30, "Orders by Client Name", cbDisplayOrdersByClientName },
	buttonDisplayOrdersByClientNameOK{ Point{ 475, 100 }, 50, 30, "OK", cbDisplayOrdersByClientNameOK },
	buttonDisplayTotalValue{ Point{ 375, 60 }, 150, 30, "Total", cbDisplayTotalValue },
	inboxClientName{ Point{ 75, 100 }, 400, 30, "Name" },
	outboxTotalValue{ Point{ 75, 100 }, 400, 30, "Value" },
	outboxMessages{ Point{ 75, 360 }, 450, 30, "" },
	buttonNextClient{ Point{ x_max() - 50, 330 }, 50, 30, "Next", cbClientNext },
	buttonPreviousClient{ Point{ 0, 330 }, 50, 30, "Prev", cbClientPrevious },
	outboxClientName{ Point{ 75, 100 }, 150, 30, "" },
	outboxClientAddress{ Point{ 225, 100 }, 150, 30, "" },
	outboxClientBirthday{ Point{ 375, 100 }, 150, 30, "" }
{
	attach(inboxFileName);
	attach(buttonDisplayOrders);
	attach(buttonDisplayOrdersByClientName);
	attach(buttonDisplayTotalValue);

	attach(inboxClientName);
	inboxClientName.hide();
	attach(buttonDisplayOrdersByClientNameOK);
	buttonDisplayOrdersByClientNameOK.hide();
	attach(outboxTotalValue);
	outboxTotalValue.hide();
	attach(outboxMessages);
	outboxMessages.hide();
	attach(buttonNextClient);
	buttonNextClient.hide();
	attach(buttonPreviousClient);
	buttonPreviousClient.hide();

	attach(outboxClientName);
	attach(outboxClientAddress);
	attach(outboxClientBirthday);
	outboxClientName.hide();
	outboxClientAddress.hide();
	outboxClientBirthday.hide();
}

void Window_Order_request::cbDisplayOrders(Address, Address pw)
{
	reference_to<Window_Order_request>(pw).displayOrders();
}

void Window_Order_request::cbDisplayOrdersByClientName(Address, Address pw)
{
	reference_to<Window_Order_request>(pw).displayOrdersByClientName();
}

void Window_Order_request::cbDisplayOrdersByClientNameOK(Address, Address pw)
{
	reference_to<Window_Order_request>(pw).displayOrdersByClientNameOK();
}

void Window_Order_request::cbDisplayTotalValue(Address, Address pw)
{
	reference_to<Window_Order_request>(pw).displayTotalValue();
}

void Window_Order_request::cbClientNext(Address, Address pw)
{
	reference_to<Window_Order_request>(pw).clientNext();
}

void Window_Order_request::cbClientPrevious(Address, Address pw)
{
	reference_to<Window_Order_request>(pw).clientPrevious();
}

void Window_Order_request::displayOrders()
{
	orders.clear();
	clearAll();

	std::string fileName = inboxFileName.get_string();
	std::ifstream fileInputStream(fileName.c_str());
	if (!fileInputStream)
	{
		outboxMessages.put("Can't open file " + fileName);
		outboxMessages.show();
		return;
	}
	Order order;
	while (fileInputStream >> order)
	{
		orders.push_back(order);
		order = Order();
	}

	clientCurrent = 0;
	outboxClientName.show();
	outboxClientAddress.show();
	outboxClientBirthday.show();
	outboxClientName.show();
	outboxClientAddress.show();
	outboxClientBirthday.show();

	showPuchases();
	buttonNextClient.show();
}

void Window_Order_request::displayOrdersByClientName()
{
	orders.clear();
	clearAll();

	std::string fileName = inboxFileName.get_string();
	std::ifstream fileInputStream(fileName.c_str());
	if (!fileInputStream)
	{
		outboxMessages.put("Can't open file " + fileName);
		outboxMessages.show();
		return;
	}

	inboxClientName.show();
	buttonDisplayOrdersByClientNameOK.show();

}

void Window_Order_request::displayOrdersByClientNameOK()
{
	inboxClientName.show();
	std::string fileName = inboxFileName.get_string();
	std::ifstream fileInputStream(fileName.c_str());
	if (!fileInputStream)
	{
		outboxMessages.put("Can't open file " + fileName);
		outboxMessages.show();
		return;
	}
	Order order;
	while (fileInputStream >> order)
	{
		orders.push_back(order);
		order = Order();
	}

	inboxClientName.show();
	buttonDisplayOrdersByClientNameOK.show();

	std::vector<std::vector<Purchase>> purchasesTemp;
	std::vector<Purchase> purchases;
	std::string client = inboxClientName.get_string();
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		if (i->getClientName() == client)
		{
			outboxClientName.put(i->getClientName());
			outboxClientAddress.put(i->getClientAddress());
			outboxClientBirthday.put(i->getClientBirthdayDate());
			inboxClientName.hide();
			buttonDisplayOrdersByClientNameOK.hide();
			outboxClientName.show();
			outboxClientAddress.show();
			outboxClientBirthday.show();
			break;
		}
	}
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		if (i->getClientName() == client)
		{
			purchasesTemp.push_back(i->getClientPurchases());
		}
	}
	int count = 0;
	for (auto& i : purchasesTemp)
	{
		for (auto& j : i)
		{
			purchases.push_back(j);
		}
	}
	int startY = 140;
	for (size_t i = 0; i < purchases.size(); ++i)
	{
		clientPurchaseNameVector.push_back(new Out_box{ Point{75, startY}, 150, 30, "" });
		clientPurchaseUnitPriceVector.push_back(new Out_box{ Point{225, startY}, 150, 30, "" });
		clientPurchaseCountVector.push_back(new Out_box{ Point{375, startY}, 150, 30, "" });
		startY += 40;
	}
	for (auto& i : clientPurchaseNameVector)
	{
		attach(*i);
		i->hide();
	}
	for (auto& i : clientPurchaseUnitPriceVector)
	{
		attach(*i);
		i->hide();
	}
	for (auto& i : clientPurchaseCountVector)
	{
		attach(*i);
		i->hide();
	}
	int key = 0;
	for (auto i : clientPurchaseNameVector)
	{
		i->put(purchases[key++].getPurchaseName());
		i->show();
	}
	key = 0;
	for (auto& i : clientPurchaseUnitPriceVector)
	{
		i->put(std::to_string(purchases[key++].getPurchaseUnitPrice()));
		i->show();
	}
	key = 0;
	for (auto& i : clientPurchaseCountVector)
	{
		i->put(std::to_string(purchases[key++].getPurchaseCount()));
		i->show();
	}
}

void Window_Order_request::displayTotalValue()
{
	orders.clear();
	clearAll();

	std::string fileName = inboxFileName.get_string();
	std::ifstream fileInputStream(fileName.c_str());
	if (!fileInputStream)
	{
		outboxMessages.put("Can't open file " + fileName);
		outboxMessages.show();
		return;
	}
	Order order;
	while (fileInputStream >> order)
	{
		orders.push_back(order);
		order = Order();
	}
	double totalSum = 0;
	for (auto i = orders.begin(); i != orders.end(); ++i)
	{
		totalSum = std::inner_product(i->getClientPurchasesBegin(), i->getClientPurchasesEnd(),
			i->getClientPurchasesBegin(),
			totalSum,
			std::plus<double>(),
			[](Purchase a, Purchase b) { return a.getPurchaseCount() * b.getPurchaseUnitPrice(); });
	}
	outboxTotalValue.put(std::to_string(totalSum));
	outboxTotalValue.show();
}

void Window_Order_request::clearAll()
{
	inboxClientName.hide();
	outboxTotalValue.hide();
	buttonDisplayOrdersByClientNameOK.hide();
	outboxMessages.hide();
	buttonPreviousClient.hide();
	buttonNextClient.hide();
	outboxClientName.hide();
	outboxClientAddress.hide();
	outboxClientBirthday.hide();
	for (auto& i : clientPurchaseNameVector)
	{
		i->hide();
	}
	for (auto& i : clientPurchaseUnitPriceVector)
	{
		i->hide();
	}
	for (auto& i : clientPurchaseCountVector)
	{
		i->hide();
	}
	clientPurchaseNameVector.clear();
	clientPurchaseUnitPriceVector.clear();
	clientPurchaseCountVector.clear();
}

void Window_Order_request::clientPrevious()
{
	clearAll();

	--clientCurrent;
	if (clientCurrent == orders.size() - 1)
	{
		showPuchases();
		buttonPreviousClient.show();
		buttonNextClient.hide();
	}
	else
	{
		if (clientCurrent == 0)
		{
			showPuchases();
			buttonPreviousClient.hide();
			buttonNextClient.show();
		}
		else
		{
			showPuchases();
			buttonPreviousClient.show();
			buttonNextClient.show();
		}
	}
}

void Window_Order_request::clientNext()
{
	clearAll();

	++clientCurrent;
	if (clientCurrent == orders.size() - 1)
	{
		showPuchases();
		buttonPreviousClient.show();
		buttonNextClient.hide();
	}
	else
	{
		if (clientCurrent == 0)
		{
			showPuchases();
			buttonPreviousClient.hide();
			buttonNextClient.show();
		}
		else
		{
			showPuchases();
			buttonPreviousClient.show();
			buttonNextClient.show();
		}
	}
}

void Window_Order_request::showPuchases()
{
	outboxClientName.put(orders[clientCurrent].getClientName());
	outboxClientAddress.put(orders[clientCurrent].getClientAddress());
	outboxClientBirthday.put(orders[clientCurrent].getClientBirthdayDate());
	outboxClientName.show();
	outboxClientAddress.show();
	outboxClientBirthday.show();
	int startY = 140;
	for (size_t i = 0; i < orders[clientCurrent].getClientPurchases().size(); ++i)
	{
		clientPurchaseNameVector.push_back(new Out_box{ Point{75, startY}, 150, 30, "" });
		clientPurchaseUnitPriceVector.push_back(new Out_box{ Point{225, startY}, 150, 30, "" });
		clientPurchaseCountVector.push_back(new Out_box{ Point{375, startY}, 150, 30, "" });
		startY += 40;
	}
	for (auto& i : clientPurchaseNameVector)
	{
		attach(*i);
		i->hide();
	}
	for (auto& i : clientPurchaseUnitPriceVector)
	{
		attach(*i);
		i->hide();
	}
	for (auto& i : clientPurchaseCountVector)
	{
		attach(*i);
		i->hide();
	}
	int key = 0;
	for (auto i : clientPurchaseNameVector)
	{
		i->put(orders[clientCurrent].getClientPurchases()[key++].getPurchaseName());
		i->show();
	}
	key = 0;
	for (auto& i : clientPurchaseUnitPriceVector)
	{
		i->put(std::to_string(orders[clientCurrent].getClientPurchases()[key++].getPurchaseUnitPrice()));
		i->show();
	}
	key = 0;
	for (auto& i : clientPurchaseCountVector)
	{
		i->put(std::to_string(orders[clientCurrent].getClientPurchases()[key++].getPurchaseCount()));
		i->show();
	}
}