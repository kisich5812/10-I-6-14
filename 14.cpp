#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> strtonum(string a) {
        vector<int> num;
        stringstream ss(a);
        int n;
        while (ss >> n) {
                num.push_back(n);
        }
        return num;
}

int main() {
    	ifstream in("kvadrat.txt");
    	if (!in.is_open()) {
        	cout << "Ошибка при открытии файла" << endl;
        	return 1;
    	}
    	string fl;
    	getline(in, fl);
    	vector<int> num = strtonum(fl);
    	in.close();
    	int n = num[num.size()-1];
    	ofstream out("kvadrat.txt", ios::app);
    	if (!out.is_open()) {
        	cout << "Ошибка при открытии файла для записи" << endl;
        	return 1;
    	}
    	for (int i = 2; i <= n; ++i) {
        	for (int j = 1; j <= n; ++j) {
            		out << n*(i - 1) + j << " ";
        	}
        	out << endl;
    	}
    	out.close();
	return 0;
}
