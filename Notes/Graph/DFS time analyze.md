* Use [[Adjacency Matrix]]
  $O(n^2)$ as it goes through every index in the matrix
* Use [[Adjacency Lists]]
  $O(V+e)$ as 
  init $\rightarrow O(V)$ as goes through every node
  begin and visit $O(V+e)$
  it'll go through every [[Connected Component]] 
  if white and the go to grey goes throgh every node (also the to black) $\therefore O(V)$ 
  and the for every adj\[e\] will go thhrough every edge so $O(e)$ thus $O(V+e)$ 