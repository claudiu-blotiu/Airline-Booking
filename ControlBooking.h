#include"Booking.h"

class ControlBooking
{
private:

	Booking** booking;

public:

	int size = 0;

	ControlBooking();

	void add(Booking* a);

	void show();

	int position(int id);

	int nextId();

	void remove(int id);

	void updateCustomerId(int id, int newCustomerId);

	void updateTicketId(int id, int newTicketId);

	/*void updateCustomerName(int id, string newCustomerName);

	void updateDepartureDate(int id, string newDepartureDate);

	void updateDestination(int id, string newDestination);*/

	Booking** getBooking_customer(int, int&);

	Booking** getBooking_id(int, int&);

	Booking* getHistory(int customerId, int& nr);
	

	void load();

	string to_Save();

	void save();




};

