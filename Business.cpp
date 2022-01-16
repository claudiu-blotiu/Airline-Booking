#include "Business.h"

Business::Business(int id, string departDate, int seatNr, int price,string destination) :Ticket(id, departDate, "Business", price,destination)
{
	this->seatNr = seatNr;
}

void Business::setSeatNr(int seatNr)
{
	this->seatNr = seatNr;
}

int Business::getSeatNr()
{
	return this->seatNr;
}

string Business::description()
{
	string text = Ticket::description();

	text += "Seat Nr: " + to_string(this->seatNr) + "\n";

	return text;
}

string Business::toSave()
{
	string text = "";

	text += to_string(this->getId()) + " ";
	text += this->getDepartDate() + " ";
	text += this->getType() + " ";
	text += to_string(this->seatNr) + " ";
	text += to_string(this->getPrice())+" ";
	text += this->getDestination();

	return text;
}


