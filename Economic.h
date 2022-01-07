#include"Business.h"

class Economic:public Ticket
{
private:

	int handbagWeight = 1;

public:

	Economic()
	{

	}

	Economic(int, string, string, int, int);

	void setHandbagWeight(int);
	int getHandbagWeight();

	string description();

	string toSave();


};

