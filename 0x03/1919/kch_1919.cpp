#include <iostream>
using namespace std;

int main(void)
{
    string a, b;
    int alphabetA[26] = {0}, alphabetB[26] = {0}, result = 0;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++) alphabetA[a[i] - 'a']++;
    for(int i = 0; i < b.length(); i++) alphabetB[b[i] - 'a']++;
    for(int i = 0; i < 26; i++)
    {
        if(alphabetA[i] != alphabetB[i]) result += abs(alphabetA[i] - alphabetB[i]);
    }
    cout << result;
}