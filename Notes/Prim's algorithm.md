Requires a starting point
## Algorithm Concept 
From a starting Point, always choose the edge with **minimum** cost until all vertax have been selected.
1. Starting Point as a Tree and $Q$ to list all vertax except starting point
2. Choose the edge which connect the vertax $v$ in $Q$ to the Tree with **minimum** cost.
4. Remove $v$ from the $Q$
5. Repeat until $Q$ is empty
## psuedo-code
```python
def Prim(G, w, s): # s is the starting point
	# init
	for u in G.V:
		u.key = -1 # infinfty
		u.pi = NULL
	s.key = 0
	Q = G.V
	# begin Prim
	while !Q.empty():
		u = Extract_min(Q)
		for v in G.Adj(u):
			if (v in Q) and w(u, v) < v.key:
				v.pi = u
				v.key = w(u, v)
```
