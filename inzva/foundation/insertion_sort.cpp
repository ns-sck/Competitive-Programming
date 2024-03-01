#include <iostream>
using namespace std;

int main ()
{
    int temp = -1;
    int arr[10] = {5,6,8,4,3,7,9,2,1,0};
    for (int i = 1; i < 10; ++i) {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {

            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = temp;
        
    }

    for (auto& i : arr) {
        cout << i << ' '; 
    } 

    return 0;
}