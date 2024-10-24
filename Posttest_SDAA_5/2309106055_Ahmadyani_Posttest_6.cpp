#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int fibonacciSearch(int arr[], int x, int n)
{
    int fibMMm2 = 0;  
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1;  

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }

    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

// Jump Search untuk integer
int jumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

// Boyer-Moore untuk string
int boyerMooreSearch(string text, string pattern)
{
    int m = pattern.length();
    int n = text.length();

    int badChar[256];
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;

    int s = 0;  // shift
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            return s;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        }
        else
            s += max(1, j - badChar[text[s + j]]);
    }

    return -1;
}

// Fungsi lainnya tetap sama
int length(Node *head)
{
    int panjang = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        panjang++;
    }
    return panjang;
}

int linkedList2Array(Node *head, int *arr)
{
    int panjang = length(head);
    for (int i = 0; i < panjang; i++)
    {
        arr[i] = head->data;
        head = head->next;
    }
    return 0;
}

int array2LinkedList(Node *head, int *arr)
{
    int panjang = length(head);
    for (int i = 0; i < panjang; i++)
    {
        head->data = arr[i];
        head = head->next;
    }
    return 0;
}

// Shell Sort (descending)
int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

// Quick Sort (ascending)
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void menu()
{
    cout << "===== Menu =====" << endl;
    cout << "1. Tampilkan Linked List" << endl;
    cout << "2. Shell Sort (Descending)" << endl;
    cout << "3. Quick Sort (Ascending)" << endl;
    cout << "4. Fibonacci Search" << endl;
    cout << "5. Jump Search" << endl;
    cout << "6. Boyer-Moore Search" << endl;
    cout << "7. Keluar" << endl;
    cout << "================" << endl;
}

int main()
{
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node5 = new Node;

    node1->data = 2;
    node2->data = 1;
    node3->data = 4;
    node4->data = 3;
    node5->data = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    Node *HEAD = node1;
    int arr[length(HEAD)];
    linkedList2Array(HEAD, arr);

    int choice, searchValue;
    string text, pattern;

    do
    {
        menu();
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Linked List: ";
            display(HEAD);
            break;
        case 2:
            cout << "Sebelum disorting (Descending): ";
            display(HEAD);
            shellSort(arr, length(HEAD));
            array2LinkedList(HEAD, arr);
            cout << "Setelah disorting (Descending): ";
            display(HEAD);
            break;
        case 3:
            cout << "Sebelum disorting (Ascending): ";
            display(HEAD);
            quickSort(arr, 0, length(HEAD) - 1);
            array2LinkedList(HEAD, arr);
            cout << "Setelah disorting (Ascending): ";
            display(HEAD);
            break;
        case 4:
            cout << "Masukkan nilai yang ingin dicari dengan Fibonacci Search: ";
            cin >> searchValue;
            quickSort(arr, 0, length(HEAD) - 1); // Sorting sebelum searching
            if (fibonacciSearch(arr, searchValue, length(HEAD)) != -1)
                cout << "Data ditemukan!" << endl;
            else
                cout << "Data tidak ditemukan!" << endl;
            break;
        case 5:
            cout << "Masukkan nilai yang ingin dicari dengan Jump Search: ";
            cin >> searchValue;
            quickSort(arr, 0, length(HEAD) - 1); // Sorting sebelum searching
            if (jumpSearch(arr, searchValue, length(HEAD)) != -1)
                cout << "Data ditemukan!" << endl;
            else
                cout << "Data tidak ditemukan!" << endl;
            break;
        case 6:
            cout << "Masukkan teks: ";
            cin.ignore();
            getline(cin, text);
            cout << "Masukkan pola yang ingin dicari: ";
            getline(cin, pattern);
            if (boyerMooreSearch(text, pattern) != -1)
                cout << "Pola ditemukan!" << endl;
            else
                cout << "Pola tidak ditemukan!" << endl;
            break;
        case 7:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (choice != 7);

    return 0;
}
