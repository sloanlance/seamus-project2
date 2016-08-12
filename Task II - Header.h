#include <vector>
#include <string>
using namespace std;


class Store{

public:
	//Just a reminder for myself....

	//void set(variable);
	//int get();	
	int getVecSize();
	void ChngePrices(int, double);
	void OrderItemAvail(int, int);
	void OrderItemOrdered(int, int);
	void SellItemSold(int, int);
	void SellItemAvail(int, int);
	void setItemID(int);
	void setItemSold(int);
	void setItemAvail(int);
	void setItemOrdered(int);
	void setItemName(string);
	void setItemManuPrice(double);
	void setItemSellPrice(double);
	signed long long calcTotInventory();
	int getItemID(int);
	int getItemSold(int);
	int getItemAvail(int);
	int getItemOrdered(int);
	string getItemName(int);
	double getItemManuPrice(int);
	double getItemSellPrice(int);
	double getTotInventory();

private:
	double totInventory;
	vector<int> itemIDs;
	vector<int> itemSold;
	vector<int> itemAvail;
	vector<int>	itemOrdered;
	vector<string> itemNames;
	vector<double> itemManuPrices;
	vector<double> itemSellPrices;

};
