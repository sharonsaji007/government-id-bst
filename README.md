# Government Identification Database Using BST

## Aim

To implement a Binary Search Tree (BST) for storing government
identification numbers and compare BST search with Linear Search.

## Identification Numbers

The following identification numbers are used:

A102, A25, A7, B100, B12, A120, B3, A45

## Objectives

1. Implement a BST using C.
2. Display the inorder traversal.
3. Compare BST Search and Linear Search.
4. Count the number of comparisons.
5. Analyse the effect of key length.
6. Analyse the effect of insertion order.
7. Determine time and space complexity.
8. Suggest a suitable approach for a growing database.

## Inorder Traversal

A102 A120 A25 A45 A7 B100 B12 B3

## Search Comparison

| ID | BST Comparisons | Linear Comparisons |
|----|-----------------|-------------------|
| A102 | 1 | 1 |
| A120 | 3 | 6 |
| B3 | 6 | 7 |
| A45 | 4 | 8 |

## Complexity

### BST Search

Best Case: O(1)

Average Case: O(log n)

Worst Case: O(n)

### Linear Search

Best Case: O(1)

Average Case: O(n)

Worst Case: O(n)

### BST Space Complexity

O(n)

## Effect of Insertion Order

The height of a BST depends strongly on the order in which
the keys are inserted. A suitable insertion order can produce
a relatively balanced tree, while sorted insertion can produce
a skewed tree.

## Effect of Key Length

Key length does not directly determine BST height. However,
longer string keys can require more character comparisons.

## Conclusion

A self-balancing BST such as an AVL Tree or Red-Black Tree is
suitable for maintaining efficient searches as the database
grows because it prevents the tree from becoming highly skewed.
