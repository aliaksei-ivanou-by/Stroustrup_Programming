#ifndef TASK_21_11_STDAFX_H
#include "Task_21_11_stdafx.h"
#include "Task_21_11_Window_Order.h"
#endif

Window_Order::Window_Order() :
	Window{ Point{ 50, 50 }, 600, 350, "Orders" },
	boxFileName{ Point{150, 20}, 300, 30, "File" },
	boxClientName{ Point{150, 60}, 300, 30, "Client Name" },
	boxClientAddress{ Point{150, 100}, 300, 30, "Client Address" },
	boxClientBirthdayDate{ Point{150, 140}, 300, 30, "Client Birthday Date" },
	boxPurchaseName{ Point{150, 180}, 300, 30, "Purchase Name" },
	boxPurchaseUnitPrice{ Point{150, 220}, 300, 30, "Purchase Unit Price" },
	boxPurchaseCount{ Point{150, 260}, 300, 30, "Purchase Count" },
	buttonAdd{ Point{150, 300}, 300, 30, "Add", cbButtonAdd }
{
	attach(boxFileName);
	attach(boxClientName);
	attach(boxClientAddress);
	attach(boxClientBirthdayDate);
	attach(boxPurchaseName);
	attach(boxPurchaseUnitPrice);
	attach(boxPurchaseCount);
	attach(buttonAdd);
}

void Window_Order::cbButtonAdd(Address, Address pw)
{
	reference_to<Window_Order>(pw).Add();
}

void Window_Order::Add()
{
	// READ FILE
	std::string fileName = boxFileName.get_string();
	std::ifstream fileInputStream(fileName.c_str());
	if (!fileInputStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::vector<Order> ordersFile;
	Order orderFile;
	while (fileInputStream >> orderFile)
	{
		ordersFile.push_back(orderFile);
		orderFile = Order();
	}
	std::sort(ordersFile.begin(), ordersFile.end());
	fileInputStream.close();

	// WRITE FILE
	std::string clientName = boxClientName.get_string();
	std::string clientAddress = boxClientAddress.get_string();
	std::string clientBirthdayDate = boxClientBirthdayDate.get_string();
	std::string purchaseName = boxPurchaseName.get_string();
	double purchaseInitPrice = std::stod(boxPurchaseUnitPrice.get_string());
	int purchaseCount = boxPurchaseCount.get_int();
	Purchase purchase = Purchase(purchaseName, purchaseInitPrice, purchaseCount);
	std::vector<Purchase> purchases;
	purchases.push_back(purchase);
	Order orderAdd = Order(clientName, clientAddress, clientBirthdayDate, purchases);
	ordersFile.push_back(orderAdd);
	std::sort(ordersFile.begin(), ordersFile.end());
	std::ofstream fileOutputStream(fileName.c_str(), std::ios_base::trunc);
	for (auto i = ordersFile.begin(); i != ordersFile.end(); ++i)
	{
		fileOutputStream << *i;
	}
	fileOutputStream.close();
}