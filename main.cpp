#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;

// 1. Максимальна кількість повторень одиниці
int findMaxConsecutiveOnes(int nums[], int n) {
    int current = 0;
    int maximum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            current++;
            if (current > maximum) {
                maximum = current;
            }
        } else {
            current = 0;
        }
    }

    return maximum;
}

// 2. Кількість чисел із парною кількістю цифр
int findNumbers(int nums[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        int number = nums[i];
        int digits = 0;

        do {
            digits++;
            number /= 10;
        } while (number != 0);

        if (digits % 2 == 0) {
            result++;
        }
    }

    return result;
}

// 3. Квадрати відсортованого масиву
void sortedSquares(int nums[], int n, int result[]) {
    int left = 0;
    int right = n - 1;
    int position = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[position] = leftSquare;
            left++;
        } else {
            result[position] = rightSquare;
            right--;
        }
        position--;
    }
}

// 4. Подвійні нулі
void duplicateZeros(int arr[], int n) {
    int temp[MAX_SIZE];
    int position = 0;

    for (int i = 0; i < n && position < n; i++) {
        temp[position] = arr[i];
        position++;

        if (arr[i] == 0 && position < n) {
            temp[position] = 0;
            position++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// 5. Об'єднання двох відсортованих масивів
void mergeArrays(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}

// 6. Видалення дублікатів із відсортованого масиву
int removeDuplicates(int nums[], int n) {
    if (n == 0) {
        return 0;
    }

    int uniqueCount = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[uniqueCount - 1]) {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
}

// 7. Перевірка, чи існує число та його подвійник
bool checkIfExist(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == 2 * arr[j]) {
                return true;
            }
        }
    }

    return false;
}

// 8. Перевірка дійсного гірського масиву
bool validMountainArray(int arr[], int n) {
    if (n < 3) {
        return false;
    }

    int i = 0;

    while (i + 1 < n && arr[i] < arr[i + 1]) {
        i++;
    }

    if (i == 0 || i == n - 1) {
        return false;
    }

    while (i + 1 < n && arr[i] > arr[i + 1]) {
        i++;
    }

    return i == n - 1;
}

// 9. Заміна елементів найбільшим елементом праворуч
void replaceElements(int arr[], int n) {
    int maxRight = -1;

    for (int i = n - 1; i >= 0; i--) {
        int current = arr[i];
        arr[i] = maxRight;

        if (current > maxRight) {
            maxRight = current;
        }
    }
}

// 10. Сортування масиву за парністю
void sortArrayByParity(int nums[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (nums[left] % 2 == 0) {
            left++;
        } else if (nums[right] % 2 != 0) {
            right--;
        } else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}

void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    setlocale(LC_ALL, "uk_UA");

    cout << "Лабораторна робота: Масиви" << endl;
    cout << "Оберіть завдання від 1 до 10:" << endl;
    cout << "1 - Максимальна кількість одиниць" << endl;
    cout << "2 - Числа з парною кількістю цифр" << endl;
    cout << "3 - Квадрати відсортованого масиву" << endl;
    cout << "4 - Подвійні нулі" << endl;
    cout << "5 - Об'єднання відсортованих масивів" << endl;
    cout << "6 - Видалення дублікатів" << endl;
    cout << "7 - Число та його подвійник" << endl;
    cout << "8 - Дійсний гірський масив" << endl;
    cout << "9 - Найбільший елемент праворуч" << endl;
    cout << "10 - Сортування за парністю" << endl;
    cout << "Ваш вибір: ";

    int task;
    if (!(cin >> task)) {
        cout << "Помилка введення." << endl;
        return 1;
    }

    if (task < 1 || task > 10) {
        cout << "Немає завдання з таким номером." << endl;
        return 1;
    }

    int nums[MAX_SIZE];
    int nums2[MAX_SIZE];
    int result[MAX_SIZE];
    int n, m;

    switch (task) {
        case 1:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть елементи (0 або 1): ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            cout << "Максимальна кількість одиниць підряд: "
                 << findMaxConsecutiveOnes(nums, n) << endl;
            break;

        case 2:
            cout << "Введіть кількість чисел: ";
            cin >> n;
            cout << "Введіть числа: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            cout << "Кількість чисел із парною кількістю цифр: "
                 << findNumbers(nums, n) << endl;
            break;

        case 3:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть відсортовані числа: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            sortedSquares(nums, n, result);
            cout << "Квадрати у відсортованому порядку: ";
            printArray(result, n);
            break;

        case 4:
            cout << "Введіть довжину масиву: ";
            cin >> n;
            cout << "Введіть елементи масиву: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            duplicateZeros(nums, n);
            cout << "Результат: ";
            printArray(nums, n);
            break;

        case 5:
            cout << "Введіть m і n: ";
            cin >> m >> n;
            cout << "Введіть перші m елементів nums1: ";
            for (int i = 0; i < m; i++) cin >> nums[i];
            for (int i = m; i < m + n; i++) nums[i] = 0;
            cout << "Введіть n елементів nums2: ";
            for (int i = 0; i < n; i++) cin >> nums2[i];
            mergeArrays(nums, m, nums2, n);
            cout << "Об'єднаний масив: ";
            printArray(nums, m + n);
            break;

        case 6: {
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть відсортовані числа: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            int k = removeDuplicates(nums, n);
            cout << "Кількість унікальних елементів: " << k << endl;
            cout << "Перші k елементів: ";
            printArray(nums, k);
            break;
        }

        case 7:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть числа: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            if (checkIfExist(nums, n)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
            break;

        case 8:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть елементи масиву: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            if (validMountainArray(nums, n)) {
                cout << "true: це дійсний гірський масив." << endl;
            } else {
                cout << "false: це не дійсний гірський масив." << endl;
            }
            break;

        case 9:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть елементи масиву: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            replaceElements(nums, n);
            cout << "Результат: ";
            printArray(nums, n);
            break;

        case 10:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            cout << "Введіть числа: ";
            for (int i = 0; i < n; i++) cin >> nums[i];
            sortArrayByParity(nums, n);
            cout << "Масив після сортування за парністю: ";
            printArray(nums, n);
            break;
    }

    return 0;
}
