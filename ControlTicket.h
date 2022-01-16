#include"Economic.h"

class ControlTicket
{
private:

	Ticket** ticket;

public:
	int size = 0;

	ControlTicket();

	void add(Ticket* a);

	void show();

	int position(int id);

	int positionDate(string date);

	int nextId();

	void remove(int id);

	void updateDepartDate(int id, string newDepartDate);

	void updateType(int id, string newType);

	void updatePrice(int id, int newPrice);

	void updateDestination(int id, string newDestination);

	void showVip();

	void showBusiness();

	void showEconomic();

	void showTickets(int ticketId);

	Ticket** getTicket(string date,int&nr);

	void getTicket1(string date, string destination,int& nr);

	void load();

	string to_Save();

	void save();




};

