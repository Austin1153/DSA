Note : u.d is distance w/ root, not discover time
```python
def BFS(G, s) :
	# init
	for u in G :
		u.color = white
		u.d = -1
		u.pi = NULL
	# begin BFS
	# init root s
	s.color = gray
	s.d = 0
	# init queue, FIFO, ins rear pop font
	Q = queue.Queue()
	Q.put(s) # or enqueue(Q, s)

	while !Q.empty() :
		u = Q.pop() # or u = dequeue(Q)
		for v in G.adj(u) :
			if v.color == white :
				v.color = gray
				v.d = u.d + 1
				v.pi = u
				Q.put(v)
		u.color = black
```