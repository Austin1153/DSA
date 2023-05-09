Minimum Spanning Tree
### Spanning Tree
A tree, acyclic, and connects to all vertax
* Tree $\rightarrow$ no cycle
* tree $\rightarrow$ have exact $n-1$ edges

## MST
A spanning w/ minimum total weight
* Isn't unique

### Methods
* Generic_MST
* Kruskal’s algorithm - use [[Greedy algorithm]]
* Prim’s algorithm - use Greedy algorithm
* Sollin’s algorithm

### Generic MST
```python
def Generic_MST(G, w) :
	A = graph.Graph()
	while !A.IsSpanningTree() : # A.edges < V-1
		# Find an edge (u, v) that is safe for A
		edge = A.FindSafeEdge(G, w)
		A.addEdge(edge)
	return A
```