#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > letter_bucket;
char p[110];

bool check_suffix(char *p) {
    int length = strlen(p);
    int pointer = -1;
    for(int i = 0; i < length; i++) {
        if(('a' > p[i]) or ('z' < p[i]))
            continue;
        int ans = -1;
        int letter = p[i];
        int left = 0;
        vector<int> arr = letter_bucket[letter];
        int right = arr.size();
        while(left <= right) {
            int middle = (left+right)/2;
            if (arr[middle] <= pointer)
                left = middle + 1;
            else {
                ans = middle;
                right = middle - 1;
            }
        }
        if(ans == -1)
            return false;
        else
            pointer = ans;
    }
    return true;
}

void solve() {
    scanf("%s\n", p);
    int length = strlen(p);
    int left = 0;
    int right = length;
    int ans;
    while(left <= right) {
        int middle = (left+right)/2;
        bool flag = check_suffix(p + middle);
        if(flag) {
            right = middle - 1;
            ans = middle;
        }
        else
            left = middle + 1;
    }
    printf("%d\n", (length - ans));
}

int main() {
    char S[1000009];
    int N;
    scanf("%s\n", S);
    for(int i = 0; S[i] != '\0'; i++) {
        letter_bucket[S[i]].push_back(i);
    }
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        solve();
}
