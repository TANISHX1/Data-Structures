# Linked List Implementations (C)

Singly, doubly, and circular linked list implementations in C.

---

## File Reference

### Singly Linked List

| File | Operations |
|---|---|
| `normal_ll.c` | Create (prepend), traverse, free |
| `normal_ll2.c` | Insert at beginning, delete from beginning |
| `normal_ll3.c` | Insert at end, delete from end |
| `normall_ll4.c` | Insert at any position, delete at any position |
| `normal__1.1.c` | Recursive insert, string data (`char*`) |
| `swapping_nodes.c` | Swap two nodes by ID |
| `middle_node.c` | Find middle node (count & re-traverse) |
| `shortllist.c` | Job-ticket sorting using bubble sort on a singly linked list |

### Doubly Linked List

| File | Operations |
|---|---|
| `d_normal_ll.c` | Insert at end, delete from front/back, forward & backward print |
| `d_norma_ll2.c` | Insert at any position (front/back), delete at any position (front/back) |

### Circular Linked List

| File | Operations |
|---|---|
| `c_normal_ll.c` | Recursive creation, circular traversal |

---

## Naming Convention

- `normal_ll...` — Singly linked list
- `d_normal_ll...` — Doubly linked list
- `c_normal_ll...` — Circular linked list

---

## Build & Run

All files are standard C. Compile with any C compiler:

```bash
gcc -o normal_ll normal_ll.c && ./normal_ll
gcc -o d_normal_ll d_normal_ll.c && ./d_normal_ll
gcc -o c_normal_ll c_normal_ll.c && ./c_normal_ll
```
