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

	int nextId();

	void remove(int id);

	void updateCustomerName(int id, string newCustomerName);
	
	void updateDepartDate(int id, string newDepartDate);

	void updateType(int id, string newType);

	void updatePrice(int id, int newPrice);

	void load();

	string to_Save();

	void save();




};

