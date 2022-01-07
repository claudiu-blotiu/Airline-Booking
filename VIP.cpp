#include "VIP.h"

VIP::VIP(int id, string customerName, string departDate, string benefits, int price) :Ticket(id, customerName, departDate, "VIP", price)
{
	this->benefits = benefits;
}

void VIP::setBenefits(string benefits)
{
	this->benefits = benefits;
}
string VIP::getBenefits()
{
	return this->benefits;
}

string VIP::description()
{
	string text = Ticket::description();

	text += "Benefits: " + this->benefits + "\n";

	return text;
}

string VIP::toSave()
{
	string text = "";

	text += to_string(this->getId()) + " ";
	text += this->getCustomerName() + " ";
	text += this->getDepartDate() + " ";
	text += this->getType() + " ";
	text += this->benefits + " ";
	text += to_string(this->getPrice());

	return text;
}




