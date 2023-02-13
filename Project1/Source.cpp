#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool LoginVerify(string input) {
	string line;
	ifstream file("Users.txt");
	while (!file.eof()) {// for each word read from the file 
		getline(file,line);
		size_t found = line.find(input);
		if (found != string::npos){
			cout <<"Congrats you have loged in" << endl;
		}
		else{
		cout << "Error! You have falied to log in\n";
		return 1;
		}
		file.close();
	}
}


int main() {
	int n;
	ofstream file ("Users.txt");

	if (!file) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	string name;
	string password;
	cout << "Hello if you want to register press 1 and if you would like to log in press 2" << endl;
	cin >> n;

	while (n != 1 && n != 2) {
		cout << "Ooops you didn't type what i asked you. Let's try again" << endl;
		cout << "Hello if you want to register press 1 and if you would like to log in press 2" << endl;
		cin >> n;
	}

	if (n == 1) {
		cout << "Type your Username to register" << endl;
		cin >> name;
		cout << "Type your Password to register" << endl;
		cin >> password;
		file << name << endl;
		file << password << endl;
	}

	file.close();

	if (!file) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	if (n == 2) {
		cout << "Type your Username" << endl;
		cin >> name;
		cout << "Type your Password" << endl;
		cin >> password;

	}

	return 0;
}