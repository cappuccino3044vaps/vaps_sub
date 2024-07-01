#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculatePi(int trials) {
    int insideCircle=0;
    int r;
    for(int i=1 ;i<=trials;++i){
        double x = (double)rand() / RAND_MAX * 2 ;
        double y = (double)rand() / RAND_MAX * 2 ;
        r=1.0/(1.0*x*x);
        if(y<=r){
            insideCircle++;
        }
    }
    return 4 * (double)insideCircle / trials;
}

double calculatePi2(int trials) {
    int insideCircle=0;
    int r;
    for(int i=1 ;i<=trials;++i){
        double x = (double)rand() / RAND_MAX * 2 ;
        double y = (double)rand() / RAND_MAX * 2 ;
        if(x*x+y*y<=1){
            insideCircle++;
        }
    }
    return 4 * (double)insideCircle / trials;
}

int main() {
    printf("何回おきに、何回くりかえすか\n");
    int rpt,times;
    int j=0;
    scanf("%d %d",&times,&rpt);
    printf("%d\n",rpt);
    while(j<=rpt){
        double pi = calculatePi2(times);
        printf("%f\n",pi);
        j++;
    }
    return 0;
}
