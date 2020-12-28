#ifndef TASK_21_10_STDAFX
#include "Task_21_10_stdafx.h"
#include "Task_21_10_Order.h"
#endif

Purchase::Purchase():
	name{ "" },
	unit_price{ 0.0 },
	count{ 0 }
{}

Purchase::Purchase(std::string name_ToAdd, double unit_price_ToAdd, int count_ToAdd):
	name { name_ToAdd },
	unit_price{ unit_price_ToAdd },
	count{ count_ToAdd }
{}

std::string Purchase::get_name() const
{
	return name;
}

double Purchase::get_unit_price() const
{
	return unit_price;
}

int Purchase::get_count() const
{
	return count;
}

std::ostream& operator<<(std::ostream& outputStream, const Purchase& purchase)
{
	return outputStream << 
		purchase.name << '\t' << 
		purchase.unit_price << '\t' <<
		purchase.count;
}

std::istream& operator>>(std::istream& inputStream, Purchase& purchase)
{
	if (!inputStream)
	{
		return inputStream;
	}
	std::string line;
	getline(inputStream, line);
	std::stringstream ss(line);
	std::string name;
	double price;
	int count;
	if (ss >> name >> price >> count)
	{
		purchase = Purchase(name, price, count);
	}
	return inputStream;
}

Order::Order():
	clientName{ },
	clientAddress{ },
	clientBirthdayDate{ },
	clientPurchases{ }
{}

Order::Order(
	std::string clientNameToAdd, 
	std::string clientAddressToAdd,
	std::string clientBirthdayDateToAdd,
	std::vector<Purchase> clientPurchasesToAdd):

	clientName{ clientNameToAdd },
	clientAddress{ clientAddressToAdd },
	clientBirthdayDate{ clientBirthdayDateToAdd },
	clientPurchases{ clientPurchasesToAdd }
{}

std::string Order::get_clientName() const
{
	return clientName;
}

std::string Order::get_clientAddress() const
{
	return clientAddress;
}

std::string Order::get_clientBirthdayDate() const
{
	return clientBirthdayDate;
}

std::vector<Purchase> Order::get_clientPurchases() const
{
	return clientPurchases;
}

std::vector<Purchase>::const_iterator Order::get_clientPurchasesBegin() const
{
	return clientPurchases.cbegin();
}

std::vector<Purchase>::const_iterator Order::get_clientPurchasesEnd() const
{
	return clientPurchases.cend();
}

void Order::add_purchase(const Purchase& purchase)
{
	clientPurchases.emplace_back(purchase);
}

bool Order::operator<(const Order& order) const
{
	return clientName < order.clientName;
}

bool Order::operator==(const Order& order) const
{
	return clientName == order.clientName;
}

std::ostream& operator<<(std::ostream& outputStream, const Order& order)
{
	outputStream << 
		order.clientName << '\t' << 
		order.clientAddress << '\t' << 
		order.clientBirthdayDate << '\n';
	for (auto i = order.clientPurchases.begin(); i != order.clientPurchases.end(); ++i)
	{
		outputStream << *i << '\n';
	}
	outputStream << '\n';
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Order& order)
{
	if (!inputStream)
	{
		return inputStream;
	}
	std::string line;
	getline(inputStream, line);
	std::stringstream ss(line);
	std::string name, address, date;
	if (ss >> name >> address >> date)
	{
		order = Order(name, address, date, {});
	}
	std::string line2;
	while (getline(inputStream, line2) && !line2.empty())
	{
		Purchase p;
		std::stringstream ss2(line2);
		if (ss2 >> p)
		{
			order.add_purchase(p);
		}
	}
	return inputStream;
}