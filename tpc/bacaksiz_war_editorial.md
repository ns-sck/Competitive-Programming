Firstly, let’s start by sorting the given array of positions. In problems like this, if we are not required to preserve the original order and sorting does not lose any important information, it is always a good idea to sort the array. Sorting ensures that we can think about the problem in a structured way.

Now we have $N$ sorted elements, and we need to pick $K$ of them such that the **minimum distance between any two chosen elements is maximized**.  

A brute-force solution would involve trying all possible $K$-combinations of $N$, which is infeasible because $Combination(N, K)$ can be extremely large. We need something smarter.

Suppose we are magically given an answer $X$. Can we check whether it is possible to place $K$ forces such that the minimum distance between any two is at least $X$?

The greedy strategy works here:

- Always place the first force at the smallest position.
- For each next force, place it at the **first available position** that is at least $X$ units away from the last chosen one.
- Continue this process until either:
  - We place all $K$ forces (success, meaning distance $X$ is feasible).
  - We run out of positions (failure, meaning distance $X$ is not feasible).

If we succeed, then we know $X$ is a possible solution. If not, then $X$ is too large.

Since the answer space is monotonic — if a distance $X$ is possible, then any distance smaller than $X$ is also possible — we can apply **binary search** to find the maximum possible $X$.

- **Lower bound ($lo$)** = 0 (minimum distance can be zero if forces are in the same spot, though usually we start from 1).
- **Upper bound ($hi$)** = (last position - first position) (the maximum possible distance if we place forces at the two ends).

Binary search works as follows:

1. Compute $mid = (lo + hi) / 2$.
2. Check if $mid$ is feasible using the greedy check.
3. If yes, update $answer = mid$ and move $lo = mid + 1$ (try for a bigger distance).
4. If no, move $hi = mid - 1$ (try for a smaller distance).
5. Continue until $lo > hi$.