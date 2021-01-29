#pragma once

class Purchase
{
private:
	std::string purchaseName;
	double purchaseUnitPrice;
	int purchaseCount;
public:
	Purchase() :
		purchaseName{ },
		purchaseUnitPrice{ },
		purchaseCount{ }
	{}
	Purchase(
		std::string purchaseNameToAdd,
		double purchaseUnitPriceToAdd,
		int purchaseCountToAdd) :
		purchaseName{ purchaseNameToAdd },
		purchaseUnitPrice{ purchaseUnitPriceToAdd },
		purchaseCount{ purchaseCountToAdd }
	{}
	std::string getPurchaseName()
	{
		return purchaseName;
	}
	double getPurchaseUnitPrice()
	{
		return purchaseUnitPrice;
	}
	int getPurchaseCount()
	{
		return purchaseCount;
	}
	void setPurchaseName(std::string&& purchaseNameToUpdate)
	{
		purchaseName = std::move(purchaseNameToUpdate);
	}
	void setPurchaseUnitPrice(double&& purchaseUnitPriceToUpdate)
	{
		purchaseUnitPrice = std::move(purchaseUnitPriceToUpdate);
	}
	void setPurchaseCount(int&& purchaseCountToUpdate)
	{
		purchaseCount = std::move(purchaseCountToUpdate);
	}
	friend std::istream& operator>>(std::istream& inputStream, Purchase& purchase)
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
	friend std::ostream& operator<<(std::ostream& outputStream, const Purchase& purchase)
	{
		return outputStream <<
			purchase.purchaseName << '\t' <<
			purchase.purchaseUnitPrice << '\t' <<
			purchase.purchaseCount;
	}
};

class Order
{
private:
	std::string clientName;
	std::string clientAddress;
	std::string clientBirthdayDate;
	std::vector<Purchase> clientPurchases;
public:
	Order() :
		clientName{ },
		clientAddress{ },
		clientBirthdayDate{ },
		clientPurchases{ }
	{}
	Order(
		const std::string& clientNameToAdd,
		const std::string& clientAddressToAdd,
		const std::string& clientBirthdayDateToAdd) :
		clientName{ clientNameToAdd },
		clientAddress{ clientAddressToAdd },
		clientBirthdayDate{ clientBirthdayDateToAdd },
		clientPurchases{ }
	{}
	Order(
		const std::string& clientNameToAdd,
		const std::string& clientAddressToAdd,
		const std::string& clientBirthdayDateToAdd,
		const std::vector<Purchase>& clientPurchasesToAdd) :
		clientName{ clientNameToAdd },
		clientAddress{ clientAddressToAdd },
		clientBirthdayDate{ clientBirthdayDateToAdd },
		clientPurchases{ clientPurchasesToAdd }
	{}
	std::string getClientName() const
	{
		return clientName;
	}
	std::string getClientAddress() const
	{
		return clientAddress;
	}
	std::string getClientBirthdayDate() const
	{
		return clientBirthdayDate;
	}
	std::vector<Purchase> getClientPurchases() const
	{
		return clientPurchases;
	}
	std::vector<Purchase>::const_iterator getClientPurchasesBegin() const
	{
		return clientPurchases.begin();
	}
	std::vector<Purchase>::const_iterator getClientPurchasesEnd() const
	{
		return clientPurchases.end();
	}
	void setClientName(std::string&& clientNameToUpdate)
	{
		clientName = std::move(clientNameToUpdate);
	}
	void setClientAddress(std::string&& clientAddressToUpdate)
	{
		clientAddress = std::move(clientAddressToUpdate);
	}
	void setClientBirthdayDate(std::string&& clientBirthdayDateToUpdate)
	{
		clientBirthdayDate = std::move(clientBirthdayDateToUpdate);
	}
	void addPurchase(const Purchase& purchase)
	{
		clientPurchases.emplace_back(purchase);
	}
	bool operator<(const Order& order) const
	{
		return clientName < order.clientName;
	}
	friend std::istream& operator>>(std::istream& inputStream, Order& order)
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
	friend std::ostream& operator<<(std::ostream& outputStream, const Order& order)
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
};