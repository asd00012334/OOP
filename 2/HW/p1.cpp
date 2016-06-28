#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class matrix2D{
public:
    int rowNum;
    int colNum;
    vector<vector<int> > content;
    matrix2D(int, int);
    ~matrix2D(){};
    matrix2D operator+(matrix2D right);
    matrix2D operator*(matrix2D right);

};


int main(){
    int m,n,l;
    scanf("%d%d%d",&m,&n,&l);
    matrix2D left(m,n),right(n,l);
    for(int row=0;row<m;row++)
    for(int col=0;col<n;col++){
        cin>>left.content[row][col];
    }
    for(int row=0;row<n;row++)
    for(int col=0;col<l;col++){
        cin>>right.content[row][col];
    }
    matrix2D output(m,l);
    output=left*right;
    for(int row=0;row<m;row++){
        for(int col=0;col<l;col++){
            if(col!=0)
                cout<<" ";
            cout<<output.content[row][col];
        }
        cout<<endl;
    }
    return 0;
}

matrix2D::matrix2D(int rowNum, int colNum){
    content.resize(rowNum);
    for(int cnt=0;cnt<rowNum;cnt++){
        content[cnt].resize(colNum);
    }
    this->rowNum=rowNum;
    this->colNum=colNum;
    return;
}

matrix2D matrix2D::operator+(matrix2D right){
    matrix2D output(rowNum,colNum);
    matrix2D& This=*this;
    int rowNum=this->rowNum;
    int colNum=this->colNum;
    for(int cnt=0;cnt<rowNum;cnt++)
    for(int cnt2=0;cnt2<colNum;cnt2++)
        output.content[cnt][cnt2]=This.content[cnt][cnt2]+right.content[cnt][cnt2];
    return output;
}

matrix2D matrix2D::operator*(matrix2D right){
    matrix2D& This=*this;
    int m,n,l;
    m=This.rowNum;
    n=This.colNum;
    l=right.colNum;
    matrix2D output(m,l);

    for(int row=0;row<m;row++)
    for(int col=0;col<l;col++)
        output.content[row][col]=0;

    for(int row=0;row<m;row++)
    for(int cnt=0;cnt<n;cnt++)
    for(int col=0;col<l;col++)
        if(This.content[row][cnt]==0)
            break;
        else
            output.content[row][col]+=This.content[row][cnt]*right.content[cnt][col];
    return output;
}
