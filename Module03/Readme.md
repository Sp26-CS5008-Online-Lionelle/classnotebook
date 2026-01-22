# Module 03


- [x] How to test free functions like free_polygon()
  - short answer, you don't really. You can set values to null and check, but not as useful - Those are what tools like valgrind are for


- [x] Understanding why assembling bitwise functions is more efficient than algebraic functions.
  - Short answer: because bitwise are binary math, logical operators require more cycles / branches before the calcs

```
1010   |
0100
----
1110



1010 &
0100
----
1000

<< 2

1010 << 2 = 101000
1010 << 3 = 1010000


1010 &
0101
---
0

1010  |
0101
----
1111
```
