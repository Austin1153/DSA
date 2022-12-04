#include <iostream>
#include <ctime>
#include <cstdlib>
#define RANDOM_RANGE_coef 10
#define RANDOM_RANGE_exp 5
using namespace std;

int random(int n, bool neg) {
    int ran = 0;

    ran = rand() % n;
    if (neg) {
        if (!(rand() % 5))
            ran = -ran;
    }

    return ran;
}

class term {
    friend class polynomial;
    private:
        int coef;
        int exp;
        term* next;
    public:
        term(int c, int e) {
            coef = c;
            exp = e;
            next = NULL;
        }
};

class polynomial {
    private:
        term* head;
    public:
        polynomial() {
            head = NULL;
        }

        void insert(int c, int e) {
            term* cur = head;
            term* tmp;
            bool flag = 1;  //determine if inserted for exit while()

            if (c == 0)  //c = 0, empty term
                return;

            if (!head)  //if initial insert
                head = new term(c, e);
            else if (head->exp < e) {  //if insert in front
                head = new term(c, e); //of head (head.e < insert.e)
                head->next = cur;
            } else {
                while (flag) {
                    if (cur->exp == e) {  //if exp same, add coef
                        cur->coef += c;
                        flag = 0;
                    } else if (cur->exp < e) { //if exp < e, means
                        tmp->next = new term(c, e); //inserted in
                        tmp->next->next = cur; //front of cur
                        flag = 0;
                    } else if (!cur->next) { //end of poly, insert
                        cur->next = new term(c, e); //at last term
                        flag = 0;
                    } else {  //still exp > e, goes to next term
                        tmp = cur;
                        cur = cur->next;
                    }
                }
            }
        }

        void multiply(polynomial a, polynomial b) {
            term* cur_a = a.head;
            term* cur_b = b.head;

            while (cur_a) {
                cur_b = b.head;
                while (cur_b) {
                    insert(cur_a->coef * cur_b->coef, cur_a->exp + cur_b->exp);
                    cur_b = cur_b->next;
                }
                cur_a = cur_a->next;
            }
        }

        void print() {
            term* cur = head;
            //if empty poly
            if (!head) {
                cout << "NULL, the polynomial is empty";
                return;
            }
            //if poly = 0;
            if (head->coef == 0 && head->next == NULL) {
                cout << '0' << endl;
                return;
            }
            //if only constant
            if (head->exp == 0 && head->next == NULL) {
                cout << head->coef << endl; 
                return;
            }
             //if only coef * x
            if (head->exp == 1 && head->next == NULL) {
                cout << head->coef << 'x' << endl;
                return;
            }
            //print head
            cout << cur->coef << "x^" << cur->exp << ' '; 
            //print rest term
            while (cur->next) {
                cur = cur->next;
                //if term = 0
                if (cur->coef == 0)
                    continue;
                //determine coef is + or -
                if (cur->coef > 0)
                    cout << "+ " << cur->coef;
                else
                    cout << "- " << abs(cur->coef);
                //if exp >= 1 => print x
                if (cur->exp >= 1)
                    cout << 'x';
                //if exp > 1 => print exp
                if (cur->exp > 1)
                    cout << '^' << cur->exp;
                
                cout << ' ';
            }
            cout << endl;
        }

};

int main() { 
    int term_a, term_b, coef, exp;
    polynomial a, b, c;

    cout << "enter term a : ";
    cin >> term_a;
    if (term_a > 10) {
        for (int i = 0; i < term_a; i++) {
            coef = random(RANDOM_RANGE_coef, true);
            exp = random(RANDOM_RANGE_exp, false);
            a.insert(coef, exp);
            cout << "coef exp " << i << " : " << coef << ' ' << exp << endl;
        }
    } else {
        for (int i = 0; i < term_a; i++) {
            cout << "enter coef exp " << i << " : ";
            cin >> coef >> exp;
            a.insert(coef, exp);
        }
    }

    cout << "enter term b : ";
    cin >> term_b;
    if (term_b > 10) {
        for (int i = 0; i < term_b; i++) {
            coef = random(RANDOM_RANGE_coef, true);
            exp = random(RANDOM_RANGE_exp, false);
            b.insert(coef, exp);
            cout << "coef exp " << i << " : " << coef << ' ' << exp << endl;
        }
    } else {
        for (int i = 0; i < term_b; i++) {
            cout << "enter coef exp " << i << " : ";
            cin >> coef >> exp;
            b.insert(coef, exp);
        }
    }

    cout << "polynomial a :" << endl;
    a.print();

    cout << "polynomial b :" << endl;
    b.print();

    c.multiply(a, b);
    cout << "polynomial c :" << endl;
    c.print();

    return 0;
}