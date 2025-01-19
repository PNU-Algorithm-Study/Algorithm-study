#include <iostream>
using namespace std;

char str[100000 + 10];

void InputData(){
	cin >> str;
}

int countnum(){
    int open=0;
    int count=0;
    for(int i = 0; str[i]!= '\0'; i++){
        //레이저인지 검사
        if(str[i]=='(' and str[i+1]==')'){
            count=count+open;
            i++;
        } else if (str[i]=='('){
            open++;
        } else if (str[i]==')'){
            count++;
            open--;
        }
    }
    return count;
}

int main() {
	int ans;
	InputData();
	ans = countnum();
	
	cout << ans << endl;
	return 0;
}
