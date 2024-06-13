#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Заповнити масив випадковими числами від 1 до 10
template <typename T>
void randArray(T arr[], int size, int a = 1, int b = 10){
	for (int i = 0; i < size; i++)	{
		arr[i] = rand() % (b - a + 1) + a;
	}
}

//Виведення масиву на екран
template <typename T>
void printArray(T arr[], int size, int w_cout = 5){
	for (int i = 0; i < size; i++)	{
		cout.width(w_cout);
		cout << arr[i];
	}
	cout << endl;
}

template<typename T>
void addItemBack(T*& arr, int& size, T value)
{
	T*tmp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = value;
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = tmp;
	size ++;
}
template<typename T>
void addItemFront(T*& arr, int& size, T value) 
{
	T* tmp = new T[size + 1];
	for (int i = 0; i < size+1; i++)
	{
		tmp[i] = arr[i-1];
	}
	tmp[0] = value;
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = tmp;
	size++;
}
template<typename T>
void delItem(T*& arr, int& size, int k)
{
	T* tmp = new T[size - 1];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i!=k)
		{
			tmp[j] = arr[i];
			j++;
		}
	}
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = tmp;
	size--;
}
template <typename T>
void my_sort(T* arr, int size, bool (*cmp)(T, T)) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}