#include"VIP.h"

class Business :public Ticket
{
private:

	int seatNr = 1;

public:

	Business()
	{

	}

	Business(int, string, int, int,string);

	void setSeatNr(int);
	int getSeatNr();

	string description();

	string toSave();


};

