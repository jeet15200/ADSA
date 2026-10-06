#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int main() {
    int n;

    cout << "Enter number of files: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter file sizes: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int t = 0, sum = 0;

    for (int x : a) {
        t += x;
        sum += t;
    }

    cout << "Files in ascending order: ";
    for (int x : a)
        cout << x << " ";

    cout << "\nMean Retrieval Time (MRT): "
         << fixed << setprecision(2) << (double)sum / n;

    return 0;
}

// //OUTPUT:
// Enter number of files: 10
// Enter file sizes: 8 9 2 8 2 8 3 3 3 6
// Files in ascending order: 2 2 3 3 3 6 8 8 8 9 
// Mean Retrieval Time (MRT): 21.20
