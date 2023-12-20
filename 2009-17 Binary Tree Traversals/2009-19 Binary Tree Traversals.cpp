#include <iostream>
using namespace std;

int search(char arr[], char x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printPostOrder(char in[], char pre[], int n)
{
    int root = search(in, pre[0], n);
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    cout << pre[0] << ' ';
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {

        int n;
        cin >> n;
        char *pre = new char[n];
        char *in = new char[n];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        printPostOrder(in, pre, n);
        puts("");
    }

    return 0;

    return 0;
}