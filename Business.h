#include"VIP.h"

class Business :public Ticket
{
private:

	int seatNr = 1;

public:

	Business()
	{

	}

	Business(int, string, string, int, int);

	void setSeatNr(int);
	int getSeatNr();

	string description();

	string toSave();


};

