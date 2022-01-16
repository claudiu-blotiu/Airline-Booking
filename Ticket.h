#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Ticket
{
private:

	int id = 1;
	string departureDate = "";
	string type = "";
	int price = 1;
	string destination = "";

public:

	Ticket()
	{

	}

	Ticket(int, string, string, int,string);

	void setId(int);
	int getId();

	void setDepartDate(string);
	string getDepartDate();

	void setType(string);
	string getType();

	void setPrice(int);
	int getPrice();

	void setDestination(string);
	string getDestination();

	virtual string description();

	virtual string toSave();



};

