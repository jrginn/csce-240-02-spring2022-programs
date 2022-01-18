//============================================================================
// Name        : practice.cpp
// Author      : Jackson Ginn
// Version     :
// Copyright   : Your copyright notice
// Description : Sorting in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int nums[], int num){
	//cout << arr[0] << endl;
	for(int i = 0; i < num; i++){
		cout << nums[i] << " ";
	}
	cout << endl;
}

void selectionSort(int arr[], int arrLength){
	for(int i = 0; i < arrLength - 1; i++){
		int minimumIndex = i;
		for(int j = i+1; j < arrLength; j++){
			if(arr[j] < arr[minimumIndex]){
				minimumIndex = j;
			}
		}
		swap(&arr[minimumIndex], &arr[i]);
	}
}

int main(){
	int foo[] = {3, 7, 8, 1, 9, 30000, -5};
	int fooLength = sizeof(foo) / sizeof(foo[0]);
	selectionSort(foo, fooLength);
	printArray(foo, fooLength);
}
