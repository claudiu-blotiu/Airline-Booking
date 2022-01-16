#include "ControlCustomer.h"

ControlCustomer::ControlCustomer()
{
	customer = new Customer * [100];

	load();
}

void ControlCustomer::add(Customer* c)
{
	customer[size] = c;
	size++;
}

void ControlCustomer::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << customer[i]->description() << endl;
	}
}

int ControlCustomer::position(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (customer[i]->getId() == id)
		{
			return i;
		}
	}
	return -1;
}

int ControlCustomer::nextId()
{
	if (size == 0)
	{
		return 1;
	}
	return customer[size - 1]->getId() + 1;
}

void ControlCustomer::remove(int id)
{
	int p = position(id);
	for (int i = p; i < size - 1; i++)
	{
		customer[i] = customer[i + 1];
	}
	size--;
}

void ControlCustomer::updateName(int id, string newName)
{
	int p = position(id);
	if (p != -1)
	{
		customer[p]->setName(newName);
	}
	else
	{
		cout << "Wrong Customer Name" << endl;
	}
}

void ControlCustomer::updatePassword(int id, string newPassword)
{
	int p = position(id);
	if (p != -1)
	{
		customer[p]->setPassword(newPassword);
	}
	else
	{
		cout << "Wrong password" << endl;
	}
}

Customer* ControlCustomer::getUser(string name, string password)
{
	for (int i = 0; i < size; i++)
	{
		if (customer[i]->getName() == name && customer[i]->getPassword() == password)
		{
			return customer[i];
		}
	}
}

void ControlCustomer::load()
{
	ifstream read("Customer.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string name;
		read >> name;
		string password;
		read >> password;

		if (id > 0)
		{
			Customer* c = new Customer(id, name,password);
			this->add(c);
		}
	}
}

string ControlCustomer::to_Save()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		text += customer[i]->toSave() + "\n";
	}
	text += customer[i]->toSave();

	return text;
}

void ControlCustomer::save()
{
	ofstream f("Customer.txt");

	f << this->to_Save();

	f.close();
}




