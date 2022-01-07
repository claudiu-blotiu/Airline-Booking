#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Ticket
{
private:

	int id = 1;
	string customerName = "";
	string departureDate = "";
	string type = "";
	int price = 1;

public:

	Ticket()
	{

	}

	Ticket(int, string, string, string, int);

	void setId(int);
	int getId();

	void setCustomerName(string);
	string getCustomerName();

	void setDepartDate(string);
	string getDepartDate();

	void setType(string);
	string getType();

	void setPrice(int);
	int getPrice();

	virtual string description();

	virtual string toSave();



};

