#include "Login.h"

Login::Login()
{
	this->listaClient = new ControlCustomer();
}

string Login::meniu()
{
	string text = "";

	text +="-----------------------------------";
	text += "\nApasati tasta 1 pentru Login";
	text += "\nApasati tasta 2 pentru Register";
	text += "\n-----------------------------------\n";

	return text;
}

void Login::play()
{
	bool quit = false;

	int choise;

	while (quit == false)
	{
		cout << meniu() << endl;

		string x;

		cin >> x;

		choise = stoi(x);

		switch (choise)
		{
		case 1:login();
			break;
		case 2:registerU();
			break;
		}
	}
}

void Login::login()
{
	string user;

	cout << "Introduceti numele" << endl;

	cin >> user;

	string parola;

	cout << "Introduceti parola" << endl;

	cin >> parola;

	Customer* c = listaClient->getUser(user, parola);

	if (c->getName() == user)
	{
		View* view = new View(c);

		view->play();
	}
	else
	{
		cout << "Wrong username or password" << endl;
	}
}

void Login::registerU()
{
	string name = "";

	cout << "Introduceti Numele dv" << endl;

	cin >> name;

	string password = "";

	cout << "Introduceti parola dv" << endl;

	cin >> password;

	Customer* c = new Customer(listaClient->nextId(), name, password);

	listaClient->add(c);

	listaClient->save();
}










