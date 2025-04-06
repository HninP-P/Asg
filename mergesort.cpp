#include <iostream>
using namespace std;

//Merge function
void merge(int arr[], int l, int m, int r) //l = left, m = mid, r = right
{
    int i = l; //starting index for left subarray
    int j = m + 1; // starting index for right subarray
    int k = 0; // starting index for temporary

    int size = (r - l) + 1;
    int* temp = new int[size]; // Dynamically allocate memory for temp

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i]; //arr[i] is smaller than arr[j]
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j]; //arr[j] is smaller than arr[i]
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = arr[i]; //copying all elements from left subarray to temp as it is
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j]; //copying all elements from right subarray to temp as it is
        j++;
        k++;
    }
    for (int p = 0; p < size; p++) //copy temp back to arr
    {
        arr[l + p] = temp[p];
    }
    delete[] temp; // Release the dynamically allocated memory
}

//Mergesort function
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m); // left subarray
        mergeSort(arr, m + 1, r); // right subarray
        merge(arr, l, m, r);
    }
}
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " number of elements of the array: " << endl;
    int myarr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> myarr[i];
    }

    cout << "Before Merge Sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarr[i] << " ";
    }

    // Mergesort function

    mergeSort(myarr, 0, (size - 1));

    cout << endl << "After Merge Sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarr[i] << " ";
    }

    return 0;
}
