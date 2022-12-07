#include <iostream>
#include <ctime>
#include <cstdlib>
#define RANDOM_RANGE_coef 10
#define RANDOM_RANGE_exp 1000
#define TERM_LIMIT 5
#define NEGATIVE_coef true
#define NEGATIVE_exp true
#define DENSE_MULTIPLY false
#define DENSE_INPUT false
using namespace std;

int random(int n, bool neg, bool zero) {
    int ran = 0;

    ran = rand() % n;
    if (!zero)
        ran++;
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
        // ~polynomial() {
        //     term* tmp = head;
        //     while (head->next) {
        //         tmp = head->next;
        //         delete head;
        //         head = tmp;
        //     }
        //     delete head;
        // }
        term* get_head() {
            return head;
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

        term* insert_dense(int c, int e, term* last) {
            if (!head) {
                head = new term(c, e);
                return head;
            } else {
                last->next = new term(c, e);
                return last->next;
            }
        }

        term* add_dense(polynomial an_x_b, term* start) {
            term* add_cur = an_x_b.get_head();
            term* c_cur = start;

            if (!head) {
                while (add_cur) {
                    c_cur = insert_dense(add_cur->coef, add_cur->exp, c_cur);
                    add_cur = add_cur->next;
                }
                return head;
            }
            
            while (add_cur) {
                if (!c_cur->next) {
                    c_cur->next = new term(add_cur->coef, add_cur->exp);
                    break;
                }
                c_cur = c_cur->next;
                c_cur->coef += add_cur->coef;
                add_cur = add_cur->next;
            }

            return start->next;
        }

        void multiply(polynomial a, polynomial b, bool dense) {
            term* cur_a = a.head;
            term* cur_b = b.head;
            term* tmp;

            while (cur_a) {
                cur_b = b.head;

                polynomial* add = new polynomial();
                term* last = NULL;
                while (cur_b) {
                    if (dense)
                        last = add->insert_dense(cur_a->coef * cur_b->coef, cur_a->exp + cur_b->exp, last);
                    else
                        insert(cur_a->coef * cur_b->coef, cur_a->exp + cur_b->exp);
                    cur_b = cur_b->next;
                }
                if (dense) 
                    tmp = add_dense(*add, tmp);
                delete add;
                
                cur_a = cur_a->next;
            }
        }

        void print() {
            term* cur = head;
            //if empty poly
            if (!head) {
                cout << "0 or NULL, the polynomial is empty" << endl;
                return;
            }
            //if poly = 0;
            if (head->coef == 0 && head->next == NULL) {
                cout << '0' << endl;
                return;
            }
            //print head
            if (head->coef != 1 || head->exp == 0)
                cout << head->coef;
            if (head->exp != 0 && head->coef != 0) { //if constant
                cout << 'x';
                if (head->exp != 1) //if only ax^1
                    cout << '^' << cur->exp;
            }
            cout << ' ';
            //if only 1 term
            if (head->next == NULL) {
                cout << endl;
                return;
            }
            //print rest term
            while (cur->next) {
                cur = cur->next;
                //if term = 0
                if (cur->coef == 0)
                    continue;
                //determine coef is + or -
                if (cur->coef > 0)
                    cout << "+ ";
                else
                    cout << "- ";
                //if |coef| = 1, only print x
                if (abs(cur->coef) != 1 || cur->exp == 0)
                    cout << abs(cur->coef);
                //if exp >= 1 => print x
                if (cur->exp != 0)
                    cout << 'x';
                //if exp > 1 => print exp
                if (cur->exp != 1 && cur->exp != 0)
                    cout << '^' << cur->exp;
                
                cout << ' ';
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
        if (DENSE_INPUT) {
            exp = random(RANDOM_RANGE_exp, NEGATIVE_exp, true);
            for (int i = 0; i < term_a; i++) {
                coef = random(RANDOM_RANGE_coef, NEGATIVE_coef, false);
                a.insert(coef, exp + i);
                cout << "coef exp " << i << " : " << coef << ' ' << exp+i << endl;        
            }
        } else {            
            for (int i = 0; i < term_a; i++) {
                coef = random(RANDOM_RANGE_coef, NEGATIVE_coef, true);
                exp = random(RANDOM_RANGE_exp, NEGATIVE_exp, true);
                a.insert(coef, exp);
                cout << "coef exp " << i << " : " << coef << ' ' << exp << endl;        
            }
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
        if (DENSE_INPUT) {
            exp = random(RANDOM_RANGE_exp, NEGATIVE_exp, true);
            for (int i = 0; i < term_b; i++) {
                coef = random(RANDOM_RANGE_coef, NEGATIVE_coef, false);
                b.insert(coef, exp + i);
                cout << "coef exp " << i << " : " << coef << ' ' << exp+i << endl;        
            }
        } else {            
            for (int i = 0; i < term_b; i++) {
                coef = random(RANDOM_RANGE_coef, NEGATIVE_coef, true);
                exp = random(RANDOM_RANGE_exp, NEGATIVE_exp, true);
                b.insert(coef, exp);
                cout << "coef exp " << i << " : " << coef << ' ' << exp << endl;
            }
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
    c.multiply(a, b, DENSE_MULTIPLY);
    end_t = clock();
    total_t = (float)(difftime(end_t, start_t) / CLOCKS_PER_SEC);

    cout << "polynomial c :" << endl;
    c.print();

    cout << "start time: " << start_t << endl;
    cout << "end time: " << end_t << endl;
    cout << fixed << "total time: " << total_t << " sec\n" << endl;

    return 0;
}