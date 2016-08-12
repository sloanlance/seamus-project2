//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Task II - Header.h"
using namespace std;

//Global Variables
const int SIZE = 100;
string sortedName[SIZE];
string a = "Invalid Input. Try again.";
ifstream infile;
Store store;
int main();



/*
	RETURN TO MENU FUNCTION
							*/
void RetMenu()
{
	char yesno;
	try{
		cout << "Return to menu? (y/n): ";
		cin >> yesno;
		if (yesno == 'y'){
			system("CLS");
			main();
		}
		else if (yesno == 'n')
			exit(-1);
		else//Confirms that user's input is not interpretable and is an exception
			throw a;
	}
	catch (string a){
		cout << a << endl << endl;
		RetMenu();
	}
}



/*
	INFO GETTING FUNCTION
							*/
void getInfo()
{
	int ID, sold, avail, order;	//local variables are used to store the information,
	string name, x;				//then pass them on to the class functions as parameters.
	double manP, sellP;

	infile.open("Info.txt");
	for (int i = 0; i < 100; i++)
	{
		if (infile.eof())
			break;
		infile >> ID;
		store.setItemID(ID);
		
		getline(infile, x);//C++ getline functions can act tricky. This getline gets the '\n' part of the last line.
		getline(infile, name);
		store.setItemName(name);

		infile >> order;
		store.setItemOrdered(order);

		infile >> avail;
		store.setItemAvail(avail);

		infile >> sold;
		store.setItemSold(sold);

		infile >> manP;
		store.setItemManuPrice(manP);

		infile >> sellP;
		store.setItemSellPrice(sellP);
	}
}



/*
	DISPLAY RECORDS FUNCTION
							*/
void DispRecords()
{
	cout << "\t\t\t\t\t==================" << endl;
	cout << "\t\t\t\t\tDisplaying Records" << endl;
	cout << "\t\t\t\t\t==================" << endl;
	cout << endl << endl;
	for (int i = -1; i < store.getVecSize(); i++)
	{
		if (i == -1)
			cout << "|Item ID|Item Name\t|# Ordered\t|# Available\t|# Sold\t\t|Manuf. Price\t|Sell Price\t|" << endl;
		else
			cout << "|"<<store.getItemID(i) << "\t|" << store.getItemName(i) << "\t|" << store.getItemOrdered(i) << "\t\t|" <<
			store.getItemAvail(i) << "\t\t|" << store.getItemSold(i) << "\t\t|" << store.getItemManuPrice(i) << "\t\t|" <<
			store.getItemSellPrice(i)<<"\t\t|" << endl;
	}
	cout << endl << endl;
	cout << "Total Inventory: $" << store.calcTotInventory() << endl;
	cout << endl << endl;
	RetMenu();
}



/*
	SELL ITEMS FUNCTION
							*/
void SellItems()
{
	int choice, amnt, num1, num2;
	try{
		cout << "\t=============" << endl;
		cout << "\tSelling Items" << endl;
		cout << "\t=============" << endl << endl << endl;
		cout << "What item has been sold?" << endl << endl;
		for (int i = 0; i < store.getVecSize(); i++){
			cout << i + 1 << ": " << store.getItemName(i) << endl;
		}
		cout << "\nChoice::";
		cin >> choice;
		if (!cin)
			throw a;
		else if (choice < 1 || choice > store.getVecSize())
			throw a;
	}
	catch (string a){
		system("CLS");
		cout << a << endl << endl << endl;
		SellItems();
	}
	cout << "\nHow many '" << store.getItemName(choice - 1) << "' have been sold: ";
	cin >> amnt;
	num1 = store.getItemAvail(choice - 1);
	num1 = num1 - amnt;
	if (num1 < 0){//checks to see if user is trying to sell more than what they have
		cout << "You cannot sell that many. You do not have that many available." << endl;
		RetMenu();
	}
	num2 = store.getItemSold(choice - 1);
	num2 = num2 + amnt;
	store.SellItemAvail(choice - 1, num1);
	store.SellItemSold(choice - 1, num2);
	RetMenu();
}



/*
	ORDER ITEMS FUNCTION
							*/
void OrderItems()
{
	int choice, amnt, num1, num2;
	try{
		cout << "\t==============" << endl;
		cout << "\tOrdering Items" << endl;
		cout << "\t==============" << endl << endl << endl;
		cout << "What item has been ordered?" << endl << endl;
		for (int i = 0; i < store.getVecSize(); i++){
			cout << i + 1 << ": " << store.getItemName(i) << endl;
		}
		cout << "\nChoice::";
		cin >> choice;
		if (!cin)
			throw a;
		else if (choice < 1 || choice > store.getVecSize())
			throw a;
	}
	catch (string a){
		system("CLS");
		cout << a << endl << endl << endl;
		OrderItems();
	}
	cout << "\nHow many '" << store.getItemName(choice - 1) << "' have been ordered: ";
	cin >> amnt;
	num1 = store.getItemAvail(choice - 1);
	num1 = num1 + amnt;
	num2 = store.getItemOrdered(choice - 1);
	num2 = num2 + amnt;
	store.OrderItemAvail(choice - 1, num1);
	store.OrderItemOrdered(choice - 1, num2);
	RetMenu();
}



