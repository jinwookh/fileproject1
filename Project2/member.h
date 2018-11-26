#pragma once
#include <iostream>
#include <string>
#include "delim.h"

#define MEMBERID 10
#define MEMBERPASS 10
#define MEMBERPHONE 13
#define MEMBERMILEAGE 10
#define STDMAXBUF 256

using namespace std;

class Member {
	string id;
	string password;
	string name;
	string phoneNumber;
	string address;
	char mileage[10];

public:
	Member();
	Member(const string new_id);
	Member(const Member & s);

	Member & operator = (const Member &s);
	bool operator == (const Member &s);
	bool operator != (const Member &s);



	friend istream & operator >> (istream &is, Member &s);
	friend ostream & operator << (ostream &os, Member &s);

	void update_id(const string new_id) { id = new_id; }
	void update_name(const string new_name) { name = new_name; }
	void update_password(const string new_number) { password =new_number; }
	void update_phoneNumber(const string new_phoneNumber) { phoneNumber = new_phoneNumber; }
	void update_address(const string new_address) { address = new_address; }
	void update_mileage(const char *new_mileage) { memcpy(mileage, new_mileage, 10); }

	bool Pack(IOBuffer & Buffer) const;
	bool Unpack(IOBuffer &);
};

istream & operator >> (istream &is, Member &s);
ostream & operator << (ostream &is, Member &s);

