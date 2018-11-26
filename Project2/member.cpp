#include "member.h"
#include <sstream>
#include <string>

Member::Member() {

}

Member::Member(const string new_id) {
	id = new_id;
}

Member::Member(const Member & s) {
	update_id(s.id);
	update_password(s.password);
	update_name(s.name);
	update_phoneNumber(s.phoneNumber);
	update_address(s.address);
	update_mileage(s.mileage);
}
//이 함수는 생성자임
Member & Member::operator = (const Member & s) {
	update_id(s.id);
	update_password(s.password);
	update_name(s.name);
	update_phoneNumber(s.phoneNumber);
	update_address(s.address);
	update_mileage(s.mileage);
	return *this;
}//위 함수와 차이가 무엇인가?
//이 함수는 복사하는 거임. 복사하는 객체, 복사받는 객체 두 객체가 이미 생성되었다고 전제함.
bool Member::operator == (const Member & s) {
	return !s.id.compare(id);
}

bool Member::operator != (const Member & s) {
	return !(0 == s.id.compare(id));
	// s.id와 같다면 0 -> false 도출
}

istream & operator >> (istream & is, Member & s) {
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
	s.update_id(token);
	getline(iss, token, '|');
	s.update_password(token);
	getline(iss, token, '|');
	s.update_name(token);
	getline(iss, token, '|');
	s.update_phoneNumber(token);
	getline(iss, token, '|');
	s.update_address(token);
	getline(iss, token, '|');
	s.update_mileage(token.data());

	return is;
}

bool Member::Pack(IOBuffer & Buffer) const {
	int numBytes;
	Buffer.Clear();
	string s_id(id, MEMBERID);
	string s_password(password, MEMBERPASS);
	string s_phoneNumber(phoneNumber, MEMBERPHONE);
	string s_mileage(mileage, MEMBERMILEAGE);

	numBytes = Buffer.Pack(id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(password.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(name.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(phoneNumber.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(address.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_mileage.c_str());
	if (numBytes == -1) return false;

	return true;
}

bool Member::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[STDMAXBUF];

	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	id = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	password = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	name = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	phoneNumber = buf;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	address = buf;
	numBytes = Buffer.Unpack(mileage, MEMBERMILEAGE);
	if (numBytes == -1) return false;

	return true;
}

ostream & operator << (ostream & os, Member & s) {
	string id(s.id, MEMBERID);
	string password(s.password, MEMBERPASS);
	string phoneNumber(s.phoneNumber, MEMBERPHONE);
	string mileage(s.mileage, MEMBERMILEAGE);

	os << "ID: " << s.id << endl; 
	os << "PASS: " << s.password << endl;
	os << "Name: " << s.name << endl;
	os << "PHONE NUMBER: " << s.phoneNumber << endl;
	os << "Address: " << s.address << endl;
	os << "MILEAGE: " << mileage << endl;

	return os;
}