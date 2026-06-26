# Data Structures

Implementations of classic data structures in **C** with a partial **Go reimplementation**.

---

## Project Structure

```
Data-Structures/
├── ptr_arithmatic.c          # Pointer arithmetic demo
├── linked_list.c/             # Linked list implementations (C)
├── stack_Queue/               # Stack & Queue implementations (C)
├── trees/                     # Tree data structures (C)
├── sorting/                   # Sorting algorithms (C)
└── go reimplementation/       # Go reimplementation of selected structures
```

---

## C Implementations

### `linked_list.c/` — Linked Lists

Contains singly, doubly, and circular linked list implementations.

| File | Type | Operations |
|---|---|---|
| `normal_ll.c` | Singly | Create (prepend), traverse, free |
| `normal_ll2.c` | Singly | Insert at beginning, delete from beginning |
| `normal_ll3.c` | Singly | Insert at end, delete from end |
| `normall_ll4.c` | Singly | Insert at any position, delete at any position |
| `normal__1.1.c` | Singly | Recursive insert, string data (`char*`) |
| `swapping_nodes.c` | Singly | Swap two nodes by ID |
| `middle_node.c` | Singly | Find middle node (count & re-traverse) |
| `d_normal_ll.c` | Doubly | Insert at end, delete from front/back, forward & backward print |
| `d_norma_ll2.c` | Doubly | Insert at any position (front/back), delete at any position (front/back) |
| `c_normal_ll.c` | Circular | Recursive creation, circular traversal |

**Naming convention:**
- `normal_ll...` — Singly linked list
- `d_normal_ll...` — Doubly linked list
- `c_normal_ll...` — Circular linked list

---

### `stack_Queue/` — Stack & Queue

| File | Structure | Operations |
|---|---|---|
| `stack.c` | Stack (array-based) | Push, pop |
| `toh.c` | Stack application | Tower of Hanoi (recursive) |
| `infex_postfix.c` | Stack application | Infix to postfix conversion |
| `simple_queue.c` | Linear queue (array-based) | Enqueue, dequeue |
| `circular_queue.c` | Circular queue (array-based) | Enqueue, dequeue (wraparound) |
| `header.h` | Shared header | Operator stack utilities for infix-postfix |

---

### `trees/` — Tree Data Structures

| File | Structure | Operations |
|---|---|---|
| `simple_tree.c` | Binary tree | Recursive creation, inorder traversal |
| `bst.c` | Binary search tree | Insert, inorder/preorder/postorder traversal |
| `bst_2.c` | Binary search tree | Insert, delete (leaf/one-child/two-children), find inorder successor, inorder traversal |

---

### `sorting/` — Sorting Algorithms

| File | Algorithm | Time Complexity | Notes |
|---|---|---|---|
| `bubble_sort.c` | Bubble sort | O(n²) | Early-exit optimization (flag-based) |
| `selection_sort.c` | Selection sort | O(n²) | Standard implementation |
| `insertion_sort.c` | Insertion sort | O(n²) | Standard implementation |

---

### `ptr_arithmatic.c` — Pointer Arithmetic

Demonstrates 5 categories of C pointer operations:
- Pointer increment (`ptr++`)
- Pointer addition (`ptr + i`)
- Pointer subtraction (distance/size computation)
- Pointer comparison (equality / element lookup)
- Pointer comparison (greater-than / range check)

---

## Go Reimplementation

See [`go reimplementation/README.md`](go%20reimplementation/README.md) for full details.

Quick summary:
- **`color/`** — ANSI escape code constants package
- **`linkedlist/`** — Doubly linked list, circular singly linked list, node swapping, middle node (Tortoise & Hare)

---

## Languages Used

- **C** — Primary implementation language
- **Go** — Partial reimplementation with improved algorithms
