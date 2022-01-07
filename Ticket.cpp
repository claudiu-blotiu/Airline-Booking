#include "Ticket.h"

Ticket::Ticket(int id, string customerName, string departDate, string  type, int price)
{
	this->id = id;
	this->customerName = customerName;
	this->departureDate = departDate;
	this->type = type;
	this->price = price;
}

void Ticket::setId(int id)
{
	this->id = id;
}
int Ticket::getId()
{
	return this->id;
}

void Ticket::setCustomerName(string customerName)
{
	this->customerName = customerName;
}
string Ticket::getCustomerName()
{
	return this->customerName;
}

void Ticket::setDepartDate(string departDate)
{
	this->departureDate = departDate;
}
string Ticket::getDepartDate()
{
	return this->departureDate;
}

void Ticket::setType(string type)
{
	this->type = type;
}
string Ticket::getType()
{
	return this->type;
}

void Ticket::setPrice(int price)
{
	this->price = price;
}
int Ticket::getPrice()
{
	return this->price;
}

string Ticket::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Customer Name: " + this->customerName + "\n";
	text += "Depart Date: " + this->departureDate + "\n";
	text += "Type: " + this->type + "\n";
	text += "Price: " + to_string(this->price) + "\n";

	return text;
}

string Ticket::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += this->customerName + " ";
	text += this->departureDate + " ";
	text += this->type + " ";
	text += to_string(this->price);

	return text;
}
