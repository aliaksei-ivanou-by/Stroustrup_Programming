#ifndef TASK_21_12_ORDER_H
#define TASK_21_12_ORDER_H

#ifndef TASK_21_12_STDAFX_H
#include "Task_21_12_stdafx.h"
#endif

class Purchase
{
private:
	std::string purchaseName;
	double purchaseUnitPrice;
	int purchaseCount;
public:
	Purchase();
	Purchase(
		std::string purchaseNameToAdd, 
		double purchaseUnitPriceToAdd, 
		int purchaseCountToAdd);
	std::string getPurchaseName() const;
	double getPurchaseUnitPrice() const;
	int getPurchaseCount() const;
	void setPurchaseName(std::string&& purchaseNameToUpdate);
	void setPurchaseUnitPrice(double&& purchaseUnitPriceToUpdate);
	void setPurchaseCount(int&& purchaseCountToUpdate);
	bool operator<(const Purchase& purchase) const;
	friend std::istream& operator>>(std::istream& inputStream, Purchase& purchase);
	friend std::ostream& operator<<(std::ostream& outputStream, const Purchase& purchase);
};

class Order
{
private:
	std::string clientName;
	std::string clientAddress;
	std::string clientBirthdayDate;
	std::vector<Purchase> clientPurchases;
public:
	Order();
	Order(
		const std::string& clientNameToAdd,
		const std::string& clientAddressToAdd,
		const std::string& clientBirthdayDateToAdd);
	Order(
		const std::string& clientNameToAdd, 
		const std::string& clientAddressToAdd, 
		const std::string& clientBirthdayDateToAdd, 
		const std::vector<Purchase>& clientPurchasesToAdd);
	std::string getClientName() const;
	std::string getClientAddress() const;
	std::string getClientBirthdayDate() const;
	std::vector<Purchase> getClientPurchases() const;
	std::vector<Purchase>::const_iterator getClientPurchasesBegin() const;
	std::vector<Purchase>::const_iterator getClientPurchasesEnd() const;
	void setClientName(std::string&& clientNameToUpdate);
	void setClientAddress(std::string&& clientAddressToUpdate);
	void setClientBirthdayDate(std::string&& clientBirthdayDateToUpdate);
	void addPurchase(const Purchase& purchase);
	bool operator<(const Order& order) const;
	friend std::istream& operator>>(std::istream& inputStream, Order& order);
	friend std::ostream& operator<<(std::ostream& outputStream, const Order& order);
};

#endif