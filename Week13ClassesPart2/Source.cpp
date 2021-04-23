// Collin McGhee
// CIS 1202 101
// April 23 2021

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"Publication.h"
using namespace std;

void getPublicationInfo(Publication& p)
{
	string itemTitle;
	cout << "The title?: ";
	cin >> itemTitle;
	cin.ignore(256, '\n');
	cout << endl;

	string itemPublication;
	cout << "Publisher Name?: ";
	cin >> itemPublication;
	cin.ignore(256, '\n');
	cout << endl;

	int inputType;
	PublicationType type;
	cout << "Enter publication type. 1. for book, 2 for magazine, 3 for Newspaper, 4 for Audio Format, 5 for Video Format: ";
	cin >> inputType;
	cin.ignore(256, '\n');
	cout << endl;

	while (inputType < 1 || inputType > 5)
	{
		cout << "Please enter a number between 1 and 5: ";
		cin >> inputType;
		cin.ignore(256, '\n');
		cout << endl;
	}

	if (inputType == 1)
		type = BOOK;
	else if (inputType == 2)
		type = MAGAZINE;
	else if (inputType == 3)
		type = NEWSPAPER;
	else if (inputType == 4)
		type = AUDIO;
	else if (inputType == 5)
		type = VIDEO;

	float itemPrice;
	cout << "Enter the item Price: ";
	cin >> itemPrice;
	cin.ignore(256, '\n');
	cout << endl;

	float itemYear;
	cout << "Enter the Year of the item: ";
	cin >> itemYear;
	cin.ignore(256, '\n');
	cout << endl;

	float itemStock;
	cout << "Enter the Stock of the item (how many): ";
	cin >> itemStock;
	cin.ignore(256, '\n');
	cout << endl;

	p.storePublication(itemTitle, itemPublication, itemPrice, itemYear, type, itemStock);
}

void getPublications(Publication books[], int& count)
{
	fstream file;
	file.open("Publications.txt", ios::in);
	file.clear();
	file.seekg(0);

	string itemTitle, itemPublication, sItemPrice, sItemYear, sType, sItemStock;
	int inputType;
	float itemPrice, itemYear, itemStock;
	PublicationType type;

	while (file && !file.eof())
	{
		//---Read from file as strings
		getline(file, itemTitle);
		getline(file, itemPublication);
		getline(file, sItemPrice);
		getline(file, sItemYear);
		getline(file, sType);
		getline(file, sItemStock);

		//cout << "File Contents\n";
		//cout << itemTitle << endl << itemPublication << endl << sItemPrice << endl << sItemYear << endl << sType << endl << sItemStock << endl;

		//---Convert neccassary items to their correct types if needed
		itemPrice = stof(sItemPrice);
		itemYear = stof(sItemYear);
		inputType = stoi(sType);
		itemStock = stof(sItemStock);
		//cout << inputType;

		//---get the publication type enum from type integer
		if (inputType == 0)
			type = BOOK;
		else if (inputType == 1)
			type = MAGAZINE;
		else if (inputType == 2)
			type = NEWSPAPER;
		else if (inputType == 3)
			type = AUDIO;
		else if (inputType == 4)
			type = VIDEO;

		//---Add all variables to the books class array
		books[count].storePublication(itemTitle, itemPublication, itemPrice, itemYear, type, itemStock);
		count++;
	}

	file.close();
}

void showPublications(Publication books[], int count)
{
	//---Loop through the books array and call the displayInfo command for each one
	cout << "Displaying all info\n\n";
	for (int i = 0; i < count; i++)
	{
		books[i].displayInfo();
		cout << "-----------------------------------\n";
	}
}

void showTitles(Publication books[], int count)
{
	//---Display all titles by calling the classes getTitle function
	cout << "Displaying all titles\n";
	for (int i = 0; i < count; i++)
	{
		cout << "Title " << (i + 1) << " : " << books[i].getTitle() << endl;
	}
	cout << "-----------------------------------\n";
}

int findPublication(Publication books[], int count, string title)
{
	//---Loop through the books array and using the getTitle function to find if the searched for book exists
	int position = -1;//---Set to -1 so if no book is found it stays at that value and can be truened to tell if no book of that title was found.
	for (int i = 0; i < count; i++)
	{
		cout << title << " : " << books[i].getTitle() << endl;
		if (title == books[i].getTitle())
		{
			position = i;
		}
	}
	return position;
}

int getMenuChoice()
{
	int choice = 0;

	cout << "1. Display all publications\n2. Display all publication titles\n3. Find a publication\n4. Check out\n5. Check in\n6. Exit\n";
	cout << "Enter an option: ";

	cin >> choice;
	cin.ignore(256, '\n');
	cout << endl;

	while (choice < 1 || choice > 6)
	{
		cout << "Please enter a number between 1 and 6.\n";
		cout << "Enter an option: ";

		cin >> choice;
		cin.ignore(256, '\n');
		cout << endl;
	}
	return choice;
}

int main()
{
	Publication books[6];
	int menu = 0;
	int count = 0;
	string title;
	int found = 0;

	getPublications(books, count);

	while (true)
	{
		menu = getMenuChoice();
		switch(menu)
		{
		//---Display all publications
		case 1:
		{
			showPublications(books, count);
			break;
		}
		//---Display all publication titles
		case 2:
		{
			showTitles(books, count);
			break;
		}
		//---Find a publication
		case 3:
		{
			cout << "Which title are you looking for? ";
			//cin.ignore();
			getline(cin, title);
			found = findPublication(books, count, title);
			if (found == -1)
				cout << "Publication not found.\n";
			else
				cout << "Publication found. Array position at : " << found << endl;
			break;
		}
		//---Check out
		case 4:
		{
			cout << "Which title are you looking to check out? ";
			//cin.ignore();
			getline(cin, title);
			found = findPublication(books, count, title);
			if (found == -1)
				cout << "Publication not found.\n";
			else
			{
				cout << "Publication found. Checking out." << endl;
				books[found].checkOut();
			}
			break;
		}
		//---Check in
		case 5:
		{
			cout << "Which title are you looking to check in? ";
			//cin.ignore();
			getline(cin, title);
			found = findPublication(books, count, title);
			if (found == -1)
				cout << "Publication not found.\n";
			else
			{
				cout << "Publication found. Checking in." << endl;
				books[found].checkIn();
			}
			break;
		}
		//---Quit
		case 6:
		{
			return 0;
		}
		}
	}
}