# C String Manipulation

Demos of the C string manipulation library (`<cstring>`), written in C++.

---

## File Reference

| File | Function(s) | Description |
|---|---|---|
| `strlen.cpp` | `strlen` | Computes and prints the length of an input string |
| `strcat.cpp` | `strcat`, `strncat` | Concatenates two strings — `strcat` joins fully, `strncat` joins up to *n* chars |
| `strcpy-strncpy.cpp` | `strcpy`, `strncpy` | Copies strings — `strcpy` copies fully, `strncpy` copies up to *n* chars |
| `strncmp-strncmp.cpp` | `strncmp` | Compares two strings up to *n* characters; reports equal, greater, or less |
| `strchrr.cpp` | `strchr` | Finds and counts all occurrences of a target character in a string |

---

## Build & Run

All files are standard C++ with `<cstring>`. Compile with any C++ compiler:

```bash
g++ -o strlen strlen.cpp && ./strlen
g++ -o strcat strcat.cpp && ./strcat
g++ -o strcpy_strncpy strcpy-strncpy.cpp && ./strcpy_strncpy
g++ -o strncmp strncmp-strncmp.cpp && ./strncmp
g++ -o strchrr strchrr.cpp && ./strchrr
```
