#include <iostream>
#include <vector>
using namespace std;

int main(){
int x, y;
vector<vector<int>> vect;
vect = {    {1, 0, 1},
            {1, 1, 1}, 
            {1, 1, 1},
            {1, 0, 1}        };

y = vect.size();
x = vect[1].size();
// cout<<x<<"\t"<<y;
for(int i = 0; i < x; i++){ 
  if (vect[0][i] == 0){
      for(int j =0; j < y; j++){
          vect[j][i] = 0;
      }
  }

}

for(int i = 0; i < y; i++){
    for(int j =0; j < x; j++){
        cout<<vect[i][j]<<"\t";
    }
    cout<<"\n";
}

return 0;
}