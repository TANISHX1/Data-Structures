#include <stdio.h>
#include <sys/time.h>

void toh(int n, int l, int m, int r)
    {
    if (n != 0) {
        toh(n - 1, l, r, m);
        printf("%d -> %d\n",l,r);
        toh(n - 1, m, l, r);
        }
}
int main()
    {
     struct timeval start, end;
     gettimeofday(&start, NULL);
     
     toh(20, 1, 2, 3);
     
     gettimeofday(&end, NULL);
    long exe_time = (end.tv_sec - start.tv_sec) * 1e6;
    exe_time += (end.tv_usec - start.tv_usec);
    printf("\nTotal Execution time : [ %3d us ] \n", exe_time);
    
    return 0;
    }