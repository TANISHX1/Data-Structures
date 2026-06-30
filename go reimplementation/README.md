# Go Reimplementation

Go reimplementation of selected data structures from the C/C++ codebase. Uses a shared `color` package for ANSI terminal formatting (replacing C `#define` macros).

---

## Folder Structure

```
go reimplementation/
├── color/
│   └── colors.go                # ANSI color/style constants
├── linkedlist/
│   ├── linkedlist.go             # Doubly linked list
│   ├── ll2.go                    # Circular singly linked list
│   ├── swap_node.go              # Node swapping
│   ├── middle.go                 # Middle node (Tortoise & Hare)
│   └── resurcive_ll.go           # Recursive singly linked list
└── stack_queue/
    ├── stack.go                  # Dynamic stack (slice-based)
    ├── toh.go                    # Tower of Hanoi
    ├── stack_application.go      # Paper Folding Sequence (Dragon Curve)
    ├── stack_application2.go     # Bounded Tower of Hanoi (adjacent-only)
    ├── stack_application3.go     # Parenthesis checker
    ├── queue.go                  # Linear queue (array-based)
    ├── circular_queue.go         # Circular queue (array-based)
    ├── priority_queue.go         # Priority queue (sorted insertion)
    └── dequeue.go                # Deque (doubly linked list)
```

---

## `color/` — Terminal Formatting

**File:** `colors.go`

Provides ANSI escape code constants for colored terminal output, used across all Go files.

- **Text styles** — Reset, Bold, Dim, Italic, Underline, Blink, Reverse, Hidden
- **Foreground colors** — Black through White (30–37)
- **Bright foreground colors** — BrightBlack through BrightWhite (90–97)
- **Background colors** — Black through White (40–47)

---

## `linkedlist/` — Linked List Implementations

### `linkedlist.go` — Doubly Linked List

| Operation | Description |
|---|---|
| `insert_at_begin` | Prepend node at head, handles empty list |
| `delete` | Delete by node ID — handles first, middle, and last node cases |
| `transverse` | Forward traversal from head to nil, prints prev/data/next |
| `format_print` | Formats node info with previous/next pointer details |

**Node struct:** `{node_id, data (string), next_node, previous_node}`

---

### `ll2.go` — Circular Singly Linked List

| Operation | Description |
|---|---|
| `insert` | Prepend at head, maintains `tail.next_node = head` linkage |
| `delete` | Delete by node ID — handles empty, single-node, head, and middle/last cases |
| `transverse` | Traverses for N cycles, prints cycle count |
| `format_print` | Formats node ID, data, and next pointer |

**Node struct:** `{node_id, data (string), next_node}`

**Globals:** `head`, `tail`, `count`

---

### `swap_node.go` — Node Swapping (Singly Linked List)

| Operation | Description |
|---|---|
| `open_file` | Reads external test data file for node strings |
| `initalize_list` | Creates list with data from file, cycles if needed |
| `swap_node` | Swaps two nodes by ID — handles head node and general case |
| `transverse` | Standard traversal and print |

**Node struct:** `{node_id, data (string), next_node}`

---

### `middle.go` — Middle Node (Tortoise & Hare Algorithm)

| Operation | Description |
|---|---|
| `initalize_list` | Creates N sequential nodes |
| `middle_node` | Tortoise & Hare — slow moves 1 step, fast moves 2 steps |
| `transverse` | Standard traversal with empty-list check |
| `format_print` | Formats node ID and next pointer |

**Algorithm:** Single-pass O(n) — improves over the C version which counts then re-traverses.

- Odd number of nodes → prints single middle
- Even number of nodes → prints both middle nodes

---

### `resurcive_ll.go` — Recursive Singly Linked List

| Operation | Description |
|---|---|
| `insert` | Recursive insert — walks to `nil` then creates and back-propagates the node |
| `transverse` | Iterative traversal with empty-list check |
| `format_print` | Formats node ID and next pointer |

**Node struct:** `{node_id, next_node}`

**Key difference:** Build and traverse using recursion instead of iterative loops.

---

## `stack_queue/` — Stack & Queue Implementations

### `stack.go` — Dynamic Stack

