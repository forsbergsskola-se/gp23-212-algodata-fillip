#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
void swap(vector<T>& list, int index1, int index2)
{
    // Validate indices
    if (index1 < 0 || index1 >= list.size() || index2 < 0 || index2 >= list.size())
    {
        throw invalid_argument("Index out of range");
    }

    T temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

template<typename T>
void sortSelection(vector<T>& unsortedList)
{
    for (int i = 0; i < unsortedList.size() - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < unsortedList.size(); j++)
        {
            if (unsortedList[j] < unsortedList[min])
            {
                min = j;
              
            }
        }

        swap(unsortedList, i, min);
    }
}

template<typename T>
void bubbleSort(std::vector<T>& unsortedVector)
{
    int size = unsortedVector.size();

    for (int i = 0; i < size - 1; i++)  // Only need to iterate up to size - 1
    {
        bool isSwapped = false;

        for (int j = 0; j < size - i - 1; j++)  // Reduce the range each time
        {
            if (unsortedVector[j] > unsortedVector[j + 1])
            {
                std::swap(unsortedVector[j], unsortedVector[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped)  // If no elements were swapped, vector is sorted
            break;
    }
}

template<typename T>
void findMedian(vector<T>& list)
{
    SortSelection(list);

    int n = nums.size();

    if (n % 2 == 0)
    {
        return(nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
    else
    {
        return(num / 2);
    }

};

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
struct Tree
{
    right::Tree<T>;
    left::Tree <T>;
    value::T;
};







int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}


template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];  // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}




