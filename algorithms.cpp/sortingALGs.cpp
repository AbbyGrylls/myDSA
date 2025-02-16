#include<iostream>
#include<array>
using namespace std;
void selectionsort(){//sorting by selecting least one and replacing in ascend order using temporary variable
    int arr[10]={78,34,25,31,65,44,49,52,13,7};
    for(int i=0;i<10;i++){
        int min=i;
        for(int j=i+1;j<10;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;   
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<"\t";
    }
    //return 0;
}

void bubblesort(){//sorting by comparing side by side elements in two for loops
    int arr[10]={78,34,25,31,65,44,49,52,13,7};
    for(int i=0;i<10-1;i++){
        for(int j=0;j<10-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<"\t";
    }
}
int main(){
    cout<<"enter sorting methond: 1 selection sorting\n2 bubble sorrting \n";
    int n;
    cin>>n;
    if(n==1){
        selectionsort();
    }
    else if(n=2){
        bubblesort();
    }
    else{
        cout<<"invalid choice:";
    }
    return 0;
}
