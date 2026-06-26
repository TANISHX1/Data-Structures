# Go Reimplementation

Go reimplementation of selected data structures from the C codebase. Uses a shared `color` package for ANSI terminal formatting (replacing C `#define` macros).

---

## Folder Structure

```
go reimplementation/
├── color/
│   └── colors.go           # ANSI color/style constants
└── linkedlist/
    ├── linkedlist.go        # Doubly linked list
    ├── ll2.go               # Circular singly linked list
    ├── swap_node.go         # Node swapping
    └── middle.go            # Middle node (Tortoise & Hare)
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

## C vs Go Comparison

| Feature | C Implementation | Go Implementation |
|---|---|---|
| Doubly linked list | Insert/delete at any position (front/back) | Insert at begin, delete by ID |
| Circular linked list | Recursive creation, single traversal | Insert, delete by ID, multi-cycle traversal |
| Node swapping | By node ID (issues with adjacent nodes) | By node ID, reads external data |
| Middle node | Count + re-traverse O(n)+O(n) | Tortoise & Hare O(n) single pass |
| Formatting | `#define` macros per file | Shared `color` package |

**Key improvements in Go:**
- String data instead of integer keys (except `middle.go`)
- Maintains explicit `tail` pointer in circular list
- Optimal Tortoise & Hare algorithm for middle node
- External file-based test data for node swapping
