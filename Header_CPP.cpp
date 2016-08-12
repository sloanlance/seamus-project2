#include "Task II - Header.h"
int Store::getVecSize()
{
	return itemIDs.size();
}
void Store::ChngePrices(int a, double b)
{
	itemSellPrices[a] = b;
}
void Store::OrderItemAvail(int a, int b)
{
	itemAvail[a] = b;
}
void Store::OrderItemOrdered(int a, int b)
{
	itemOrdered[a] = b;
}
void Store::SellItemSold(int a, int b)
{
	itemSold[a] = b;
}
void Store::SellItemAvail(int a, int b)
{
	itemAvail[a] = b;
}
void Store::setItemID(int a)
{
	itemIDs.push_back(a);
}
void Store::setItemSold(int a)
{
	itemSold.push_back(a);
}
void Store::setItemAvail(int a)
{
	itemAvail.push_back(a);
}
void Store::setItemOrdered(int a)
{
	itemOrdered.push_back(a);
}
void Store::setItemName(string a)
{
	itemNames.push_back(a);
}
void Store::setItemManuPrice(double a)
{
	itemManuPrices.push_back(a);
}
void Store::setItemSellPrice(double a)
{
	itemSellPrices.push_back(a);
}
signed long long Store::calcTotInventory()
{
	signed long long total = 0;
	signed long long add;
	for (int i = 0; i < getVecSize(); i++)
	{
		add = getItemAvail(i)*getItemSellPrice(i);
		total += add;
	}
	return total;
}
int Store::getItemID(int a)
{
	return itemIDs[a];
}
int Store::getItemSold(int a)
{
	return itemSold[a];
}
int Store::getItemAvail(int a)
{
	return itemAvail[a];
}
int Store::getItemOrdered(int a)
{
	return itemOrdered[a];
}
string Store::getItemName(int a)
{
	return itemNames[a];
}
double Store::getItemManuPrice(int a)
{
	return itemManuPrices[a];
}
double Store::getItemSellPrice(int a)
{
	return itemSellPrices[a];
}
double Store::getTotInventory()
{
	return totInventory;
}