#include <iostream>
#include <thread>

struct IndexValue {
	int index;
	int value;
};

void SelectionSort(int array[], int elementsCount, int elementToSortFrom = 0);
IndexValue FindMin(int array[], int elementsCount, int elementToStartFrom = 0);
void PrintArray(int array[], int elementsCount);

// Showoff.
void PrintAnimated(std::string text, bool shouldEndLine = true, int afterSleep = 500, int perCharSleep = 40);
void Sleep(int milliseconds);

int main()
{
	// Create and fill array.
	PrintAnimated("How many elements would you like to sort?");
	PrintAnimated("Elements count: ", false);
	int elementsCount;
	std::cin >> elementsCount;

	int elements[elementsCount];
	for (int i = 0; i < elementsCount; i++) {
		PrintAnimated("Enter the " + std::to_string(i) + " element's value: ", false, 500, 20);
		std::cin >> elements[i];
	}

	// Show initial array state.
	PrintAnimated("The initial array values order  is: ", false);
	PrintArray(elements, elementsCount);

	// Sort.
	SelectionSort(elements, elementsCount);

	// Show sorted array state.
	PrintAnimated("The sorted array values order is: ", false);
	PrintArray(elements, elementsCount);

	return 0;
}

void SelectionSort(int array[], int elementsCount, int elementToSortFrom) {
	IndexValue min = FindMin(array, elementsCount, elementToSortFrom);
	
	// Switch smallest and first elements.
	int firstElement = array[elementToSortFrom];
	array[elementToSortFrom] = min.value;
	array[min.index] = firstElement;

	if (elementsCount - 1 > elementToSortFrom) {
		SelectionSort(array, elementsCount, ++elementToSortFrom);
	}
}

IndexValue FindMin(int array[], int elementsCount, int elementToStartFrom) {
	IndexValue min;
	min.value = INT_MAX;
	for (int i = elementToStartFrom; i < elementsCount; i++) {
		if (array[i] < min.value) {
			min.value = array[i];
			min.index = i;
		}
	}
	return min;
}

void PrintArray(int array[], int elementsCount) {
	for (int i = 0; i < elementsCount; i++) {
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;
}

// Showoff.
void PrintAnimated(std::string text, bool shouldEndLine, int afterSleep, int perCharSleep) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text[i] << std::flush;
		Sleep(perCharSleep);
	}
	Sleep(afterSleep);
	if (shouldEndLine) std::cout << std::endl;
}

void Sleep(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
