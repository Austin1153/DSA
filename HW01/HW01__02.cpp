#include <iostream>
#include <string>

using namespace std;

int main() {
    int x, y, maxlen_name = 0, maxlen_before_space = 0;
    string name;
    cout << "enter how many names & length of the longest name :" << endl;
    cin >> x >> y; //x:quantity, y:str length
    char **arr = new char* [x](); 
                    //double ptr point to arr of ptr, which point to strings;
    cin.ignore();  //ignore the '\n' from last cin
    for (int i = 0; i < x; i++) {
        arr[i] = new char [y]();  //assign char to ptr
        cout << "enter string" << i+1 << ':' << endl; 
        getline(cin, name);
        while (name.length() > y) {  //check if input is too long
            cout << "input string too long, please reenter" << endl;
            getline(cin, name);
        }
        if (name.length() > maxlen_name) //find len of longest str
            maxlen_name = name.length();
        if (name.find_first_of(' ') > maxlen_before_space) //find longest len before space
            maxlen_before_space = name.find_first_of(' ');
        for (int j = 0; j < y; j++)  //assign name to arr
            arr[i][j] = name[j];
    }

    for(int i = 0; i < x; i++) { //create new arr with longest str len
        name = arr[i];
        delete[] arr[i];
        arr[i] = new char [maxlen_name]();
        for (int j = 0; j < y; j++)  //assign name to arr
            arr[i][j] = name[j];
    }
    cout << "------ output ------" << endl;
    for (int i = 0; i < x; i++) {  //output data
        name = arr[i];
        for (int j = 0; j < (maxlen_before_space-name.find_first_of(' ')); j++)
            cout << ' ';
        cout << name << endl;
    }
    for (int i = 0; i < x; i++)  //free
        delete[] *(arr+i);
    delete[] arr;

    return 0;
}