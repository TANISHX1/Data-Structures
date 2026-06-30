# Tree Data Structures (C)

Binary tree and binary search tree implementations.

---

## File Reference

| File | Structure | Operations |
|---|---|---|
| `simple_tree.c` | Binary tree | Recursive creation, inorder traversal |
| `bst.c` | Binary search tree | Insert, inorder/preorder/postorder traversal |
| `bst_2.c` | Binary search tree | Insert, delete (leaf / one-child / two-children), find inorder successor, inorder traversal |

---

## Build & Run

All files are standard C. Compile with any C compiler:

```bash
gcc -o simple_tree simple_tree.c && ./simple_tree
gcc -o bst bst.c && ./bst
gcc -o bst2 bst_2.c && ./bst2
```
