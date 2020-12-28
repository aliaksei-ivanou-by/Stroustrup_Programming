#ifndef TASK_21_10_ORDER_H
#define TASK_21_10_ORDER_H

#ifndef TASK_21_10_STDAFX_H
#include "Task_21_10_stdafx.h"
#endif

class Purchase
{
private:
	std::string name;
	double unit_price;
	int count;
public:
	Purchase();
	Purchase(std::string name, double unit_price, int count);
	std::string get_name() const;
	double get_unit_price() const;
	int get_count() const;
	friend std::ostream& operator<<(std::ostream& outputStream, const Purchase& purchase);
	friend std::istream& operator>>(std::istream& inputStream, Purchase& purchase);
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
	Order(std::string clientName, std::string clientAddress, std::string clientBirthdayDate, std::vector<Purchase> clientPurchases);
	std::string get_clientName() const;
	std::string get_clientAddress() const;
	std::string get_clientBirthdayDate() const;
	std::vector<Purchase> get_clientPurchases() const;
	std::vector<Purchase>::const_iterator get_clientPurchasesBegin() const;
	std::vector<Purchase>::const_iterator get_clientPurchasesEnd() const;
	void add_purchase(const Purchase& purchase);
	bool operator<(const Order& order) const;
	bool operator==(const Order& order) const;
	friend std::ostream& operator<<(std::ostream& outputStream, const Order& order);
	friend std::istream& operator>>(std::istream& inputStream, Order& order);
};

#endif