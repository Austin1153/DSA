## Problem Define
***
## Top-Down Solution
```c++
int TD_CutRodAux(int n, int* p, int* r) {
	// if subproblem resolved, return resolved result
	if (r[n] >= 0) return r[n];
	// calculate subproblem
	int q;
	// r[0] = 0
	if (n == 0 ) q = 0;
	else {
		q = -1;
		for (int i = 1; i <= n; i++) 
			q = max(q, p[i]+TD_CutRodAux(n-i, p, r));
		r[n] = q
	}
	return q;
}

int TD_CutRod(int n, int *p) {
	// arr r for memorize subproblem result
	int *r = new int [n+1];
	for (int i = 0; i <= n; i++)
		r[i] = -1;
	return TD_CutRodAux(n, p, r);
}
```
time complexiety $O(n^2)$, $\sum^{n}_{i=1} i$ 
## Bottom-up Solution
```c++
int BU_CutRod(int n, int *p) {
	int *r = new int [n+1];
	r[0] = 0;
	// solve subproblemfrom 1 to n
	for (int i = 1; i <= n; i++) {
		int q = -1;
		for (j = 1; j <= i; j++) {
			q = max(q, p[j]+r[i-j]);
		}
		r[i] = q;
	}
	return r[n];
}
```
***
## To get Solution Choice 
```c++
void Extend_BU_CutRod(int n, int *p, int *r, int *s) {
	r = new int [n+1]; // value for rod lentgh i
	s = new int [n+1]; // best choice for rod length i
	r[0] = 0;

	for (int i = 1; i <= n; i++) {
		int q = -1;
		for (int j = 1; j <= i; j++) {
			if (q < p[j] + r[i-j]) {
				q = p[j] + r[i-j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
	// r and s is your return/ans;
}
```
```c++
void print_CutRod(int n, int *p, int *r, int *s) {
	Extend_BU_CutRod(n, p, r, s);
	while (n > 0) {
		cout << s[n] << ' ';
		n = n - s[n];
	}
}
```
