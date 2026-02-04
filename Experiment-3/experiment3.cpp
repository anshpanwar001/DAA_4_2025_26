#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    unordered_map<int, int> firstOccur;
    int prefix = 0;
    int maxLen = 0;

    firstOccur[0] = -1; 

    for (int i = 0; i < N; i++) {

        if (arr[i] == 'P') prefix += 1;
        else prefix -= 1;

        if (firstOccur.find(prefix) != firstOccur.end()) {
            maxLen = max(maxLen, i - firstOccur[prefix]);
        } else {
            firstOccur[prefix] = i;   
        }
    }

    cout << maxLen;
    return 0;
}