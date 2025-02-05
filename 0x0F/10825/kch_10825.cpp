#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct STU{
    string name;
    int kor, eng, math;
};

bool cmp(STU s1, STU s2)
{
    if(s1.kor == s2.kor && s1.eng == s2.eng && s1.math == s2.math) return s1.name < s2.name;
    else if(s1.kor == s2.kor && s1.eng == s2.eng) return s1.math > s2.math;
    else if(s1.kor == s2.kor) return s1.eng < s2.eng;
    else return s1.kor > s2.kor;
}

int main(void)
{
    int n;
    cin >> n;
    vector<STU> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) cout << v[i].name << '\n';
}
