//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int arr[100000];	//입력받을 문자열

int BinarySearch_reculsive(int arr[], int target, int first, int last) {
	if (first > last) return -1;
	//target이 존재하지 않으면 -1 return

	int mid = (first + last) / 2;	//중간 값 구하기
	if (target == arr[mid])
		return mid;		//target이 가장 중간 값이면 그대로 return
	else if (target < arr[mid])
		return BinarySearch_reculsive(arr, target, first, mid - 1);
		//target이 중간보다 앞에 있으면 first~mid-1로 범위를 재조정하고 재귀함수 호출
	else
		return BinarySearch_reculsive(arr, target, mid + 1, last);
		//target이 중간보다 뒤에 있으면 mid+1~last로 범위를 재조정하고 재귀함수 호출
}	//재귀함수를 이용한 이진탐색
int BinarySearch_repetitive(int arr[], int target, int first, int last) {
	int mid;

	while (first <= last) {
		//first가 last보다 커질 경우, 반복문 탈출
		mid = (first + last) / 2;	//중간 값 구하기

		if (target == arr[mid]) 
			return mid;		//target이 가장 중간 값이면 그대로 return
		else if (target < arr[mid])
			last = mid - 1;
			//target이 중간보다 앞에 있으면 first~mid-1로 범위를 재조정하고 다시 탐색
		else
			first = mid + 1;
			//target이 중간보다 뒤에 있으면 mid+1~last로 범위를 재조정하고 다시 탐색
	}
	return -1;	//target이 존재하지 않으면 -1 return
}	//while 반복문을 이용한 이진탐색

int main(void) {
	int n, target;
	scanf("%d", &n);	//입력 받을 배열의 크기
	for (int i = 0; i < n; i++) cin >> arr[i];

	scanf("%d", &target);	//찾을 인자

	//int result = BinarySearch_reculsive(arr, target, 0, n - 1);
	int result = BinarySearch_repetitive(arr, target, 0, n - 1);

	if (result == -1) printf("%s\n", "실패");
	else printf("%d\n", result+1);

	return 0;
}