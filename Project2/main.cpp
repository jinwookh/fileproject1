#include "student.h"
#include "member.h"
#include "purchase.h"
#include "recfile.h"
#include <fstream>
#include <vector>
#include "lecture.h"

using namespace std;

void showMember();
void showLecture();
void showPurchase();
void memberTest();
void lectureTest();
void purchaseTest();
void lecturePurchaseSystem();


int main() {
	int choice;
	int loops = 1;

	while (loops) {
		cout << "\n*****************Please tell me the program you want!***************\n";
		cout << "1.showmember program\n";
		cout << "2.showlecture program\n";
		cout << "3.showpurchase program\n";
		cout << "4.membertest program\n";
		cout << "5.lecturetest program\n";
		cout << "6.purchasetest program\n";
		cout << "7.LecturePurchaseSystem program\n";
		cout << "8.Exit\n";
		//shows the menu


		cin >> choice;
		//stores user choice into choice variable

		switch (choice) {
		case 1:
			showMember();
			break;
		case 2:
			showLecture();
			break;
		case 3:
			showPurchase();
			break;
		case 4:
			memberTest();
			break;
		case 5:
			lectureTest();
			break;
		case 6:
			purchaseTest();
			break;
		case 7:
			lecturePurchaseSystem();
			break;
		case 8:
			loops = 0;
		}
	}
	
	return 0;
	
	/*
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	// 파일에서 \n 기준으로 한 줄씩 읽음

	vector <Purchase> s_list;

	for (int i = 0; i < 10; i++) {
		Purchase s;
		ifs >> s;
		cout << s;
		s_list.push_back(s); // pushes element at back of the array
	}
	
	Member s1 = s_list[0];
	Member s2 = s_list[1];

	if (s1 == s1) cout << "'==' works well!" << endl;
	if (s1 != s2) cout << "!= works pretty well!" << endl;

	Member s3;
	s3 = s1;

	cout << s3;
	cout << "'=' works pretty well!" << endl;
	
	ifs.close();
	return 0;
	*/
	
}

void purchaseTest() {
	ifstream ifs("listOfPurchase.txt");
	int r;
	int n;
	Purchase s1;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Purchase> PurchaseFile(buffer);
	

	PurchaseFile.Create("fileOfPurchase.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Purchase s;
		ifs >> s;
		int recaddr;
		if ((recaddr = PurchaseFile.Write(s)) == -1);
		//cout << "Write Error!" << endl;
	//else
		//cout << "Write at" << recaddr << endl;
	}
	PurchaseFile.Close();

	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Purchase s;
		r = PurchaseFile.Read(s);
		if (i == 9) {
			r = PurchaseFile.Read(s1);
		}
		//r에 위치를 저장한 후 후에 r을 이용해 dwrite한다.
		
		cout << s;
	}
	PurchaseFile.Close();
	cout << "----------------";
	PurchaseFile.Open("fileOfPurchase.dat", ios::out);
	PurchaseFile.Write(s1, r, 1);
	PurchaseFile.Close();

	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	for (int i = 0; i < 20; i++) {
		cout << i << "번째\n";
		Purchase s;
		r = PurchaseFile.Read(s);
		
		//r에 위치를 저장한 후 후에 r을 이용해 dwrite한다.

		cout << s;
	}
	PurchaseFile.Close();

	ifs.close();
	return;
}

void lectureTest() {
	ifstream ifs("listOfLecture.txt");

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Lecture> LectureFile(buffer);

	LectureFile.Create("fileOfLecture.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Lecture s;
		ifs >> s;
		int recaddr;
		if ((recaddr = LectureFile.Write(s)) == -1);
		//cout << "Write Error!" << endl;
	//else
		//cout << "Write at" << recaddr << endl;
	}
	LectureFile.Close();

	LectureFile.Open("fileOfLecture.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Lecture s;
		LectureFile.Read(s);
		//여기서 READ를 하면 UNPACK함수가 호출된다
		cout << s;
	}
	LectureFile.Close();
	ifs.close();
	return;
}

void memberTest() {
	ifstream ifs("listOfMember.txt");

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Member> MemberFile(buffer);

	MemberFile.Create("fileOfMember.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Member s;
		ifs >> s;
		int recaddr;
		if ((recaddr = MemberFile.Write(s)) == -1);
		//cout << "Write Error!" << endl;
	//else
		//cout << "Write at" << recaddr << endl;
	}
	MemberFile.Close();
	
	MemberFile.Open("fileOfMember.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Member s;
		MemberFile.Read(s);
		//여기서 READ를 하면 UNPACK함수가 호출된다
		cout << s;
	}
	MemberFile.Close();
	ifs.close();
	
	return;

}

void showMember() {
	ifstream ifs("listOfMember.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return ;
	}

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	// 파일에서 \n 기준으로 한 줄씩 읽음

	vector <Member> s_list;

	for (int i = 0; i < 10; i++) {
		Member s;
		ifs >> s;
		cout << s;
		s_list.push_back(s); // pushes element at back of the array
	}

	ifs.close();
	return;
}

void showLecture() {
	ifstream ifs("listOfLecture.txt");
	

	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return ;
	}

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	// 파일에서 \n 기준으로 한 줄씩 읽음

	vector <Lecture> s_list;

	for (int i = 0; i < 10; i++) {
		Lecture s;
		ifs >> s;
		cout << s;
		s_list.push_back(s); // pushes element at back of the array
	}
	
	ifs.close();
	return;
}

void showPurchase() {
	ifstream ifs("listOfPurchase.txt");

	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return;
	}

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');
	// 파일에서 \n 기준으로 한 줄씩 읽음

	vector <Purchase> s_list;

	for (int i = 0; i < 10; i++) {
		Purchase s;
		ifs >> s;
		cout << s;
		s_list.push_back(s); // pushes element at back of the array
	}
	
	ifs.close();
	return;
}

void lecturePurchaseSystem() {
	cout << "\nsorry\n";

}