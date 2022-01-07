#include "Business.h"

Business::Business(int id, string customerName, string departDate, int seatNr, int price) :Ticket(id, customerName, departDate, "Business", price)
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
	text += this->getCustomerName() + " ";
	text += this->getDepartDate() + " ";
	text += this->getType() + " ";
	text += to_string(this->seatNr) + " ";
	text += to_string(this->getPrice());

	return text;
}


