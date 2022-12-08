#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

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
            //c = 0, empty term
            if (c == 0)  
                return;
            //if initial insert or insert at front
            if (!head || head->exp < e) {
                head = new term(c, e);
                head->next = cur;
                return;
            }   
            while (cur) {
                tmp = cur;
                cur = cur->next;
                //if last
                if (tmp->exp == e) {  
                    tmp->coef += c;
                    break;
                //if exp same, add coef
                } else if (!cur) {
                    tmp->next = new term(c, e);
                    break;
                //if in middle but exp node not created
                } else if (tmp->exp > e && cur->exp < e) { 
                    tmp->next = new term(c, e);
                    tmp->next->next = cur;
                    break;
                }
            }
        }

        void multiply(polynomial a, polynomial b) {
            term* polya = a.head;
            term* polyb = b.head;
            term* start = head, *cur;
            int c, e;

            while (polya) {
                polyb = b.head;
                cur = start;
                while (polyb) {
                    c = polya->coef * polyb->coef;
                    e = polya->exp + polyb->exp;

                    if (!head) {
                       head = new term(c, e);
                       polyb = polyb->next;
                       start = head;
                       cur = start;
                       continue;
                    }

                    if (!cur->next) {
                        cur->next = new term(c, e);
                        cur = cur->next;
                    } else {
                        cur = cur->next;
                        cur->coef += c;
                    }

                    polyb = polyb->next;
                }
                if (polya != a.head) 
                    start = start->next;
                
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
                cur = cur->next;
                cout << "+ " << cur->coef << "x^" << cur->exp << ' ';
            }
            cout << endl;
        }
};

void dense_rand(polynomial* poly, int term) {
    int coef;
    for (int i = term; i > 0; i--) {
            coef = rand() % 100 + 1;
            poly->insert(coef, i);
            cout << "coef exp " << i << " : " << coef << ' ' << i << endl;
        }
}

int main() { 
    int term_a, term_b, coef, exp;
    polynomial a, b, c;
    clock_t start_t, end_t;
    float total_t;
    srand(time(NULL));

    cout << "enter term a : ";
    cin >> term_a;
    if (term_a > 100) {
        dense_rand(&a, term_a);
    } else {
        for (int i = 0; i < term_a; i++) {
            cout << "enter coefficient & exp " << i << " : ";
            cin >> coef >> exp;
            a.insert(coef, exp);
        }
    }

    cout << "enter term b : ";
    cin >> term_b;
    if (term_b > 100) {
        dense_rand(&b, term_b);
    } else {
        for (int i = 0; i < term_b; i++) {
            cout << "enter coefficient & exp " << i << " : ";
            cin >> coef >> exp;
            b.insert(coef, exp);
        }
    }

    cout << "poly a :" << endl;
    a.print();

    cout << "poly b :" << endl;
    b.print();

    start_t = clock();
    c.multiply(a, b);
    end_t = clock();
    total_t = (float)(difftime(end_t, start_t) / CLOCKS_PER_SEC);

    cout << "a * b :" << endl;
    c.print();

    cout << "start time: " << start_t << endl;
    cout << "end time: " << end_t << endl;
    cout << fixed << "total time: " << total_t << " sec\n" << endl;

    return 0;
}