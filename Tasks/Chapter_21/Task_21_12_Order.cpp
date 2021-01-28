#ifndef TASK_21_12_STDAFX_H
#include "Task_21_12_stdafx.h"
#include "Task_21_12_Order.h"
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

std::string Purchase::getPurchaseName() const
{
	return purchaseName;
}

double Purchase::getPurchaseUnitPrice() const
{
	return purchaseUnitPrice;
}

int Purchase::getPurchaseCount() const
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

bool Purchase::operator<(const Purchase& purchase) const
{
	if (getPurchaseName() < purchase.getPurchaseName())
	{
		return true;
	}
	else
	{
		if (getPurchaseName() > purchase.getPurchaseName())
		{
			return false;
		}
		else
		{
			if (getPurchaseUnitPrice() < purchase.getPurchaseUnitPrice())
			{
				return true;
			}
			else
			{
				if (getPurchaseUnitPrice() > purchase.getPurchaseUnitPrice())
				{
					return true;
				}
				else
				{
					if (getPurchaseCount() < purchase.getPurchaseCount())
					{
						return true;
					}
					else
					{
						if (getPurchaseCount() > purchase.getPurchaseCount())
						{
							return false;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
	}
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
	if (getClientName() < order.getClientName())
	{
		return true;
	}
	else
	{
		if (getClientName() > order.getClientName())
		{
			return false;
		}
		else
		{
			if (getClientAddress() < order.getClientAddress())
			{
				return true;
			}
			else
			{
				if (getClientAddress() > order.getClientAddress())
				{
					return false;
				}
				else
				{
					if (getClientBirthdayDate() < order.getClientBirthdayDate())
					{
						return true;
					}
					else
					{
						if (getClientBirthdayDate() > order.getClientBirthdayDate())
						{
							return false;
						}
					}
				}
			}
		}
	}
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