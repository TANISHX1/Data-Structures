# Stack & Queue Implementations (C)

Array-based stack and queue implementations, plus classic stack applications.

---

## File Reference

### Stack

| File | Structure | Operations |
|---|---|---|
| `stack.c` | Stack (array-based) | Push, pop |

### Queue

| File | Structure | Operations |
|---|---|---|
| `simple_queue.c` | Linear queue (array-based) | Enqueue, dequeue |
| `circular_queue.c` | Circular queue (array-based) | Enqueue, dequeue (wraparound) |

### Stack Applications

| File | Application | Description |
|---|---|---|
| `toh.c` | Tower of Hanoi | Recursive solution counting total moves |
| `infex_postfix.c` | Infix → Postfix | Converts infix expressions to postfix notation using an operator stack |

### Shared Header

| File | Purpose |
|---|---|
| `header.h` | Operator stack utility functions shared with `infex_postfix.c` |

---

## Build & Run

All files are standard C. Compile with any C compiler:

```bash
gcc -o stack stack.c && ./stack
gcc -o toh toh.c && ./toh
gcc -o simple_queue simple_queue.c && ./simple_queue
gcc -o circular_queue circular_queue.c && ./circular_queue
```

For `infex_postfix.c`, include the header directory:

```bash
gcc -I. -o infix_postfix infex_postfix.c && ./infix_postfix
```
