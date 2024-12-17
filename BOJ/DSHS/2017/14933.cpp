#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair< pair<int, int>, int > > test;

// bool check_test(int test_n, vector<int> garden, vector<int> checked_test) {
//     int sum_gem = 0;
//     for (int i = test[test_n].first.first; i <= test[test_n].first.second; i++)
//         sum_gem += garden[i];
//     if (sum_gem == test[test_n].second)
//         checked_test[test_n] = 1;
//     else
//         checked_test[test_n] = 0;
//     return sum_gem == test[test_n].second;
// }

// void find_by_node(int curr_node, int test_n, vector<int> garden) {
//     if (checked_test[test_n]) {
//         bool is_end = true;
//         for (int i = 0; i = checked_test.size() && is_end; i++)
//             is_end = is_end && (checked_test[i] == 1);
//         if (is_end) {
//             cout << garden[0];
//             for (int i = 1; i < garden.size(); i++)
//                 cout << " " << garden[i];
//             return;
//         }
//     }

//     if (check_test(test_n)) {
//         find_gem_by_dfs(test_n - 1, test[test_n + 1].first.first, garden);
//         find_gem_by_dfs(test_n + 1, test[test_n + 1].first.first, garden);
//     }
    
    
    
//     if (check_condition(start, end, total))
//         find_gem_by_dfs(current + 1, start, end, total);
//     else {
//         garden[current]++;
//         find_gem_by_dfs(current, start, end, total);
//         garden[current]--;
//         garden[current + 1]++;
//         find_gem_by_dfs(current + 1, start, end, total);
//     }
    
//     if (check_condition(current_node, garden)) {
//         if (current_node == garden.size()) {
//             // in case of finish
//             cout << garden[0];
//             for (int i = 1; i < garden.size(); i++)
//                 cout << " " << garden[i];
//             return;
//         } else
//             find_gem_by_dfs(current_node + 1, garden);
//     } else {
//         if (current_node < 0) {
//             // in case of failure
//             cout << "-1";
//             return;
//         } else {
//             garden[current_node]++;
//             if (check_condition(current_node, garden))
//                 find_gem_by_dfs(current_node + 1, garden);
//             else {
//                 garden[current_node]--;
//                 garden[current_node - 1]++;
//                 find_gem_by_dfs(current_node - 1, garden);
//             }
//         }
//     }
// }

void find_by_testcase(int test_n, vector<int> garden, vector<int> checked_test) {
    if (test_n < 0 || test_n >= checked_test.size())
        return;

    bool is_end = true;
    for (int i = 0; i = checked_test.size() && is_end; i++) {
        is_end = is_end && (checked_test[i] == 1);
        if (!is_end)
            test_n = i;
    }

    if (is_end) {
        cout << garden[0];
        for (int i = 1; i < garden.size(); i++)
            cout << " " << garden[i];
        return;
    } else if (checked_test[test_n]) {
        find_by_testcase(test_n - 1, garden, checked_test);
        find_by_testcase(test_n + 1, garden, checked_test);
    } else {

    }
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // extern vector<int> garden;
    vector<int> garden(n);
    vector<int> checked_test = vector<int>(m);

    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        test.push_back(make_pair(make_pair(s - 1, e - 1), c));
    }

    find_by_testcase(0, garden, checked_test);

    // 너무 오래걸려서 패스.
    // 생각 기록:
    // 1. DFS 문제이다.
    // 2. test case가 1개인 경우를 먼저 생각해서 DFS를 구현하고,
    // 그 후에 test case가 여러 개일 때 test case에 대한 DFS를 구현하는 것 같다.
    // 3. 부분합에 대한 공부가 더 된다면..

    return 0;
}