To sort a list of n elements
* suppose $2^{k-1}\leq n\leq 2^k$
  so the tree has k levels
* the number of nodes on level i is $n_i \leq 2^{i-1}$
  last level $n_{last} \leq 2^{i-1}$, else $n_i = 2^{i-1}$
  
#### Build Heap
###### In the first for loop
`Adjust()` is called once for **each node that has children**.
* for node in level i
  Time requires: 此level中的node數目與max distance it can move $\rightarrow 2^{i-1}(k-i)$ 
In for loop, so Time:
$$ \begin{align}
& \sum_{i = 1}^k 2^{i-1}(k-i)  & \text{let } i' = k-i\\
= & \sum_{i' = 1}^{k-1} 2^{k-i'-1}(i') & \text{拆分} 2^{k-i'-1}=(2^{k-1}\cdot 2^{-i'}) \\
= & \sum_{i' = 1}^{k-1} (2^{k-1}\cdot 2^{-i'})(i') \\
\leq & n\sum_{i' = 1}^{k-1} \frac{i'}{2^{i'}} < 2n & \text{note: } \sum_{i = 0}^{\infty} \frac{i}{2^i} = 2\\
& \therefore \text{Time Complexiety: } O(n)
\end{align} $$
#### Sorting
###### 2<sup>nd</sup> for loop
* $n-1$ applications of `Adjust()` are made with max tree depth $k=\lceil \log_2 (n+1)\rceil$
* Swap is invoked $n-1$ times
$$\lceil \log_2 (n+1)\rceil \cdot (n-1) \rightarrow n\log n$$
$\therefore O(n\log n)$


## Space Complexiety
The only additional space needed is space for **one record** to carry up the ==swap== in the second for loop