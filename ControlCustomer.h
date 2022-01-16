#include"Customer.h"

class ControlCustomer
{

private:

	Customer** customer;

public:
	int size = 0;

	ControlCustomer();

	void add(Customer* c);

	void show();

	int position(int id);

	int nextId();

	void remove(int id);

	void updateName(int id, string newName);

	void updatePassword(int id, string newPassword);

	Customer* getUser(string name, string password);

	void load();

	string to_Save();

	void save();









};

