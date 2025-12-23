We need to count the number of **balanced vertices** in a rooted tree.  

- If a node has **zero** or **one** child, it is always balanced.  
- Otherwise, we need to check if **all of its children have the same subtree size**.  

The size of a node’s subtree is equal to the sum of the sizes of its children’s subtrees plus one (the node itself):  

$$
\text{subtree}[u] = 1 + \sum_{v \in \text{children}(u)} \text{subtree}[v]
$$

To compute subtree sizes, we use **DFS** starting from the root:  

1. Start at the root node.  
2. For each child of the current node, recursively visit that child first.  
3. Only after visiting all children, compute the current node’s subtree size by summing the sizes of its children and adding one for itself.  

This order of visiting children **before the parent** is called **postorder traversal**.  
It ensures that when we calculate a node’s subtree size, all of its children’s sizes are already known. 
Once we have subtree sizes, checking whether a node is balanced becomes straightforward.  