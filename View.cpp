#include "View.h"

View::View(Customer* c)
{
	this->client = c;

	ticketList = new ControlTicket();

	clientList = new ControlCustomer();

	bookingList = new ControlBooking();
}

string View::meniu()
{
	string text = "";

	text += "-----------------------------------------------------------";
	text += "\nApasati tasta 1 pentru a vedea toate Biletele disponibile";
	text += "\nApasati tasta 2 pentru a vedea biletele cumparate";
	text += "\nApasati tasta 3 pentru a rezerva un bilet";
	text += "\nApasati tasta 4 pentru a sterge un bilet";
	text += "\nApasati tasta 5 pentru a finaliza tranzactia";
	text += "\nApasati tasta 6 pentru a vedea istoricul biletelor";
	text += "\n-----------------------------------------------------------";
	cout << endl;

	return text;
}

void View::play()
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
		case 1:viewTickets();
			break;
		case 2:viewBooking();
			break;
		case 3:add();
			break;
		case 4:remove();
			break;
		case 5:save();
			break;
		case 6:history();
			break;
		}
	}

}

void View::viewTickets()
{
	cout << "--------Bilet clasa Vip--------" << endl;
	this->ticketList->showVip();
	cout << "--------Bilet clasa Business--------" << endl;
	this->ticketList->showBusiness();
	cout << "--------Bilet clasa Economic--------" << endl;
	this->ticketList->showEconomic();
}

void View::viewBooking()
{
	int ct = 0;
	Booking** rent = bookingList->getBooking_customer(this->client->getId(), ct);
	
	for (int i = 0; i < ct; i++)
	{
		ticketList->showTickets(rent[i]->getTicketId());
	}
}

void View::add()
{
	cout << "Introduceti data in care doriti sa zburati" << endl;

	int ct = 0;

	string departDate = "";

	cin >> departDate;

	//functie ce afiseaza biletele in functie de data si destinatie

	cout << "Introduceti destinatia dorita" << endl;

	string destination = "";

	cin >> destination;

	cout << endl;

	ticketList->getTicket1(departDate, destination, ct);

	if (ct == 0)
	{
		cout << "Wrong Ticket data" << endl;
	}
	else {

		cout << "Introduceti Id ticketului dorit" << endl;

		int ticketId = 0;

		cin >> ticketId;

		Booking* book = new Booking(bookingList->nextId(), client->getId(), ticketId);

		bookingList->add(book);
	}

}

void View::remove()
{
	int bookingID = 0;

	cout << "Introduceti ID inchirierii" << endl;

	cin >> bookingID;

	int ct = 0;

	Booking** retur = bookingList->getBooking_id(bookingID, ct);

	for (int i = 0; i < ct; i++)
	{
		if (retur[i]->getCustomerId() == client->getId())
		{
			bookingList->remove(retur[i]->getId());
		}
	}
}

void View::save()
{
	bookingList->save();
}

void View::history()
{
	int ct = 0;

	Booking* istoric = bookingList->getHistory(client->getId(), ct);

	for (int i = 0; i < ct; i++)
	{
		cout << istoric[i].description() << endl;
	}
}




