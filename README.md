# Data Structures

Implementations of classic data structures in **C/C++** with a partial **Go reimplementation**.

---

## Project Structure

```
Data-Structures/
├── ptr_arithmatic.c              # Pointer arithmetic demo
├── c_string_manipulation/         # C string library demos (C++)
├── linked_list.c/                 # Linked list implementations (C)
├── stack_Queue/                   # Stack & Queue implementations (C)
├── trees/                         # Tree data structures (C)
├── sorting/                       # Sorting algorithms (C)
└── go reimplementation/           # Go reimplementation of selected structures
    ├── color/                      #   ANSI color constants
    ├── linkedlist/                 #   Linked list implementations
    └── stack_queue/                #   Stack & Queue implementations
```

---

## C Implementations

### `c_string_manipulation/` — C String Functions

Demos of the C string manipulation library (`<cstring>`), written in C++.

| File | Function(s) | Description |
|---|---|---|
| `strlen.cpp` | `strlen` | Compute string length |
| `strcat.cpp` | `strcat`, `strncat` | Concatenate two strings (full & bounded) |
| `strcpy-strncpy.cpp` | `strcpy`, `strncpy` | Copy strings (full & bounded) |
| `strncmp-strncmp.cpp` | `strncmp` | Compare two strings up to *n* characters |
| `strchrr.cpp` | `strchr` | Find all occurrences of a character in a string |

See [c_string_manipulation/README.md](c_string_manipulation/README.md) for details.

---

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
| `shortllist.c` | Singly | Sort by ticket number using bubble sort |
| `d_normal_ll.c` | Doubly | Insert at end, delete from front/back, forward & backward print |
| `d_norma_ll2.c` | Doubly | Insert at any position (front/back), delete at any position (front/back) |
| `c_normal_ll.c` | Circular | Recursive creation, circular traversal |

**Naming convention:**
- `normal_ll...` — Singly linked list
- `d_normal_ll...` — Doubly linked list
- `c_normal_ll...` — Circular linked list

See [linked_list.c/README.md](linked_list.c/README.md) for details.

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

See [stack_Queue/README.md](stack_Queue/README.md) for details.

---

### `trees/` — Tree Data Structures

| File | Structure | Operations |
|---|---|---|
| `simple_tree.c` | Binary tree | Recursive creation, inorder traversal |
| `bst.c` | Binary search tree | Insert, inorder/preorder/postorder traversal |
| `bst_2.c` | Binary search tree | Insert, delete (leaf/one-child/two-children), find inorder successor, inorder traversal |

See [trees/README.md](trees/README.md) for details.

---

### `sorting/` — Sorting Algorithms

| File | Algorithm | Time Complexity | Notes |
|---|---|---|---|
| `bubble_sort.c` | Bubble sort | O(n²) | Early-exit optimization (flag-based) |
| `selection_sort.c` | Selection sort | O(n²) | Standard implementation |
| `insertion_sort.c` | Insertion sort | O(n²) | Standard implementation |

See [sorting/README.md](sorting/README.md) for details.

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
- **`linkedlist/`** — Doubly linked list, circular singly linked list, node swapping, middle node (Tortoise & Hare), recursive singly linked list
- **`stack_queue/`** — Dynamic stack, Tower of Hanoi, bounded Tower of Hanoi, parenthesis checker, linear queue, circular queue, priority queue, deque

---

## Languages Used

- **C / C++** — Primary implementation language
- **Go** — Partial reimplementation with improved algorithms
