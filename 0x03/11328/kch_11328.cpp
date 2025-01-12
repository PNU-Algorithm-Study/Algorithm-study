#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while(n > 0)
    {
        string a, b;
        int result = 0, alphabetA[26] = {0}, alphabetB[26] = {0};
        cin >> a >> b;
        for(int i = 0; i < a.length(); i++) alphabetA[a[i] - 'a']++;
        for(int i = 0; i < b.length(); i++) alphabetB[b[i] - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            if(alphabetA[i] != alphabetB[i]) break;
            else result++;
        }
        if(result < 26) cout << "Impossible" << endl;
        else cout << "Possible" << endl;
        n--;
    }
}