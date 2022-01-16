#include"ControlCustomer.h"

class View
{
private:

	Customer* client;
	/*Ticket* bilet;*/
	ControlTicket* ticketList;
	ControlCustomer* clientList;
	ControlBooking* bookingList;

public:

	View(Customer* c);

	string meniu();

	void play();

	void viewTickets();

	void viewBooking();

	void add();

	void remove();

	void save();

	void history();





};

