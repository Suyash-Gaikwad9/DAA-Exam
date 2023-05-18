#include<iostream> 
using namespace std; 
void merge(int array[],int l, int m, int h){ int n1=m-l+1; 
int n2=h-m; 
int left[n1],right[n2]; 
for(int i=0;i<n1;i++){ 
left[i]=array[i+l]; 
} 
for(int i=0;i<n2;i++){ 
right[i]=array[i+m+1]; 
} 
int i=0,j=0,k=l; 
while(i<n1 && j<n2){ 
if(left[i]<=right[j]){ 
array[k]=left[i]; 
i++; 
}else{ 
array[k]=right[j]; 
j++; 
} 
k++; 
} 
while(i<n1){ 
array[k]=left[i]; 
i++;k++; 
} 
while(j<n2){
array[k]=right[j]; 
k++;j++; 
} 
} 
void mergeSort(int array[], int begin, int end) { 
if (begin >= end) 
return;  
int mid = begin + (end - begin) / 2; 
mergeSort(array, begin, mid); 
mergeSort(array, mid + 1, end); 
merge(array, begin, mid, end); 
} 
void printArray(int A[], int size) 
{ 
for (auto i = 0; i < size; i++) 
cout << A[i] << " "; 
} 
int main() 
{ 
int arr[] = { 12, 11, 13, 5, 6, 7 }; 
auto arr_size = sizeof(arr) / sizeof(arr[0]); 
cout << "Given array is \n"; 
printArray(arr, arr_size); 
mergeSort(arr, 0, arr_size - 1); 
cout << "\nSorted array is \n"; 
printArray(arr, arr_size); 
return 0; 
} 
