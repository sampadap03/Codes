/*x-Tree is an infinite rooted tree where:
- each vertex has exactly x childern
- each edge has some weight
- if we look at the edges that goes from some vertex to its children (exactly x edges), then their weights will equal 1, 2, 3, ..., x.

image
As

soon as Abhijeet found out about the tree, he immediately wondered: "How many paths of total weight n (the sum of all weights of the edges in the path) are there, starting from the root of a x-tree and also containing at least one edge of weight at least d ? ".

Help Abhijeet find an answer to his question. As the number of ways can be rather large, print it modulo 1000000007(109+7)

Input Format

A single line contains three space-separated integers: n , x and d .

Constraints

1 ≤ n,x ≤ 100
1 ≤ d ≤ x

Output Format

Print a single integer — the answer to the problem mo
dulo 1000000007 (109 + 7)*/
