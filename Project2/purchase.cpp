#include "purchase.h"
#include <sstream>
#include <string>

Purchase::Purchase() {

}

Purchase::Purchase(const char * new_id) {
	memcpy(id, new_id, 16);
}

Purchase::Purchase(const Purchase & s) {
	update_id(s.id);
	update_lectureId(s.lectureId);
	update_memberId(s.memberId);
	update_mileage(s.mileage);
}
//이 함수는 생성자임
Purchase & Purchase::operator = (const Purchase & s) {
	update_id(s.id);
	update_lectureId(s.lectureId);
	update_memberId(s.memberId);
	update_mileage(s.mileage);
	return *this;
}
//위 함수와 차이가 무엇인가?
//이 함수는 복사하는 거임. 복사하는 객체, 복사받는 객체 두 객체가 이미 생성되었다고 전제함.
bool Purchase::operator == (const Purchase s) {
	return !memcmp(id, s.id, 16);
}

bool Purchase::operator != (const Purchase & s) {
	return !(0 == memcmp(id, s.id, 16));
}

istream & operator >> (istream & is, Purchase & s) {
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
	s.update_lectureId(token.data());
	getline(iss, token, '|');
	s.update_memberId(token.data());
	getline(iss, token, '|');
	s.update_mileage(token.data());

	return is;
}

bool Purchase::Pack(IOBuffer & Buffer) const {
	int numBytes;
	Buffer.Clear();
	string s_id(id, PURCHASEID);
	string s_lecId(lectureId, LECID);
	string s_mileage(mileage, MILEAGE);

	numBytes = Buffer.Pack(s_id.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_lecId.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(memberId.c_str());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack(s_mileage.c_str());
	if (numBytes == -1) return false;

	return true;
}

bool Purchase::Unpack(IOBuffer & Buffer) {
	int numBytes;
	char buf[STDMAXBUF];

	numBytes = Buffer.Unpack(id, PURCHASEID);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(lectureId, LECID);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack(buf);
	if (numBytes == -1) return false;
	memberId = buf;
	numBytes = Buffer.Unpack(mileage, MILEAGE);
	if (numBytes == -1) return false;
	

	return true;
}

ostream & operator << (ostream & os, Purchase & s) {
	string id(s.id, PURCHASEID);
	string lectureId(s.lectureId , LECID);
	string mileage(s.mileage, MILEAGE);

	os << "ID: " << id << endl;
	os << "LECTURE ID: " << lectureId<< endl;
	os << "MEMBER ID: " << s.memberId << endl;
	os << "MILEAGE: " << mileage << endl;

	return os;
}