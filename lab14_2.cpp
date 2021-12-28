#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}
void updateImage(bool n[][M],int size,int xs,int ys){
    int i=xs,j=ys,row=N,line=M;
    for(int rc=0;rc<line;rc++){
        for(int lc=0;lc<row;lc++){
            if(sqrt(((rc-j)*(rc-j))+((lc-i)*(lc-i)))<=(size-1)) n[lc][rc]=1;
        }
    }
}


void showImage(const bool x[][M]){
    for(int i=1;i<=M+2;i++) cout<<"-";
    cout << endl;
    for(int row=0;row<N;row++){
        for(int j=0;j<M+2;j++){
            switch(j){
                case 0 : cout << "|";
                        continue;
                case M+1 : cout <<"|";
                        continue;
            }
            if(x[row][j-1]==1) cout << "*";
            else cout << " ";
            }
    cout<<endl;
    }
    for(int i=1;i<=M+2;i++) cout<<"-";
    cout << endl;
}
