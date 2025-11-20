#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size, price, cnt = 0;
    vector<int> coin;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> size >> price;
    coin.resize(size);

    for (int i = 0; i < size; i++)
    {
        cin >> coin[i];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        if (price == 0)
        {
            break;
        }

        if (coin[i] <= price)
        {
            cnt += price / coin[i];
            price = price % coin[i];
        }
    }

    cout << cnt;
    cout.flush();
    
    return 0;
}