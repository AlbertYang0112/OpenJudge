#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<float> input(n);
	for(int i = 0; i < n; i++)
	  cin >> input[i];

	vector<float> lengthL(n, 0), lengthR(n, 0);

	lengthL[0] = 1;
	lengthR[n - 1] = 1;

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
		    //cout << "Visit L(" << i << ' ' << j;
		    //cout << ") R:("<< n - i - 1 << ' ' << n - j - 1 << ")" <<endl;
			if(input[j] < input[i] && lengthL[j] > lengthL[i])
                lengthL[i] = lengthL[j];
            if(input[n - j - 1] < input[n - i - 1] && lengthR[n - j - 1] > lengthR[n - i - 1])
                lengthR[n - i - 1] = lengthR[n - j - 1];
		}
		lengthL[i]++;
		lengthR[n - i - 1]++;
	}
	int maxLength = 0;
	for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(lengthL[i] + lengthR[j] > maxLength)maxLength = lengthL[i] + lengthR[j];
        }
        if(lengthL[i] + lengthR[i] - 1 >maxLength)maxLength = lengthL[i] + lengthR[i];
    }
    cout << n - maxLength << endl;
}

