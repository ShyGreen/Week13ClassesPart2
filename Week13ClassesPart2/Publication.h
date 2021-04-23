#pragma once
#include<string>
using namespace std;

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication
{
private:
	string title;
	string publisher;
	float price;
	int year;
	PublicationType type;
	int stock;
public:
	void storePublication(string, string, double, int, PublicationType, int);
	void displayInfo();
	void checkOut();
	void checkIn();
	string getTitle();
	int getStock();
};