
# Solutions
**Part 1: Coding**
1. The worst case of Quicksort occurs when the pivots are chosen such that one subarray contains zero element and other one contains n-1 elements.
2. The prerequisite of binary search is that the array must be sorted.
3. The best time complexity of merge sort is O(nlogn) and worst time complexity is O(nlogn)
4. Minimal Spanning tree does not give the shortest distance between any 2 specified nodes.
5. log q (base p) = log q (base k) / log p (base k)
6. a = b, b = a/2
  
7.
```
bool myFun(int N) { return (N & (N-1)) == 0;}
```

8.
```
 int secMin(int nums[], int len) {
  int cnt[100005], i, j, val, mn = INT_MAX;
  memset(cnt, 0, sizeof(cnt));
  for (i = 0; i < len; i++) {
      val = nums[i];
      cnt[val] += 1;
      if (val < mn) {
          mn = val;
      }
  }
  if (cnt[mn] > 1) {
      return mn;
  }

  for (i = mn+1; i <= 100000; i++) {
      if (cnt[i] > 0)
          return i;
  }
}
```
9.
  ```
 int waysOfSum30(int nums[], int len) {
  int i, j, k, total = 0, a, b, c;
  for (i = 0; i < len; i++) {
      for (j = 0; j < len; j++) {
          for (k = 0; k < len; k++) {
              if (i != j && j != k && k != i) {
                  a = nums[i];
                  b = nums[j];
                  c = nums[k];
                  if (a+b+c == 30 && i < j && j < k) {
                      total += 1;
                  }
              }
          }
      }
  }
  return total;
}
 ```
10. Fow n = 2^31-1, the provided code will give an incorrect answer.
12.
```
string position(int n) {
    int a = 0, b = 1, c = 3, d = 6;
    int total = 1+2+3+4;
    n = n%total;
    if (n == a) return "a";
    else if (n == b) return "b";
    else if (n == c) return "c";
    else if (n == d) return "d";
    else if (n > a && n < b) return "ab";
    else if (n > b && n < c) return "bc";
    else if (n > c && n < d) return "cd";
    else return "ad";
}
```



