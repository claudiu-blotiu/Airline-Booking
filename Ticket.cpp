#include "Ticket.h"

Ticket::Ticket(int id, string departDate, string  type, int price,string destination)
{
	this->id = id;
	this->departureDate = departDate;
	this->type = type;
	this->price = price;
	this->destination = destination;
}

void Ticket::setId(int id)
{
	this->id = id;
}
int Ticket::getId()
{
	return this->id;
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

void Ticket::setDestination(string destination)
{
	this->destination = destination;
}
string Ticket::getDestination()
{
	return this->destination;
}

string Ticket::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Depart Date: " + this->departureDate + "\n";
	text += "Type: " + this->type + "\n";
	text += "Price: " + to_string(this->price) + "\n";
	text += "Destination: " + this->destination + "\n";

	return text;
}

string Ticket::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += this->departureDate + " ";
	text += this->type + " ";
	text += to_string(this->price)+" ";
	text += this->destination;
	return text;
}
