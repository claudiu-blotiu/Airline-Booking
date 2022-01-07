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
}

void ControlTicket::updateCustomerName(int id, string newCustomerName)
{
	int p = position(id);
	if (p != -1)
	{
		ticket[p]->setCustomerName(newCustomerName);
	}
	else
	{
		cout << "Wrong customer Name" << endl;
	}
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

void ControlTicket::load()
{
	ifstream read("Ticket.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string customerName;
		read >> customerName;
		string departDate;
		read >> departDate;
		string type;
		read >> type;
		int price;
		if (type == "VIP")
		{
			string benefits;
			read >> benefits;
			read >> price;
			Ticket* a = new VIP(id, customerName, departDate, benefits, price);
			this->add(a);
		}
		if (type == "Business")
		{
			int seatNr;
			read >> seatNr;
			read >> price;
			Ticket* b = new Business(id, customerName, departDate, seatNr, price);
			this->add(b);
		}
		if (type == "Economic")
		{
			int bagWeight;
			read >> bagWeight;
			read >> price;
			Ticket* c = new Economic(id, customerName, departDate, bagWeight, price);
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



