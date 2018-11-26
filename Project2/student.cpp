#include "student.h"
#include <sstream>
#include <string>

Student::Student() {

}

Student::Student(const char * new_id) {
	memcpy(id, new_id, 8);
}

Student::Student(const Student & s) {
	update_id(s.id);
	update_name(s.name);
	update_number(s.number);
	update_birthday(s.birthday);
}
//이 함수는 생성자임
Student & Student::operator = (const Student & s) {
	update_id(s.id);
	update_name(s.name);
	update_number(s.number);
	update_birthday(s.birthday);
	return *this;
}//위 함수와 차이가 무엇인가?
//이 함수는 복사하는 거임. 복사하는 객체, 복사받는 객체 두 객체가 이미 생성되었다고 전제함.
bool Student::operator == (const Student & s) {
	return !memcmp(id, s.id, 8);
}

bool Student::operator != (const Student & s) {
	return !(0== memcmp(id,s.id,8));
}

istream & operator >> (istream & is, Student & s) {
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
	getline(iss, token ,'|');
	s.update_id(token.data());
	getline(iss, token, '|');
	s.update_name(token);
	getline(iss, token, '|');
	s.update_number(token.data());
	getline(iss, token, '|');
	s.update_birthday(token.data());

	return is;
}

bool Student::Pack(IOBuffer & Buffer) const {
	int numBytes;
	Buffer.Clear();
	string s_id(id, LENID);
	string s_number(number, LENUM);
	string s_birthday(birthday, LENBIR);

	numBytes = Buffer.Pack(s_id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(name.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_number.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_birthday.c_str());
	if (numBytes == -1) return false;

	return true;
}

bool Student::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[STDMAXBUF];

	numBytes = Buffer.Unpack(id, LENID);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	name = buf;
	numBytes = Buffer.Unpack(number, LENUM);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(birthday, LENBIR);
	if (numBytes == -1) return false;

	return true;
}

ostream & operator << (ostream & os, Student & s) {
	string id(s.id, LENID);
	string number(s.number, LENUM);
	string birthday(s.birthday, LENBIR);

	os << "ID: " << id << endl;
	os << "Name: " << s.name << endl;
	os << "NUMBER: " << number << endl;
	os << "BIRTHDAY: " << birthday << endl;

	return os;
}