#include "Economic.h"

Economic::Economic(int id, string departDate, int handbagWeight, int price,string destination) :Ticket(id, departDate, "Economic", price,destination)
{
	this->handbagWeight = handbagWeight;
}

void Economic::setHandbagWeight(int handbagWeight)
{
	this->handbagWeight = handbagWeight;
}

int Economic::getHandbagWeight()
{
	return this->handbagWeight;
}

string Economic::description()
{
	string text = Ticket::description();

	text += "Handbag Weight: " + to_string(this->handbagWeight) + "\n";

	return text;
}

string Economic::toSave()
{
	string text = "";

	text += to_string(this->getId()) + " ";
	text += this->getDepartDate() + " ";
	text += this->getType() + " ";
	text += to_string(this->handbagWeight) + " ";
	text += to_string(this->getPrice())+" ";
	text += this->getDestination();

	return text;
}
