#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pp;
typedef pair<pp, int> p;

int main()
{
    int list[5000];
    int usado;

    vector<p> v;
    int N, Q;

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int pi, qi, ri;
        cin >> pi >> qi >> ri;

        v.push_back(make_pair(make_pair(pi, qi), ri));
    }

    // Output
    pair<int, int> question;
    int K, V;
    for (int i = 0; i < Q; i++)
    {
        int arr[5000] = {
            0,
        };
        cin >> K >> V;
        question = make_pair(K, V);

        for (int k = 0; k < v.size(); k++)
        {
            if (v[k].first.first == V)
            {
                arr[v[k].first.second] = v[k].second;
            }
            else if (v[k].first.second == V)
            {
                arr[v[k].first.first] = v[k].second;
            }
        }

        // for (int k = 1; k <= N - 1; k++)
        // {
            
        //     for (int q = 0; q < v.size(); q++)
        //     {
        //         if(find(v[q].first,k)==)
        //         int first, second;
        //         if (v[q].first.first == V || v[q].first.second == V)
        //             first = v[q].second;
        //             if(v[q].first.first==V && v[q].first.second == V)
        //     }
        // }

        for (int i = 1; i <= N; i++)
        {
            cout << "arr" << i << ": " << arr[i] << " ";
        }
        cout << '\n';
    }

    cout << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first.first << "," << v[i].first.second << ": " << v[i].second;
    }
    cout << '\n';
}