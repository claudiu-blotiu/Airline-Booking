#include "Economic.h"

Economic::Economic(int id, string customerName, string departDate, int handbagWeight, int price) :Ticket(id, customerName, departDate, "Economic", price)
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
	text += this->getCustomerName() + " ";
	text += this->getDepartDate() + " ";
	text += this->getType() + " ";
	text += to_string(this->handbagWeight) + " ";
	text += to_string(this->getPrice());

	return text;
}
