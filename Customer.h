#include"ControlBooking.h"

class Customer
{
private:

	int id = 1;
	string name = "";
	string password = "";

public:

	Customer()
	{

	}

	Customer(int, string,string);

	void setId(int);
	int getId();

	void setName(string);
	string getName();

	void setPassword(string);
	string getPassword();

	string description();

	string toSave();



};

