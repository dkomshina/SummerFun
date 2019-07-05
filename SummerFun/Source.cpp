/*
 * Учебная практика 2019
 * Комшина Дарья Олеговна БПИ184
 * CLion
 * Сделаны все сортировки, подсчет операций, вывод в файл *.csv,
 * генерация необходимых массивов, графики нарисованы в Excel.
 */
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

/**
 * Bubble sort
 * @param arr - array for sorting
 * @param n - array length
 */
void bubbleSort(unsigned int *arr, int n) {
	int iterations = 3; //i = 0, i < n - 1
	for (int i = 0; i < n - 1; i++) {
		iterations += 4; //i < n - 1, i++
		iterations += 4; //j = 0, j < n - i - 1
		for (int j = 0; j < n - i - 1; j++) {
			iterations += 5; //i < n - i - 1; j++
			iterations += 4; //arr[j] > arr[j + 1]
			if (arr[j] > arr[j + 1]) {
				iterations += 9; //swap
				swap(arr[j + 1], arr[j]);
			}
		}
	}
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

/**
 * Bubble sort with first Iversion condition
 * @param arr - array for sorting
 * @param n - array length
 */
void bubbleIversionSort1(unsigned int *arr, int n) {
	int iterations = 1; //swapped = true
	bool swapped = true;
	iterations += 4; //i = 0, swapped && i < n - 1
	for (int i = 0; swapped && i < n - 1; i++) {
		iterations += 5; //swapped && i < n - 1, i++
		iterations += 1; //swapped = false
		swapped = false;
		iterations += 4; //j = 0, j < n - i - 1
		for (int j = 0; j < n - i - 1; j++) {
			iterations += 5; //j < n - i - 1, j++
			iterations += 4; //arr[j] > arr[j + 1]
			if (arr[j] > arr[j + 1]) {
				iterations += 9; //swap
				swap(arr[j + 1], arr[j]);
				iterations += 1; //swapped = true
				swapped = true;
			}
		}
	}
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

/**
 * Bubble sort with second Iversion condition
 * @param arr - array for sorting
 * @param n - array length
 */
void bubbleIversionSort2(unsigned int *arr, int n) {
	int iterations = 1; //t = 0
	int t = 0;
	iterations += 3; //bound = n - 1, bound > 0
	for (int bound = n - 1; bound > 0; bound = t) {
		iterations += 2; //bound > 0, bound = t
		iterations += 1; //t = 0
		t = 0;
		iterations += 2; //i = 0, i < bound
		for (int i = 0; i < bound; i++) {
			iterations += 3; //i < bound, i++
			iterations += 4; //arr[i] > arr[i + 1]
			if (arr[i] > arr[i + 1]) {
				iterations += 9; //swap
				swap(arr[i + 1], arr[i]);
				iterations += 1; //t = i
				t = i;
			}
		}
	}
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

/**
 * Insertion Sort
 * @param arr - array for sorting
 * @param n - array length
 */
void insertionSort(unsigned int *arr, int n) {
	int iterations = 2; //i = 1, i < n
	for (int i = 1; i < n; i++) {
		iterations += 3; //i < n, i++
		iterations += 7; //j = i, j > 0 && arr[j] < arr[j - 1]
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			iterations += 8; //j > 0 && arr[j] < arr[j - 1], j--
			iterations += 9; //swap
			swap(arr[j], arr[j - 1]);
		}
	}
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

/**
 * Binary insertion sort
 * @param arr - array for sorting
 * @param n - array length
 */
void insertionBinarySort(unsigned int *arr, int n) {
	int iterations = 2; //i = 1, i < n
	for (int i = 1; i < n; i++) {
		iterations += 3; //i < n; i++
		iterations += 7; //l, r, c
		int l = 0, r = i - 1;
		int c = (l + r) / 2;
		iterations += 1; //l != c
		while (l != c) {
			iterations += 1; //l != c;
			iterations += 3; //arr[c] > arr[i]
			if (arr[c] > arr[i]) {
				iterations += 2; //r = c - 1
				r = c - 1;
			}
			else {
				iterations += 1; //l = c
				l = c;
			}
			iterations += 4; //c = (l + r) / 2
			c = (l + r) / 2;
		}
		iterations += 3; //arr[l] < arr[i]
		if (arr[l] < arr[i]) {
			iterations += 3; // arr[i] > arr[r]
			if (arr[i] > arr[r]) {
				iterations += 2; // l = r + 1
				l = r + 1;
			}
			else {
				iterations += 1; // l = r
				l = r;
			}
		}
		iterations += 2; //p = arr[i]
		unsigned int p = arr[i];
		iterations += 2; // k = i, k > l
		for (int k = i; k > l; k--) {
			iterations += 3; //k > l, k--
			iterations += 3; //arr[k] = arr[k - 1]
			arr[k] = arr[k - 1];
		}
		iterations += 2; //arr[l] = p
		arr[l] = p;
	}
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

/**
 * Counting sort
 * @param arr - array for sorting
 * @param n - array length
 */
void countingSort(unsigned int *arr, int n) {
	int iterations = 2; //max = arr[0]
	unsigned int max = arr[0];
	iterations += 2; //i = 1, i < n
	for (int i = 1; i < n; i++) {
		iterations += 3; //i < n, i++
		iterations += 2; //arr[i] > max
		if (arr[i] > max) {
			iterations += 2; //max = arr[i]
			max = arr[i];
		}
	}
	iterations += 2; //*c = new int[max + 1]
	int *c = new int[max + 1];
	iterations += 3; //i = 0, i < max + 1
	for (unsigned int i = 0; i < max + 1; i++) {
		iterations += 4; //i < max + 1, i++
		iterations += 2; // c[i] = 0
		c[i] = 0;
	}
	iterations += 2; //i = 0, i < n
	for (int i = 0; i < n; i++) {
		iterations += 3; //i < n, i++
		iterations += 6; //c[arr[i]]++
		c[arr[i]]++;
	}
	iterations += 3; //i = 1, i < max + 1
	for (unsigned int i = 1; i < max + 1; i++) {
		iterations += 4; //i < max + 1, i++
		iterations += 6; //c[i] = c[i] + c[i - 1]
		c[i] += c[i - 1];
	}
	iterations += 1; //*b = new int[n]
	auto *b = new unsigned int[n];
	iterations += 3; //i = n - 1, i >= 0
	for (int i = n - 1; i >= 0; i--) {
		iterations += 3; //i >= 0, i--
		iterations += 6; //b[c[arr[i]] - 1] = arr[i]
		b[c[arr[i]] - 1] = arr[i];
		iterations += 4; //c[arr[i]]--
		c[arr[i]]--;
	}
	iterations += 2; //i = 0, i < n
	for (int i = 0; i < n; i++) {
		iterations += 3; //i < n, i++
		iterations += 3; //arr[i] = b[i]
		arr[i] = b[i];
	}
	delete[] c;
	delete[] b;
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

union rad {
	unsigned int number;
	unsigned char digit[4];
};

/**
 * Radix sort
 * @param arr - array for sorting
 * @param n - array length
 */
void radixSort(unsigned int *arr, int n) {
	int iterations = 1; //rad *array = new rad[n]
	rad *array = new rad[n];
	iterations += 2; //i = 0, i < n
	for (int i = 0; i < n; i++) {
		iterations += 3; //i < n, i++
		iterations += 3; // array[i].number = arr[i]
		array[i].number = arr[i];
	}
	iterations += 2; //k = 0, k < 4
	for (int k = 0; k < 4; k++) {
		iterations += 3; //k < 4, k++
		unsigned int max = array[0].digit[k];
		iterations += 2; //i = 1, i < n
		for (int i = 1; i < n; i++) {
			iterations += 3; //i < n, i++
			iterations += 3; //array[i].digit[k] > max
			if (array[i].digit[k] > max) {
				iterations += 3; //max = array[i].digit[k]
				max = array[i].digit[k];
			}
		}
		iterations += 2; //*c = new int[max + 1]
		int *c = new int[max + 1];
		iterations += 3; //i = 0, i < max + 1
		for (unsigned int i = 0; i < max + 1; i++) {
			iterations += 4; //i < max + 1, i++
			iterations += 2; //c[i] = 0
			c[i] = 0;
		}
		iterations += 2; //i = 0, i < n
		for (int i = 0; i < n; i++) {
			iterations += 3; //i < n, i++
			iterations += 8; //c[array[i].digit[k]] = c[array[i].digit[k]] + 1
			c[array[i].digit[k]]++;
		}
		iterations += 3; //i = 1, i < max + 1
		for (unsigned int i = 1; i < max + 1; i++) {
			iterations += 4; //i < max + 1, i++
			iterations += 6; //c[i] = c[i] + c[i - 1]
			c[i] += c[i - 1];
		}
		iterations += 1; //int *b = new int[n];
		auto b = new unsigned int[n];
		iterations += 3; //i = n - 1, i >= 0
		for (int i = n - 1; i >= 0; i--) {
			iterations += 3; //i >= 0, i--
			iterations += 7; //b[c[array[i].digit[k]] - 1] = array[i].number
			b[c[array[i].digit[k]] - 1] = array[i].number;
			iterations += 7; //c[array[i].digit[k]] = c[array[i].digit[k]] - 1
			c[array[i].digit[k]]--;
		}
		iterations += 2; //i = 0, i < n
		for (int i = 0; i < n; i++) {
			iterations += 3; //i < n, i++
			iterations += 3; //array[i].number = b[i]
			array[i].number = b[i];
		}
		delete[] c;
		delete[] b;
	}
	iterations += 2; //i = 0, i < n
	for (int i = 0; i < n; i++) {
		iterations += 3; //i < n, i++
		iterations += 3; //arr[i] = array[i].number;
		arr[i] = array[i].number;
	}
	delete[] array;
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName, ios::app);
	fs << iterations << ";";
	fs.close();
}

/**
 * Generates 4 arrays from the task
 * @return reference on the array
 */
unsigned int **generateArrays() {
	const int numberOfArrays = 4;
	const int arrayLength = 8000;
	auto **defaultArrays = new unsigned int *[numberOfArrays];
	for (int n = 0; n < numberOfArrays; ++n) {
		defaultArrays[n] = new unsigned int[arrayLength];
	}
	random_device randomDevice;
	default_random_engine generator(randomDevice());
	uniform_int_distribution<int> distribution1(0, 9);
	for (int i = 0; i < arrayLength; ++i) {
		defaultArrays[0][i] = static_cast<unsigned int>(distribution1(generator));
	}
	uniform_int_distribution<int> distribution2(0, 10000);
	for (int j = 0; j < arrayLength; ++j) {
		defaultArrays[1][j] = static_cast<unsigned int>(distribution2(generator));
	}
	for (int k = 0; k < arrayLength; ++k) {
		defaultArrays[2][k] = static_cast<unsigned int>(k + 1);
	}
	uniform_int_distribution<int> distribution3(0, 7999);
	for (int l = 0; l < 30; ++l) {
		swap(defaultArrays[2][distribution3(generator)], defaultArrays[2][distribution3(generator)]);
	}
	for (int m = 0; m < arrayLength; ++m) {
		defaultArrays[3][m] = static_cast<unsigned int>(arrayLength - m + 1);
	}
	return defaultArrays;
}

/**
 * Writes the heading if CSV file
 */
void writeHeadingToCSV() {
	ofstream fs;
	string fileName = "../BigProject.csv";
	fs.open(fileName);
	fs << "Array Length;";
	string name[7] = { "Bubble ", "Iversion1 ", "Iversion2 ",
					  "Insertion ", "Insertion Binary ",
					  "Counting ", "Radix " };
	string length[4] = { "(0-9);", "(0-10000);", "(Almost Sorted);", "(Reversed Sorted);" };
	for (auto &i : name) {
		for (auto &j : length) {
			fs << i.c_str() << j.c_str();
		}
	}
	fs << endl;
	fs.close();
}

/*bool isArraySorted(unsigned int *array, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (array[i] > array[i + 1]) {
			cout << "It is not sorted";
		}
	}

	return true;
}*/

/**
 * Writes the body of CSV file
 */
void writeBodyToCsv() {
	void(*delegate[7])(unsigned int *, int) =
	{ bubbleSort, bubbleIversionSort1, bubbleIversionSort2,
	 insertionSort, insertionBinarySort,
	 countingSort, radixSort };
	unsigned int **arrays = generateArrays();
	ofstream fs;
	string fileName = "../BigProject.csv";
	for (int i = 1000; i <= 8000; i += 1000) {
		fs.open(fileName, ios::app);
		fs << i << ";";
		fs.close();
		for (auto &j : delegate) {
			auto **array = new unsigned int *[4];
			for (int m = 0; m < 4; ++m) {
				array[m] = new unsigned int[i];
			}
			for (int k = 0; k < 4; ++k) {
				for (int l = 0; l < i; ++l) {
					array[k][l] = arrays[k][l];
				}
				j(array[k], i);
				//isArraySorted(array[k], i);
			}
			for (int m = 0; m < 4; ++m) {
				delete[] array[m];
			}
			delete[] array;
		}
		fs.open(fileName, ios::app);
		fs << endl;
		fs.close();
	}

	for (int i = 0; i < 4; ++i) {
		delete[] arrays[i];
	}
	delete[] arrays;
}

/**
 * I don't know what is wrong with me
 */
void writeToCSW() {
	writeHeadingToCSV();
	writeBodyToCsv();
}

/**
 * It is main
 * @return it should return 0 but it don't
 */
int main() {
	writeToCSW();
	return 0;
}