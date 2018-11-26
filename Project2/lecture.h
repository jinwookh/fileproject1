#pragma once
#include <iostream>
#include <string>
#include "delim.h"

#define LECID 12
#define LECPRICE 7
#define LECDUE 2
#define LECLEVEL 1
#define LECEXTENSION 1
#define STDMAXBUF 256

using namespace std;

class Lecture {
	char id[12];
	string subject;
	char level[1];
	char price[7];
	char extension[1];
	char dueDate[2];
	string nameOfTeacher;
	string textBook;

public:
	Lecture();
	Lecture(const char * new_id);
	Lecture(const Lecture & s);

	Lecture & operator = (const Lecture &s);
	bool operator == (const Lecture &s);
	bool operator != (const Lecture &s);



	friend istream & operator >> (istream &is, Lecture &s);
	friend ostream & operator << (ostream &os, Lecture &s);

	void update_id(const char * new_id) { memcpy(id, new_id, 12); }
	void update_subject(const string new_subject) { subject = new_subject; }
	void update_level(const char* new_level) { memcpy(level, new_level, 1); }
	void update_price(const char * new_price) { memcpy(price, new_price, 7); }
	void update_extension(const char* new_extension) { memcpy(extension, new_extension,1);  }
	void update_dueDate(const char* new_dueDate) { memcpy(dueDate, new_dueDate, 2); }
	void update_nameOfTeacher(const string new_teacher) { nameOfTeacher = new_teacher; }
	void update_textBook(const string new_textbook) { textBook = new_textbook; }


	bool Pack(IOBuffer & Buffer) const;
	bool Unpack(IOBuffer &);
};

istream & operator >> (istream &is, Lecture &s);
ostream & operator << (ostream &is, Lecture &s);

