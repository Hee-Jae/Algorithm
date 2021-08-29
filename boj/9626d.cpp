#include <iostream>
#include <cstring>
#include <string>

#include <vector>

using namespace std;

int main()
{
    int M, N, U, L, R, D;
    char odd = '#';
    char even = '.';
    int line = 1;
    char arr[1000];
    char puzzle[1000];

    cin >> M >> N;
    cin >> U >> L >> R >> D;
    char word;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> word;
            puzzle[(i * M) + j] = word;
        }
    }

    for (int i = 0; i < M + U + D; i++)
    {
        for (int j = 0; j < L + N + R; j++)
        {
            if (line % 2 != 0)
            {
                if (j % 2 == 0)
                {
                    arr[i * (L + N + R) + j] = odd;
                }
                else
                {
                    arr[i * (L + N + R) + j] = even;
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    arr[i * (L + N + R) + j] = even;
                }
                else
                {
                    arr[i * (L + N + R) + j] = odd;
                }
            }
        }
        line++;
    }

    int idx = 0;
    int add = L + R;
    int start = U * (L + R + N) + L;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[start + ((add + N) * i) + j] = puzzle[idx];
            idx++;
        }
    }

    for (int i = 0; i < M + U + D; i++)
    {
        for (int j = 0; j < L + N + R; j++)
        {
            cout << arr[j + i * (L + N + R)];
        }
        cout << '\n';
    }
}