#include"Publication.h"
#include<iostream>
using namespace std;

void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock)
{
	title = itemTitle;
	publisher = itemPublisher;
	price = itemPrice;
	year = itemYear;
	type = itemType;
	stock = itemStock;
}
void Publication::displayInfo()
{
	cout << "Title      : " << title << endl;
	cout << "Publisher  : " << publisher << endl;
	cout << "Type       : ";
	if (type == BOOK)
		cout << "Book\n";
	else if (type == MAGAZINE)
		cout << "Magazine\n";
	else if (type == NEWSPAPER)
		cout << "Newspaper\n";
	else if (type == AUDIO)
		cout << "Audio\n";
	else if (type == VIDEO)
		cout << "Video\n";
	else
		cout << "Unknown\n";

}
void Publication::checkOut()
{
	if (stock == 0)
	{
		cout << "Error, stock can't go below 0.\n";
	}
	else
		stock--;
}
void Publication::checkIn()
{
	stock++;
}
string Publication::getTitle()
{
	return title;
}
int Publication::getStock()
{
	return stock;
}