#include <iostream>
using namespace std;


void reverseArray(int arr[],int size) {
    int temp;
    for(int i = 0;i<size/2;i++) {
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
    for(int j = 0;j<size;j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
    
    return;
    
}
int main() {
    
    int t;
    cin >> t;
    int size;
    while(t--) {
        cin >> size;
        int arr[size];
        for(int i = 0;i<size;i++) {
            cin >> arr[i];
        }
        
        reverseArray(arr,size);
    }
	//code
	return 0;
}