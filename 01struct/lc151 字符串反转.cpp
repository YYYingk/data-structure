#include<iostream>
#include<string>

using namespace std;
int n;
string st;
void swapse(string& s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

string reverseWords(string s)
{
    int start = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if (i == s.size() || s[i] == ' ')
        {
            swapse(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}

int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        getline(cin, st);
        string sz = reverseWords(st);
        cout << sz << endl;
    }
	return 0;
}