solve for negative weights
### Algorithm Concept
[[Dijkstra’s algorithm]] [[Ralax]] adjacent nodes
Bellman-Ford [[Ralax]] ==all edges== every time
* at most check $V-1$ times, since longest path in G is $V-1$ edges
* return boolean value each cycle showing if having a [[negative cycle]](負環) 
* return 無解 and stop if $\exists$ 負環

### pseudo-code
`Init_SS` see [[Dijkstra’s algorithm]]
```python
def Bellman_Ford(G, w, s):
	Init_SS(G, s)
	# relax all edge cycle
	for i in range(1, len(G.V)):
		# every node insert, check all edge one time
		for edge in G.E: # edge(u, v)
			Relax(u, v, w)
	# check for negative cycle
	for edge in G.E:
		# since cycle complete, should v.d=u.d+w(u,v)
		# u.d + w(u, v) shrink means negative cycle exist
		if v.d > u.d + w(u, v)
			return false # exist negative cycle
	return true
```