/*
	CHANGE PRICES FUNCTION
							*/
void ChangePrices()
{
	int choice;
	double amnt;
	try{
		cout << "\t===============" << endl;
		cout << "\tChanging Prices" << endl;
		cout << "\t===============" << endl << endl << endl;
		cout << "What price has been changed?" << endl << endl;
		for (int i = 0; i < store.getVecSize(); i++){
			cout << i + 1 << ": " << store.getItemName(i) << " - " << store.getItemSellPrice(i) << endl;
		}
		cout << "\nChoice::";
		cin >> choice;
		if (!cin)
			throw a;
		else if (choice < 1 || choice > store.getVecSize())
			throw a;
	}
	catch (string a){
		system("CLS");
		cout << a << endl << endl << endl;
		OrderItems();
	}
	cout << "What is the new price: ";
	cin >> amnt;
	store.ChngePrices(choice - 1, amnt);
	RetMenu();
}



/*
	SEARCH ITEM FUNCTION
							*/
void SearchItem()
{
	string itemName;
	int x = 0;
	string item;
	cout << "\t============" << endl;
	cout << "\tSearch Items" << endl;
	cout << "\t============" << endl << endl << endl;
	cout << "Enter the name of the item you're searching for: ";
	getline(cin, item);
	if (item.empty())//again, getline functions work strange. In this case, I check to see if the item variable contains a string or not.
		getline(cin, item);//if it does not contain anything, this line will activate.
	for (int i = 0; i < store.getVecSize(); i++){
		if (item == store.getItemName(i)){
			cout << "\nItem is in the store." << endl;
			if (store.getItemAvail(i) > 0) {//checks the item's availability.
				cout << "Item is also available." << endl << endl << endl;
				RetMenu();
			}
			else {
				cout << "Item is also unavailable." << endl << endl;
				RetMenu();
			}
		}
		else
			x++;//needed to have an else that did something, so it adds one to an arbitrary variable.
	}
	if (item != store.getItemName(store.getVecSize() - 1)) {
		cout << "\nItem is not in the store." << endl << endl;
		RetMenu();
	}
	
}


/*
	SORT NAMES FUNCTION
							*/
void quickSort(string arr[], int left, int right) {
	int i = left, j = right;
	string temp;
	string pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)	//...if these are less than the pivot..
			i++;				//check the next.
		while (arr[j] > pivot)	//...if these are more than the pivot...
			j--;				//check the next.
		if (i <= j) {			//...if [LEFT] is greater than or equal to [RIGHT]...
								//SWAP 'EM
			temp = arr[i];	
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(arr, left, j);//Recursion
	if (i < right)
		quickSort(arr, i, right);
}
void SortNames()
{
	
	cout << "\t=============" << endl;
	cout << "\tSorting Names" << endl;
	cout << "\t=============" << endl;
	//TURNING NAME VECTOR INTO STRING ARRAY
	//... this is done because the vectors are private variables and aren't as easily accessed as a global array.
	for (int i = 0; i < store.getVecSize(); i++) 
	{
		sortedName[i] = store.getItemName(i);
	}
	quickSort(sortedName, 0, store.getVecSize()-1);
	for (int i = 0; i < store.getVecSize(); i++) {
		cout << i + 1 << ". " << sortedName[i] << endl;
	}
	cout << endl;
	RetMenu();
}


/*
		MENU FUNCTION
							*/
int menu()
{
	bool valid = true;
	int choice;
	while (valid){
		try{
			cout << "\t__________________________________" << endl;
			cout << "\t||\t\tMENU\t\t||" << endl;
			cout << "\t||\t1. Display Records\t||" << endl;
			cout << "\t||\t2. Sell Items\t\t||" << endl;
			cout << "\t||\t3. Order Items\t\t||" << endl;
			cout << "\t||\t4. Change Prices\t||" << endl;
			cout << "\t||\t5. Search Item\t\t||" << endl;
			cout << "\t||\t6. Sort Items\t\t||" << endl;
			cout << "\t||\t7. Quit Program\t\t||" << endl;
			cout << "\t||______________________________||" << endl;
			cout << "\t  \tChoice:: ";
			cin >> choice;
			if (!cin) {
				throw a;
			}
			if (choice < 1 || choice > 7)
				throw a;
			else//confirms that user's input is valid and interpretable.
			{
				system("CLS");
				return choice;
			}
		}
		catch (string a)
		{
			system("CLS");
			cin.clear();//without this, the try catch block would continue to display and you'd be forced to quit the program
			cin.ignore(10000, '\n');
			cout << a << endl << endl << endl;
		}
	}
}



/*
		MAIN FUNCTION
							*/
int main()
{
	//getInfo() happens at the beginning of the compile so all the information is already ready for the user to control
	getInfo();
	switch (menu())
	{
	case 1:
		DispRecords();
		break;
	case 2:
		SellItems();
		break;
	case 3:
		OrderItems();
		break;
	case 4:
		ChangePrices();
		break;
	case 5:
		SearchItem();
		break;
	case 6:
		SortNames();
		break;
	case 7:
		system("CLS");
		//just a disclaimer
		cout << "Note: Any changes made are not permanent." << endl;
		exit(-1);
	}
}