#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
int a[maxn];
int cnt;
int n;

void Qsort(int A[], int Left, int Right) {
    int Pivot, Low, High;
    cnt++;
    if (Left < Right) {
        Pivot = A[Left];
        Low = Left;
        High = Right;

        while (1) {
            // 从左向右找第一个大于等于基准的元素
            while (Low < High && A[Low] < Pivot) {
                Low++;
            }
            // 从右向左找第一个小于等于基准的元素
            while (Low < High && A[High] > Pivot) {
                High--;
            }
            if (Low >= High) break;
            swap(A[Low], A[High]);
        }

        // 放置基准值到正确位置
        if (Low > High) {
            swap(A[Left], A[High]);
        } else {
            swap(A[Left], A[Low]);
        }

        Qsort(A, Left, High - 1);
        Qsort(A, High + 1, Right);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Qsort(a, 0, n - 1);
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}