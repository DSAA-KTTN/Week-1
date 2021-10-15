#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2-way quick sort
int lastPartition1(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low;
    int j = high-1;
    while(1)
    {
        while(i <= j && a[i] < pivot) i++;
        while(i <= j && a[i] > pivot) j--;
        if (i >= j) break;
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
    swap(&a[i], &a[high]);
    return i;
}

void quickSort1(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot;
        pivot = lastPartition1(a, low, high);

        quickSort1(a, low, pivot-1);
        quickSort1(a, pivot+1, high);
    }
}
// 2-way quick sort

// 3-way quick sort
    void quickSort2(int a[], int low, int high) {
	if (high <= low) return;
	int i = low-1, j = high;
	int p = low-1, q = high;
	int k;
	while(1)	{
		while (a[++i] < a[high]);
		while (a[high] < a[--j]) 
            if (j == low) break;
		if (i >= j) break;

		swap(&a[i],&a[j]);
		if (a[i]==a[high]) swap(&a[++p],&a[i]);
		if (a[j]==a[high]) swap(&a[--q],&a[j]);
	}

	swap(&a[i],&a[high]);
	j = i - 1;
	i = i + 1;
	
	for (k = low ; k <= p; k++) swap(&a[k],&a[j--]);		
	for (k = high-1; k >= q; k--) swap(&a[k],&a[i++]);
	
	quickSort2(a, low, j);
	quickSort2(a, i, high);
}
// 3-way quick sort

// create array
int *createArray(int n)
{
    int *newArray = (int*)malloc(n*sizeof(int));
    srand(time(NULL));

    int i;
    for(i = 0; i < n; i++)
        *(newArray+i) = rand() % 10;
    
    return newArray;
}
// create array

// dumb array
int *dumbArray(int *a, int n)
{
    int *copyArray = (int*)malloc(n*sizeof(int));
    memcpy(copyArray, a, n*sizeof(int));
    return copyArray;
}
// dumb array

int main()
{
    int n = 10000000;
    int *a, *b;

    a = createArray(n);
    b = dumbArray(a, n);

    // 2-way quick sort
    double start_1 = clock();
    quickSort1(a, 0, n);
    double end_1 = clock();

    double time_1 = (double)(end_1-start_1) / CLOCKS_PER_SEC;

    printf("2-way quick sort: %lf seconds\n", time_1);
    // 2-way quick sort

    // 3-way quick sort
    double start_2 = clock();
    quickSort2(a, 0, n);
    double end_2 = clock();

    double time_2 = (double)(end_2-start_2) / CLOCKS_PER_SEC;

    printf("3-way quick sort: %lf seconds\n", time_2);
    // 3-way quick sort
}