#include<iostream>
#include<climits>
#include <algorithm>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int min=arr[0];
    int max=arr[0];
    for(int i:arr){
        if(i<min){
            min=i;
        }
        if(i>max){
            max=i;
        }
    }
    cout<<"Min element is "<<min<<endl;
    cout<<"Max element is "<<max<<endl;
    return 0;
}
