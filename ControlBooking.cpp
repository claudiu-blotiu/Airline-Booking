#include "ControlBooking.h"

ControlBooking::ControlBooking()
{
	booking = new Booking * [100];

	load();
}

void ControlBooking::add(Booking* a)
{
	booking[size] = a;
	size++;
}

void ControlBooking::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << booking[i]->description() << endl;
	}
}

int ControlBooking::position(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (booking[i]->getId() == id)
		{
			return i;
		}
	}
	return -1;
}

int ControlBooking::nextId()
{
	if (size == 0)
	{
		return 1;
	}
	return booking[size - 1]->getId() + 1;
}

void ControlBooking::remove(int id)
{
	int p = position(id);
	for (int i = p; i < size - 1; i++)
	{
		booking[i] = booking[i + 1];
	}
	size--;
}

void ControlBooking::updateCustomerId(int id, int newCustomerId)
{
	int p = position(id);
	if (p != -1)
	{
		booking[p]->setCustomerId(newCustomerId);
	}
	else
	{
		cout << "Wrong Customer Id"<<endl;
	}
}

void ControlBooking::updateTicketId(int id, int newTicketId)
{
	int p = position(id);
	if (p != -1)
	{
		booking[p]->setTicketId(newTicketId);
	}
	else
	{
		cout << "Wrong Ticket Id" << endl;
	}
}

//void ControlBooking::updateCustomerName(int id, string newCustomerName)
//{
//	int p = position(id);
//	if (p != -1)
//	{
//		booking[p]->setCustomerName(newCustomerName);
//	}
//	else
//	{
//		cout << "Wrong Customer Name" << endl;
//	}
//}
//
//void ControlBooking::updateDepartureDate(int id, string newDepartureDate)
//{
//	int p = position(id);
//	if (p != -1)
//	{
//		booking[p]->setDepartureDate(newDepartureDate);
//	}
//	else
//	{
//		cout << "Wrong Departure date" << endl;
//	}
//}
//
//void ControlBooking::updateDestination(int id, string newDestination)
//{
//	int p = position(id);
//	if (p != -1)
//	{
//		booking[p]->setDestination(newDestination);
//	}
//	else
//	{
//		cout << "Wrong Destination" << endl;
//	}
//	
//}

Booking** ControlBooking::getBooking_customer(int clientId, int& nr)
{
	nr = 0;

	Booking** rent = new Booking * [100];

	for (int i = 0; i < size; i++)
	{
		if (booking[i]->getCustomerId() == clientId)
		{
			rent[nr] = booking[i];

			nr++;
		}
	}
	return rent;
}

Booking** ControlBooking::getBooking_id(int bookingId, int& nr)
{
	nr = 0;
	Booking** inchiriere = new Booking * [100];

	for (int i = 0; i < size; i++) {


		if (booking[i]->getId() == bookingId) {

			inchiriere[nr] = booking[i];

			nr++;
		}
	}
	return inchiriere;
}

Booking* ControlBooking::getHistory(int customerId,int&nr)
{
	nr = 0;

	Booking* book = new Booking[100];

	for (int i = 0; i < size; i++)
	{
		if (booking[i]->getCustomerId() == customerId)
		{
			book[nr] = *booking[i];

			nr++;
		}
	}

	return book;
}

void ControlBooking::load()
{
	ifstream read("Booking.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		int customerId;
		read >> customerId;
		int ticketId;
		read >> ticketId;

		if (id > 0)
		{
			Booking* a = new Booking(id, customerId, ticketId);
			this->add(a);
		}
	}
}

string ControlBooking::to_Save()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size-1; i++)
	{
		text += booking[i]->toSave() + "\n";
	}
	text += booking[i]->toSave();
	return text;
}

void ControlBooking::save()
{
	ofstream f("Booking.txt");

	f << this->to_Save();

	f.close();
}



