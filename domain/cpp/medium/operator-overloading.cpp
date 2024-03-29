#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
        vector<vector<int>> a;

        Matrix operator+(const Matrix& a){
            Matrix matrixSum;
            int size_v = this->a.size();
            for(int index_vertical= 0; index_vertical < size_v; index_vertical++){
                vector<int> horizontal;
                int size_horizontal = this->a[index_vertical].size();
                for(int index_horizontal = 0; index_horizontal < size_horizontal; index_horizontal++){
                    horizontal.push_back(a.a[index_vertical][index_horizontal]+this->a[index_vertical][index_horizontal]);
                };
                matrixSum.a.push_back(horizontal);
            }

            return matrixSum;
        }   
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
