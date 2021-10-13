#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000
int* createArray(int n);
int* dumpArray(int *a,int n);
// Create An Array
int* createArray(int n){
  int *a=(int*)malloc(n*sizeof(int));
  return a;
}
// Dump Array
int* dumpArray(int* a, int n)
{
  int i;
  srand((unsigned)time(NULL));
  for(i=0;i<n;i++){
    a[i]=rand()%MAX;
  }
  return a;
}
// Swap 2 Elements
void swapd(int a[],int i,int j){
  int tmp;
  tmp=a[i];
  a[i]=a[j];
  a[j]=tmp;
}
// Quicksort 2-way
void quicksort2(int arr[],int l,int r){
  if(l<r){
  int v = arr[r];
  int q = r-1;
  int p = l;
  while(1){
    while(p<=q && arr[p]<v){
      p ++;
    }
    while(q>=p && arr[q]>v){
      q --;
    }
    if(p >= q){ break;}
    swapd(arr,p,q);
    p++;
    q--;
  }
  swapd(arr,p,r);
  
    quicksort2(arr,l,p-1);
    quicksort2(arr,p+1,r);
  }
}
// Quicksort 3-way
void quicksort3(int arr[], int l, int r)
{
  //partition3
    if (r <= l)
        return;
    int i,j;
   i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = arr[r];
 
    while (1) {
        while (arr[++i] < v);
        while (v < arr[--j])
            if (j == l)
                break;
        if (i >= j)
            break;
        swapd(arr,i,j);
        if (arr[i] == v) {
            p++;
            swapd(arr,p, i);
        }

        if (arr[j] == v) {
            q--;
            swapd(arr,j, q);
        }
    }
    swapd(arr,i,r);
 
    j = i - 1;
    for (int k = l; k < p; k++, j--)
      swapd(arr,k,j);
 
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
      swapd(arr,i, k);
    
    quicksort3(arr, l, j);
    quicksort3(arr, i, r);
}
// qsort()
void qsort(void *buf, size_t num, size_t size, int (*compare)(void const *, void const *));
int int_compare(void const* x, void const *y) {
  int m, n;
  m = *((int*)x);
  n = *((int*)y);
  if ( m == n ) return 0;
  return m > n ? 1: -1;
}
// Print Array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d  ", a[i]);
    printf("\n");
}
//Copy data form An Array to Another
void memorycpy(int a[], int b[],int n){
  int i;
  for(i=0;i<n;i++){
    b[i]=a[i];
  }
}
int main(){
  int n;
  int *arr;
  int *brr,*crr;
  do{
  printf("Enter the number of elements in the array: ");
  scanf("%d%*c",&n);
  }while(n<0||n>MAX);
  arr=createArray(n);
  brr=createArray(n);
  crr=createArray(n);
  arr=dumpArray(arr,n);
  memorycpy(arr,brr,n);
  memorycpy(arr,crr,n);
  time_t start,end;
  double duration;
  // 
  start=clock();
  quicksort2(arr,0,n-1);
  end=clock();
  duration=(double)(-start+end)/CLOCKS_PER_SEC;
  printf("Quicksort2: \n");
  //printarr(arr,n);
  printf("\n-> the algorithm take %lf s.\n",duration);
  //
  start=clock();
  quicksort3(brr,0,n-1);
  end=clock();
  duration=(double)(-start+end)/CLOCKS_PER_SEC;
  printf("Quicksort3: \n");
  //printarr(brr,n);
  printf("\n-> the algorithm take %lf s.\n",duration);
  //
  start=clock();
  qsort(crr,n,sizeof(int),int_compare);
  end=clock();
  duration=(double)(-start+end)/CLOCKS_PER_SEC;
  printf("Qsort: \n");
  //printarr(crr,n);
  printf("\n-> the algorithm take %lf s.\n",duration);
  free(arr);
  free(brr);
  free(crr);
  return 0;
}
