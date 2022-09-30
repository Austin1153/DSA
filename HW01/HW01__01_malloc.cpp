#include <iostream>
#include <cstdlib>

using namespace std;

void bobblesort(char** ptr, int end, int curlop) {
    char* tmp;
    for (int i = 0; i < end-1; i++) {
        if (**(ptr + i) < **(ptr + i+1)) { //if arr[i+i] > arr[i]
            tmp = *(ptr + i+1);  //swap arr[i] & arr[i+1]
            *(ptr + i+1) = *(ptr + i);
            *(ptr + i) = tmp;
        }
    }
}

int main() {
    int x, y;
    cout << "enter quantity & length :" << endl;
    cin >> x >> y; //x:quantity, y:str length
    char **arr = (char**)malloc(x * sizeof(char*)); 
                    //double ptr point to arr of ptr, which point to strings;
    for (int i = 0; i < x; i++) {
        *(arr + i) = (char*)malloc(y * sizeof(char));
        cout << "enter string :" << endl; //(upper line) assign char to ptr
        cin >> *(arr + i);        
    } 

    for (int i = 0; i < x-1; i++) {  //bubble sort
        bobblesort(arr, x-i, i);     //give first loc of arr & len to sort
    }
    cout << '\n';
    for (int i = 0; i < x; i++) {  //output data
        cout << *(arr + i) << endl;
    }
    for (int i = 0; i < x; i++)  //free
        free(*(arr+i));
    free(arr);

    return 0;
}