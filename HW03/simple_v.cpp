#include <iostream>
#include <ctime>
#include <cstdlib>
#define RANDOM_RANGE_coef 100
#define RANDOM_RANGE_exp 1000
#define TERM_LIMIT 100
#define NEGATIVE_coef true
#define NEGATIVE_exp true
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
            term* polya = a.head;
            term* polyb = b.head;
            int c, e;

            while (polya) {
                polyb = b.head;
                while (polyb) {
                    c = polya->coef * polyb->coef;
                    e = polya->exp + polyb->exp;
                    insert(c, e);
                    polyb = polyb->next;
                }
                polya = polya->next;
            }
        }

        void print() {
            term* cur = head;
            //if empty poly
            if (!head) {
                cout << "NULL" << endl;
                return;
            }
            //if poly = 0;
            if (head->coef == 0 && head->next == NULL) {
                cout << '0' << endl;
                return;
            }
            //print head
            cout << head->coef << "x^" << head->exp << ' ';
            //print rest term
            while (cur->next) {
                cout << "+ " << head->coef << "x^" << head->exp << ' ';
            }
            cout << endl;
        }
};

int main() { 
    int term_a, term_b, coef, exp;
    polynomial a, b, c;
    clock_t start_t, end_t;
    float total_t;
    srand(time(NULL));

    cout << "enter term a : ";
    cin >> term_a;
    if (term_a > TERM_LIMIT) {
        for (int i = 0; i < term_a; i++) {
            coef = random(RANDOM_RANGE_coef, true);
            exp = random(RANDOM_RANGE_exp, true);
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
    if (term_b > TERM_LIMIT) {
        for (int i = 0; i < term_b; i++) {
            coef = random(RANDOM_RANGE_coef, NEGATIVE_coef);
            exp = random(RANDOM_RANGE_exp, NEGATIVE_exp);
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

    start_t = clock();
    c.multiply(a, b);
    end_t = clock();
    total_t = (float)(difftime(end_t, start_t) / CLOCKS_PER_SEC);

    cout << "polynomial c :" << endl;
    c.print();

    cout << "start time: " << start_t << endl;
    cout << "end time: " << end_t << endl;
    cout << fixed << "total time: " << total_t << " sec\n" << endl;

    return 0;
}