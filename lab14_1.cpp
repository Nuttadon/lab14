#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double x[],int N,double ans[]){
    double sumx=0,sumx4sd=0,sumx4hm=0,multix=1,root=1/(double)N;
    ans[5] = x[0];
    ans[4] = x[0];
    for(int j=0;j<N;j++){
        sumx += x[j];
        sumx4hm += 1/x[j];
        multix *= x[j];
    }
    ans[0] = sumx/N;
    for(int j=0;j<N;j++)sumx4sd += pow((x[j]-ans[0]),2);
    ans[1] = sqrt(sumx4sd/N);
    ans[3] = N/sumx4hm;
    ans[2]=pow(multix,root);
    for(int j=0;j<N;j++){
        if(x[j]>ans[4]) ans[4] = x[j];
        if(x[j]<ans[5]) ans[5] = x[j];
    }
}
