#include<iostream>
#include<climits>
using namespace std;
int main (){
    int arr[] = {7, 2, 9, 4, 1};
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i<5; i++){
        if(max < arr[i]){
        max = arr[i];
        }
        if(min > arr[i]){
        min = arr[i];
        }
    }
    cout<<"Maximum element is :- "<<max<<endl;
    cout<<"Minimum element is :- "<<min<<endl;
    return 0;
}