## Diagraph
### Strongly Connected
Diagraph G is Strongly Connected, iff 
* $\forall u, v \in V(G), \exists$ path from $u \rightarrow v$ and also $v \rightarrow u$
### Strongly [[Connected Component]]
maximal [[subgraph]] that is strongly connected
```mermaid
graph TD
subgraph H1
	A --> D --> A
end
subgraph H2
	B --> C --> F --> B
end
subgraph H3
	E
end
subgraph H4
	G --> H --> G
end
subgraph H5
	I
end
B --> E --> D
H --> E --> I
```
> Ex 在這個digraph有多少個Strongly [[Connected Component]]?![[Strong Connected diagraph.png]]
![[graphviz.svg]]
```mermaid
---
title : mermaid ver.
---
graph LR
A((1)) --> B((2)) --> D((4)) --> A
A --> C((3)) --> D
C --> E((5)) --> F
D --> F((6))
```
Ans : $3, H = \{1,2,3,4\},\{5\},\{6\}$