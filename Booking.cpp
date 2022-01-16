#include "Booking.h"

Booking::Booking(int id,int customerId,int ticketId/*string customerName, string departureDate, string destination*/)
{
	this->id = id;
	this->customerId=customerId;
	this->ticketId=ticketId;
	/*this->customerName = customerName;
	this->departureDate = departureDate;
	this->destination = destination;*/
}

void Booking::setId(int id)
{
	this->id = id;
}
int Booking::getId()
{
	return this->id;
}

void Booking::setCustomerId(int customerId)
{
	this->customerId = customerId;
}
int Booking::getCustomerId()
{
	return this->customerId;
}

void Booking::setTicketId(int ticketId)
{
	this->ticketId = ticketId;
}
int Booking::getTicketId()
{
	return this->ticketId;
}

//void Booking::setCustomerName(string customerName)
//{
//	this->customerName = customerName;
//}
//string Booking::getCustomerName()
//{
//	return this->customerName;
//}
//
//void Booking::setDepartureDate(string departureDate)
//{
//	this->departureDate = departureDate;
//}
//string Booking::getDepartureDate()
//{
//	return this->departureDate;
//}
//
//void Booking::setDestination(string destination)
//{
//	this->destination = destination;
//}
//string Booking::getDestination()
//{
//	return this->destination;
//}

string Booking::description()
{
	string text = "";

	text += "Id: " + to_string(this->id) + "\n";
	text += "Customer Id: " + to_string(this->customerId) + "\n";
	text += "Ticket Id: " + to_string(this->ticketId) + "\n";
	/*text += "Customer name: " + this->customerName + "\n";
	text += "Departure Date: " + this->departureDate + "\n";
	text += "Destination: " + this->destination + "\n";*/

	return text;

}

string Booking::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += to_string(this->customerId) + " ";
	text += to_string(this->ticketId);

	return text;
}


