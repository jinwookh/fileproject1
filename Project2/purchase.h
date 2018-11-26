#pragma once
#include <iostream>
#include <string>
#include "delim.h"

#define PURCHASEID 16
#define LECID 12
#define MEMID 10
#define MILEAGE 10
#define STDMAXBUF 256

using namespace std;

class Purchase {
	char id[16];
	char lectureId[12];
	string memberId;
	char mileage[10];
	

public:
	Purchase();
	Purchase(const char * new_id);
	Purchase(const Purchase & s);

	Purchase & operator = (const Purchase &s);
	bool operator == (const Purchase &s);
	bool operator==(const Purchase s);
	bool operator != (const Purchase &s);



	friend istream & operator >> (istream &is, Purchase &s);
	friend ostream & operator << (ostream &os, Purchase &s);

	void update_id(const char * new_id) { memcpy(id, new_id, 16); }
	void update_lectureId(const char * new_lectureId) { memcpy(lectureId, new_lectureId, 12); }
	void update_memberId(const string new_MemberId) { memberId = new_MemberId; }
	void update_mileage(const char * new_mileage) { memcpy(mileage, new_mileage, 10); }
	

	bool Pack(IOBuffer & Buffer) const;
	bool Unpack(IOBuffer &);
};

istream & operator >> (istream &is, Purchase &s);
ostream & operator << (ostream &is, Purchase &s);

