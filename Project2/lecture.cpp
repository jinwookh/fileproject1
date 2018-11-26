#include "lecture.h"
#include <sstream>
#include <string>

Lecture::Lecture() {

}

Lecture::Lecture(const char * new_id) {
	memcpy(id, new_id, 12);
}

Lecture::Lecture(const Lecture & s) {
	update_id(s.id);
	update_subject(s.subject);
	update_level(s.level);
	update_price(s.price);
	update_extension(s.extension);
	update_dueDate(s.dueDate);
	update_nameOfTeacher(s.nameOfTeacher);
	update_textBook(s.textBook);
}
//이 함수는 생성자임
Lecture & Lecture::operator = (const Lecture & s) {
	update_id(s.id);
	update_subject(s.subject);
	update_level(s.level);
	update_price(s.price);
	update_extension(s.extension);
	update_dueDate(s.dueDate);
	update_nameOfTeacher(s.nameOfTeacher);
	update_textBook(s.textBook);
	return *this;
}//위 함수와 차이가 무엇인가?
//이 함수는 복사하는 거임. 복사하는 객체, 복사받는 객체 두 객체가 이미 생성되었다고 전제함.

bool Lecture::operator == (const Lecture & s) {
	return !memcmp(id, s.id, 12);
}

bool Lecture::operator != (const Lecture & s) {
	return !(0 == memcmp(id, s.id, 12));
}

istream & operator >> (istream & is, Lecture & s) {
	string st;
	is.exceptions(istream::failbit | istream::badbit);
	try {
		getline(is, st);
	}
	catch (istream::failure e) {
		return is;
	}
	istringstream iss(st);
	string token;
	getline(iss, token, '|');
	s.update_id(token.data());
	getline(iss, token, '|');
	s.update_subject(token);
	getline(iss, token, '|');
	s.update_level(token.data());
	getline(iss, token, '|');
	s.update_price(token.data());
	getline(iss, token, '|');
	s.update_extension(token.data());
	getline(iss, token, '|');
	s.update_dueDate(token.data());
	getline(iss, token, '|');
	s.update_nameOfTeacher(token.data());
	getline(iss, token, '|');
	s.update_textBook(token.data());

	return is;
}

bool Lecture::Pack(IOBuffer & Buffer) const {
	int numBytes;
	Buffer.Clear();
	string s_id(id, LECID);
	string s_level(level, LECLEVEL);
	string s_extension(extension, LECEXTENSION);
	string s_price(price, LECPRICE);
	string s_dueDate(dueDate, LECDUE);
	

	numBytes = Buffer.Pack(s_id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(subject.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_level.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_price.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_extension.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_dueDate.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(nameOfTeacher.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(textBook.c_str());
	if (numBytes == -1) return false;
	

	return true;
}

bool Lecture::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[STDMAXBUF];

	numBytes = Buffer.Unpack(id, LECID);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	subject = buf;
	numBytes = Buffer.Unpack(level, LECLEVEL);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(price, LECPRICE);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(extension, LECEXTENSION);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(dueDate, LECDUE);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	nameOfTeacher = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	textBook = buf;

	return true;
}

ostream & operator << (ostream & os, Lecture & s) {
	string id(s.id, LECID);
	string level(s.level, LECLEVEL);
	string price(s.price, LECPRICE);
	string extension(s.extension, LECEXTENSION);
	string dueDate(s.dueDate, LECDUE);
	


	os << "ID: " << id << endl;
	os << "SUBJECT: " << s.subject << endl;
	os << "level: " << level << endl;
	os << "price: " << price << endl;
	os << "Extension: " << extension << endl;
	os << "Due Date: " << dueDate << endl;
	os << "NameOfTeacher: " << s.nameOfTeacher << endl;
	os << "textbook: " << s.textBook << endl;

	return os;
}