* Unstable Sort
## Time Complexiety
* The time required to position a record in a list of size n is $O(n)$
  要把n個資料排到正確位置需要$O(n)$
#### Worst Case
* $O(n^2)$
  The list of records is decreasing, ex: 10, 9 , 8 , 7, 6, sort increasing
  Always pick up the incorrect pivot (the first largest element)
   * {9, 8, 7, 6}, 10, { } -> 4 comparison
   * {8, 7, 6}, 9, { } ->3 comparisons
   * {7, 6}, 8, { } ->2 comparsions
   * {6}, 7, { } ->1 comparsions
   
  Total number of comparison: 4+3+2+1=10
  so when n elements: $n + (n-1)+...+1=\frac{n(n-1)}{2}=O(n^2)$
 
  

#### Best Case
If we are lucky, pick the pivot correctly each time, the size of sublist left equals to the right.
Which leave us sorting 2 sublists, each of size roughly $n/2$
T(n) is the time sorting n records, sorting a record requires times of c 
$$
\begin{align}
T(n) & \leq cn + 2T(\frac{n}{2}) \\
& \leq cn + 2(\frac{cn}{2} + 2T(\frac{n}{4})) \\
& \leq 2cn + 4T(\frac{n}{4}) \\
& \leq 2cn + 4(\frac{cn}{4} + 2T(\frac{n}{8})) \\
& \vdots \\
& \leq \log_2 n\cdot cn + nT(1) = O(n\log n)
\end{align}
$$
$\therefore n$ 要一直切，直到不能切$\rightarrow 1$ 
$n\cdot (\frac{1}{2})^x \geq 1 \Rightarrow x = \log_2 n \therefore O(n\log n)$ 

## Space Complexiety
* 看==遞迴深度==(stack space)
#### Best Case
If the **lists split evenly**, 
* the **maximum recursion depth** would be $\log n$ 
* the stack space is of $O(\log n)$.
#### Worse Case
The worst case is when the lists split into only a left sublist of size n–1, such as decreasing when sort increasing 
* the recursion depth is $n$,
* the stack space of $O(n)$.