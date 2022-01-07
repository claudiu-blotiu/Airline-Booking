#include"Ticket.h"

class VIP:public Ticket
{
private:

	string benefits = "";

public:

	VIP()
	{

	}

	VIP(int, string, string, string, int);

	void setBenefits(string);
	string getBenefits();

	string description();

	string toSave();





};

