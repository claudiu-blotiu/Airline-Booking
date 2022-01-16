#include"Business.h"

class Economic:public Ticket
{
private:

	int handbagWeight = 1;

public:

	Economic()
	{

	}

	Economic(int, string,int, int, string);

	void setHandbagWeight(int);
	int getHandbagWeight();

	string description();

	string toSave();


};

