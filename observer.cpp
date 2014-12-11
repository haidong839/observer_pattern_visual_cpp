// observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>

using namespace std;
using namespace System;

class Observer {
public: 
	virtual void notify() = 0;
};

class User : Observer
{
private:
	int userId;
	~User() {;}
public:
	User(int id)
	{
	    userId = id;
	}
	void  notify() {
	    Console::Write("---- Notified user with ID ");
		Console::Write(userId);
		Console::WriteLine();
	}
};

class EventSubject {

private:
	list<User*> *registeredUsers;
	~EventSubject(){;}
public:
	EventSubject(){
		registeredUsers = new list<User*>;
	}
	void registerUser(User* user)
	{
		registeredUsers->push_back(user);
	}

	void deregisterUser(User* user)
	{
		registeredUsers->remove(user);
	}
	void notifyUsers()
	{
		 list <User*>::iterator Iter;
		 User* user;
		 for(Iter = registeredUsers->begin(); Iter != registeredUsers->end(); Iter++)
		 {
			 user = *Iter;
			 user->notify();
		 }	         
	}
};





int _tmain(int argc, _TCHAR* argv[])
{
	User* user[10];
	EventSubject* eventSubject = new EventSubject();
	for(int ii=0; ii<10; ii++)
	{
		user[ii] = new User(ii);
		eventSubject->registerUser(user[ii]);
	}
	
	eventSubject->notifyUsers();

	Console::ReadLine();
	for(int ii=0; ii<10; ii++){
	    eventSubject->deregisterUser(user[ii]);
	}
	return 0;
}

