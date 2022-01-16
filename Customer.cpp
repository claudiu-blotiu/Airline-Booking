#include "Customer.h"

Customer::Customer(int id, string name,string password)
{
	this->id = id;
	this->name = name;
	this->password = password;
}

void Customer::setId(int id)
{
	this->id = id;
}
int Customer::getId()
{
	return this->id;
}

void Customer::setName(string name)
{
	this->name = name;
}
string Customer::getName()
{
	return this->name;
}

void Customer::setPassword(string password)
{
	this->password = password;
}
string Customer::getPassword()
{
	return this->password;
}

string Customer::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Name: " + this->name + "\n";
	text += "Password: " + this->password + "\n";

	return text;
}

string Customer::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += this->name + " ";
	text += this->password;

	return text;
}


