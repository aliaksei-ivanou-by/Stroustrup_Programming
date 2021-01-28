#ifndef TASK_21_10_STDAFX_H
#include "Task_21_10_stdafx.h"
#include "Task_21_10_Order.h"
#endif

Purchase::Purchase():
	purchaseName{ }, 
	purchaseUnitPrice{ },
	purchaseCount{ }
{}

Purchase::Purchase(
	std::string purchaseNameToAdd,
	double purchaseUnitPriceToAdd,
	int purchaseCountToAdd):

	purchaseName{ purchaseNameToAdd },
	purchaseUnitPrice{ purchaseUnitPriceToAdd },
	purchaseCount{ purchaseCountToAdd }
{}

std::string Purchase::getPurchaseName()
{
	return purchaseName;
}

double Purchase::getPurchaseUnitPrice()
{
	return purchaseUnitPrice;
}

int Purchase::getPurchaseCount()
{
	return purchaseCount;
}

void Purchase::setPurchaseName(std::string&& purchaseNameToUpdate)
{
	purchaseName = std::move(purchaseNameToUpdate);
}

void Purchase::setPurchaseUnitPrice(double&& purchaseUnitPriceToUpdate)
{
	purchaseUnitPrice = std::move(purchaseUnitPriceToUpdate);
}

void Purchase::setPurchaseCount(int&& purchaseCountToUpdate)
{
	purchaseCount = std::move(purchaseCountToUpdate);
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

std::ostream& operator<<(std::ostream& outputStream, const Purchase& purchase)
{
	return outputStream <<
		purchase.purchaseName << '\t' <<
		purchase.purchaseUnitPrice << '\t' <<
		purchase.purchaseCount;
}

Order::Order():
	clientName{ },
	clientAddress{ },
	clientBirthdayDate{ },
	clientPurchases{ }
{}

Order::Order(
	const std::string& clientNameToAdd,
	const std::string& clientAddressToAdd,
	const std::string& clientBirthdayDateToAdd) :

	clientName{ clientNameToAdd },
	clientAddress{ clientAddressToAdd },
	clientBirthdayDate{ clientBirthdayDateToAdd },
	clientPurchases{ }
{}

Order::Order(
	const std::string& clientNameToAdd,
	const std::string& clientAddressToAdd,
	const std::string& clientBirthdayDateToAdd,
	const std::vector<Purchase>& clientPurchasesToAdd):

	clientName{ clientNameToAdd },
	clientAddress{ clientAddressToAdd },
	clientBirthdayDate{ clientBirthdayDateToAdd },
	clientPurchases{ clientPurchasesToAdd }
{}

std::string Order::getClientName() const
{
	return clientName;
}

std::string Order::getClientAddress() const
{
	return clientAddress;
}

std::string Order::getClientBirthdayDate() const
{
	return clientBirthdayDate;
}

std::vector<Purchase> Order::getClientPurchases() const
{
	return clientPurchases;
}

std::vector<Purchase>::const_iterator Order::getClientPurchasesBegin() const
{
	return clientPurchases.begin();
}

std::vector<Purchase>::const_iterator Order::getClientPurchasesEnd() const
{
	return clientPurchases.end();
}

void Order::setClientName(std::string&& clientNameToUpdate)
{
	clientName = std::move(clientNameToUpdate);
}

void Order::setClientAddress(std::string&& clientAddressToUpdate)
{
	clientAddress = std::move(clientAddressToUpdate);
}

void Order::setClientBirthdayDate(std::string&& clientBirthdayDateToUpdate)
{
	clientBirthdayDate = std::move(clientBirthdayDateToUpdate);
}

void Order::addPurchase(const Purchase& purchase)
{
	clientPurchases.emplace_back(purchase);
}

bool Order::operator<(const Order& order) const
{
	return clientName < order.clientName;
}

std::istream& operator>>(std::istream& inputStream, Order& order)
{
	if (!inputStream)
	{
		return inputStream;
	}
	std::string line;
	std::string name;
	std::string address;
	std::string birthdayDate;
	getline(inputStream, line);
	std::stringstream stringStream(line);
	if (stringStream >> name >> address >> birthdayDate)
	{
		order = Order(name, address, birthdayDate);
	}
	std::string line2;
	while (getline(inputStream, line2) && !line2.empty())
	{
		Purchase purchase;
		std::stringstream ss2(line2);

		if (ss2 >> purchase)
		{
			order.addPurchase(purchase);
		}
	}

	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Order& order)
{
	outputStream <<
		order.clientName << '\t' <<
		order.clientAddress << '\t' << 
		order.clientBirthdayDate << '\n';

	for (auto i = order.getClientPurchasesBegin(); i != order.getClientPurchasesEnd(); ++i)
	{
		outputStream << *i << '\n';
	}
	outputStream << '\n';
	return outputStream;
}