| Operation | Description |
|---|---|
| `push` | Append value to slice |
| `pop` | Remove and print last element; underflow check |
| `top` | Return top element; invalid-index check |

**Implementation:** Go slice (dynamic array) with `append`/reslice.

---

### `toh.go` — Tower of Hanoi

Classic recursive Tower of Hanoi with move counter.

---

### `stack_application.go` — Paper Folding Sequence (Dragon Curve)

| Operation | Description |
|---|---|
| `sequenceprint` | Recursively generates the paper folding / dragon curve sequence (R/L direction flips) |

---

### `stack_application2.go` — Bounded Tower of Hanoi (Adjacent-Only)

| Operation | Description |
|---|---|
| `a_toh` | Tower of Hanoi variant where disks can only move between adjacent pegs |

**Constraint:** Disks must move A→B→C (no direct A→C), increasing move count significantly.

---

### `stack_application3.go` — Parenthesis Checker

| Operation | Description |
|---|---|
| `Parenthesses_check` | Validates balanced parentheses `()`, `{}`, `[]` using a rune stack |

---

### `queue.go` — Linear Queue

| Operation | Description |
|---|---|
| `insert` | Enqueue at rear; overflow check at capacity 64 |
| `delete` | Dequeue from front; underflow check |

**Implementation:** Fixed-size `[64]rune` array with `front`/`rear` indices.

---

### `circular_queue.go` — Circular Queue

| Operation | Description |
|---|---|
| `insert` | Enqueue with wraparound at rear; overflow when `rear == front - 1` |
| `delete` | Dequeue from front with modular wraparound; resets when queue empties |
| `printqueue` | Colored queue printout using `color` package |

**Implementation:** Fixed-size `[64]rune` circular array using modular arithmetic.

---

### `priority_queue.go` — Priority Queue

| Operation | Description |
|---|---|
| `insert` | Sorted insertion — places node by ascending priority |
| `delete` | Remove and print highest-priority (last) element; underflow check |

**Node struct:** `{char (rune), priority (int)}`

**Implementation:** Slice-based with in-order insertion; dequeue from the end.

---

### `dequeue.go` — Deque (Doubly Linked List)

| Operation | Description |
|---|---|
| `insert_front` | Prepend node at head; handles empty list |
| `insert_end` | Append node at tail; handles empty list |
| `delete_front` | Remove and return head node; handles single-node list |
| `delete_end` | Remove and return tail node; handles single-node list |
| `transverse` | Bidirectional traversal (front→end or end→front) |
| `format_print` | Formats node with prev/next pointers |

**Node struct:** `{node_id, value (rune), prev, next}`

**Globals:** `queue` (head), `tail`, `node_count`

---

## C vs Go Comparison

| Feature | C Implementation | Go Implementation |
|---|---|---|
| Doubly linked list | Insert/delete at any position (front/back) | Insert at begin, delete by ID |
| Circular linked list | Recursive creation, single traversal | Insert, delete by ID, multi-cycle traversal |
| Node swapping | By node ID (issues with adjacent nodes) | By node ID, reads external data |
| Middle node | Count + re-traverse O(n)+O(n) | Tortoise & Hare O(n) single pass |
| Recursive list | Recursive insert with `char*` data | Recursive insert with node IDs |
| Stack | Array-based, push/pop | Slice-based (dynamic), push/pop/top |
| Tower of Hanoi | Standard recursive | Standard + bounded (adjacent-only) variant |
| Parenthesis check | Infix-to-postfix with operator stack | Direct bracket matching |
| Queue | Linear & circular (array-based) | Linear & circular (array-based) |
| Priority queue | — | Sorted-insertion slice-based |
| Deque | — | Doubly linked list with `prev`/`next` |
| Formatting | `#define` macros per file | Shared `color` package |

**Key improvements in Go:**
- String data instead of integer keys (except `middle.go`, `resurcive_ll.go`)
- Maintains explicit `tail` pointer in circular list and deque
- Optimal Tortoise & Hare algorithm for middle node
- External file-based test data for node swapping
- Additional data structures: priority queue, deque, parenthesis checker, paper folding sequence
- Bounded Tower of Hanoi variant (adjacent-peg constraint)
