can find topological order(拓撲順序)

## Topological-Sort(G)
1. Call DFS(G) to find $v.f$ for each vertex $v$
2. As each vertex is finished, insert it to the **front** of a linked list.
3. Return the linked list of vertices
#### Ex
![[Topological Sort Ex.png]]
result
![[Topological sort result.png]]
