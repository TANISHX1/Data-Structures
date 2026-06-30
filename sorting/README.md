# Sorting Algorithms (C)

Classic O(n²) sorting algorithm implementations.

---

## File Reference

| File | Algorithm | Time Complexity | Notes |
|---|---|---|---|
| `bubble_sort.c` | Bubble sort | O(n²) | Early-exit optimization with flag-based check |
| `selection_sort.c` | Selection sort | O(n²) | Standard implementation |
| `insertion_sort.c` | Insertion sort | O(n²) | Standard implementation |

---

## Complexity Summary

| Algorithm | Best | Average | Worst | Space | Stable |
|---|---|---|---|---|---|
| Bubble sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion sort | O(n) | O(n²) | O(n²) | O(1) | Yes |

> Bubble sort's best case of O(n) is achieved via the early-exit optimization (skips remaining passes when no swaps occur).

---

## Build & Run

All files are standard C. Compile with any C compiler:

```bash
gcc -o bubble_sort bubble_sort.c && ./bubble_sort
gcc -o selection_sort selection_sort.c && ./selection_sort
gcc -o insertion_sort insertion_sort.c && ./insertion_sort
```
