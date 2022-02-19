```c
> int u[5] = {1,3,5,7,9};
> int v[5] = {0,2,4,6,8};
> int r[10];
> merge(r, u, v, 5, 5);
> for(int i = 0; i < 10; i++) printf("%d ", r[i]);
0 1 2 3 4 5 6 7 8 9
```