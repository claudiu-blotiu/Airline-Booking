#include"ControlTicket.h"

class Booking
{
private:

	int id = 1;
	int customerId = 1;
	int ticketId = 1;
	/*string customerName = "";*/
	/*string departureDate = "";
	string destination = "";*/

public:

	Booking()
	{

	}

	Booking(int,int,int/*string, string, string*/);

	void setId(int);
	int getId();

	void setCustomerId(int);
	int getCustomerId();

	void setTicketId(int);
	int getTicketId();

	/*void setCustomerName(string);
	string getCustomerName();

	void setDepartureDate(string);
	string getDepartureDate();

	void setDestination(string);
	string getDestination();*/

	string description();

	string toSave();







};

