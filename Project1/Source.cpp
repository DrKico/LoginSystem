#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void LoginVerify() {
	string name;
	string password;
	cout << "Type a username and password to register" << endl;
	cin >> name >> password;
	string line;
	ifstream file("Users.txt");
	int counter=0;

	while (!file.eof()) {
		getline(file, line);
		if (line==name || line==password) {
			counter++;
		}
	}
	if (counter == 2) {
		cout << "You have loged in sucessfully"<<endl;
	}
	else {
		cout << "Login failed" << endl;
	}
	file.close();
}


int main() {
	int n;
	string name;
	string password;
	cout << "Hello if you want to register press 1 and if you would like to log in press 2" << endl;
	cin >> n;

	while (n != 1 && n != 2) {
		cout << "Ooops you didn't type what i asked you. Let's try again" << endl;
		cout << "Hello, if you want to register press 1 and if you would like to log in press 2" << endl;
		cin >> n;
	}

	if (n == 1) {
		ofstream file("Users.txt", ios::app);
		cout << "Type a username and password to register" << endl;
		cin >>name>>password;
		file << name<<endl;
		file << password << endl;
		cout << "You have sucessfully registered" << endl;
		file.close();
		LoginVerify();
	}
	
	if (n == 2) {
		LoginVerify();
	}
	
	return 0;
}