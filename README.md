# tp-algorithmique-3is
## Exercise 4
## 4.1 — Recursive Algorithm Proposal for GCD
### Notations
- `a` and `b`: two positive (non-zero) integers
- `GCD(a, b)`: the greatest common divisor of `a` and `b`
### Base Case (“Anchor”)
When `b = 0`, the computation stops:
> GCD(a, 0) = a
This is the **stopping condition** of the recursion.  
It means that as soon as the second number becomes zero, the GCD is the first number.
### Recursive Part
Otherwise, we apply the **mathematical property of the GCD (Euclidean algorithm)**:
> GCD(a, b) = GCD(b, a % b)
### Steps of the Recursive Process
1. If `b == 0` → return `a`
2. Else → recursively call `GCD(b, a % b)`
### Example of Execution
Calculation of **GCD(35, 45)**:
Recursive Call | Computation Performed | Partial Result
GCD(35, 45) | → GCD(45, 35) | - |
GCD(45, 35) | → GCD(35, 10) | - |
GCD(35, 10) | → GCD(10, 5)  | - |
GCD(10, 5)  | → GCD(5, 0)   | - |
GCD(5, 0)   | returns 5     | Final Result = 5 |
### Summary
- **Base case:** `GCD(a, 0) = a`
- **Recursive case:** `GCD(a, b) = GCD(b, a % b)`
- This algorithm is based on the **Euclidean division principle** and efficiently computes the GCD.


## Exercise 6 — Longest Increasing Subsequence (LIS)
### Problem Description
Given a sequence of integers `A = a[1..n]` (n ≤ 5000, -10000 ≤ a[i] ≤ 10000), a subsequence of `A` is a sequence that contains some elements of `A` while maintaining their relative order.
The task is to find the **longest increasing subsequence** of `A`.

Example:  
`A = (1, 2, 3, 4, 9, 10, 5, 6, 7)`  
The longest increasing subsequence is `(1, 2, 3, 4, 5, 6, 7)`.


### 6.1 — Dynamic Programming Approach

#### Notation
- `A[i]` : the i-th element of the sequence
- `L[i]` : length of the longest increasing subsequence ending at `A[i]`

#### Base Case
If we have a single element, the LIS ending at that element is just 1:  
L[1] = 1

#### Recursive Formula
For each `i` from 2 to n, check all previous elements `j < i`:  
if A[j] < A[i]:
L[i] = max(L[i], L[j] + 1)
else:
L[i] = 1

#### Result
The length of the LIS for the whole sequence is:
LIS = max(L[i]) for i = 1..n

### Example of Execution

Sequence: `A = (1, 2, 3, 4, 9, 10, 5, 6, 7)`

| i | A[i] | L[i] | Explanation |
| 1 | 1    | 1    | first element |
| 2 | 2    | 2    | (1, 2) |
| 3 | 3    | 3    | (1, 2, 3) |
| 4 | 4    | 4    | (1, 2, 3, 4) |
| 5 | 9    | 5    | (1, 2, 3, 4, 9) |
| 6 | 10   | 6    | (1, 2, 3, 4, 9, 10) |
| 7 | 5    | 5    | (1, 2, 3, 4, 5) |
| 8 | 6    | 6    | (1, 2, 3, 4, 5, 6) |
| 9 | 7    | 7    | (1, 2, 3, 4, 5, 6, 7) |

**Length of LIS = 7**



