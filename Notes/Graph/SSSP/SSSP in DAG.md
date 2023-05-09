DAG: directed acyclic graph (有向無環圖)

Using [[Topological Sort]], we can compute SSSP in a weighted DAG in $O(V+E)$, whereas [[Bellman-Ford Time Analysis]] is $O(|V||E|)$
* DAG has no cycle $\rightarrow$ no negative-cycle, even $\exists$ negative weight

### pseudo-code
```python
def DAG_Shortest_Path(G,w,s):
	# same as DFS -> O(V+E)
	topo_order = Topologically_sort(G.V)
	Init_SS(G,s) # O(|V|)
	# O(|E|)
	for u in topo_order: 
		for v in topo_order.adj(u)
			Relax(u,v,w)
```
total take $O(2(V+E)) = O(|V|+|E|)$
