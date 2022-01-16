#include "ControlTicket.h"

ControlTicket::ControlTicket()
{
	ticket = new Ticket * [100];

	load();
}

void ControlTicket::add(Ticket* a)
{
	ticket[size] = a;
	size++;
}

void ControlTicket::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << ticket[i]->description() << endl;
	}
}

int ControlTicket::position(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (ticket[i]->getId() == id)
		{
			return i;
		}
	}
	return -1;
}

int ControlTicket::positionDate(string date)
{
	for (int i = 0; i < size; i++)
	{
		if (ticket[i]->getDepartDate() == date)
		{
			return i;
		}
	}
	return -1;
}

int ControlTicket::nextId()
{
	if (size == 0)
	{
		return 1;
	}
	return ticket[size - 1]->getId() + 1;
}

void ControlTicket::remove(int id)
{
	int p = position(id);
	for (int i = p; i < size - 1; i++)
	{
		ticket[i] = ticket[i + 1];
	}
	size--;
}

void ControlTicket::updateDepartDate(int id, string newDepartDate)
{
	int p = position(id);
	if (p != -1)
	{
		ticket[p]->setDepartDate(newDepartDate);
	}
	else
	{
		cout << "Wrong depart Date" << endl;
	}
}

void ControlTicket::updateType(int id, string newType)
{
	int p = position(id);
	if (p != -1)
	{
		ticket[p]->setType(newType);
	}
	else
	{
		cout << "Wrong Type" << endl;
	}
}

void ControlTicket::updatePrice(int id, int newPrice)
{
	int p = position(id);
	if (p != -1)
	{
		ticket[p]->setPrice(newPrice);
	}
	else
	{
		cout << "Wrong Price" << endl;
	}
}

void ControlTicket::updateDestination(int id, string newDestination)
{
	int p = position(id);
	
	if (p != -1)
	{
		ticket[p]->setDestination(newDestination);
	}
	else
	{
		cout << "Wrong destination" << endl;
	}
}

void ControlTicket::showVip()
{
	for (int i = 0; i < size; i++)
	{
		VIP* a = dynamic_cast<VIP*>(ticket[i]);

		if (a != NULL)
		{
			cout << a->description() << endl;
		}
	}
}

void ControlTicket::showBusiness()
{
	for (int i = 0; i < size; i++)
	{
		Business* b = dynamic_cast<Business*>(ticket[i]);

		if (b != NULL)
		{
			cout << b->description() << endl;
		}
	}
}

void ControlTicket::showEconomic()
{
	for (int i = 0; i < size; i++)
	{
		Economic* c = dynamic_cast<Economic*>(ticket[i]);

		if (c != NULL)
		{
			cout << c->description() << endl;
		}
	}
}

void ControlTicket::showTickets(int ticketId)
{
	for (int i = 0; i < size; i++)
	{
		if (ticket[i]->getId() == ticketId)
		{
			cout << ticket[i]->description() << endl;
		}
	}
}

Ticket** ControlTicket::getTicket(string date ,int&nr)
{
	nr = 0;

	Ticket** bilet = new Ticket * [100];

	for (int i = 0; i < size; i++)
	{
		if (ticket[i]->getDepartDate() == date)
		{
			bilet[nr] = ticket[i];

			nr++;
		}
	}
	return bilet;

	/*int poz = positionDate(date);

	return ticket[poz];*/
}

void ControlTicket::getTicket1(string date, string destination ,int &nr)
{
	nr = 0;
	for (int i = 0; i < size; i++)
	{
		if (ticket[i]->getDepartDate() == date && ticket[i]->getDestination()==destination)
		{
			cout << ticket[i]->description() << endl;

			nr++;
		}
	}
}

void ControlTicket::load()
{
	ifstream read("Ticket.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string departDate;
		read >> departDate;
		string type;
		read >> type;
		int price;
		string destination;
		if (type == "VIP")
		{
			string benefits;
			read >> benefits;
			read >> price;
			read >> destination;
			Ticket* a = new VIP(id, departDate, benefits, price,destination);
			this->add(a);
		}
		if (type == "Business")
		{
			int seatNr;
			read >> seatNr;
			read >> price;
			read >> destination;
			Ticket* b = new Business(id, departDate, seatNr, price, destination);
			this->add(b);
		}
		if (type == "Economic")
		{
			int bagWeight;
			read >> bagWeight;
			read >> price;
			read >> destination;
			Ticket* c = new Economic(id, departDate, bagWeight, price, destination);
			this->add(c);
		}
		
	}
}

string ControlTicket::to_Save()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		text += ticket[i]->toSave() + "\n";
	}
	text += ticket[i]->toSave();
	return text;
}

void ControlTicket::save()
{
	ofstream f("Ticket.txt");

	f << this->to_Save();

	f.close();
}



