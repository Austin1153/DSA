==Weights are non-negative==
It maintains a set $S$ of vertices whose final shortest-path weights from the source $v_0$ have already determined
It repeatedly selects a vertax $u$ **not in $S$** with **minimum shortest-path** estimate, add to $S$, and ==ralaxes== $u$ out-edge
