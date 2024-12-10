#include <iostream>
#include <vector>
#include <map>
using namespace std;

// long long calc_dis(long long x_dis, long long y_dis) {
//     long long dis = 0;

//     if (x_dis < 0)
//         dis -= x_dis;
//     else
//         dis += x_dis;
//     if (y_dis < 0)
//         dis -= y_dis;
//     else
//         dis += y_dis;

//     return dis;
// }

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long total_x = 0, total_y = 0;
    vector<long long> bank_x(n);
    vector<long long> bank_y(n);
    multimap<long long, long long> bankmap_x;
    multimap<long long, long long> bankmap_y;
    vector<long long> partial_num_x(n);
    vector<long long> partial_sum_x(n);
    vector<long long> partial_num_y(n);
    vector<long long> partial_sum_y(n);
    long long num_x = 0, num_y = 0;
    long long sum_x = 0, sum_y = 0;

    long long x, y;

    for (long long i = 0; i < n; i++) {
        cin >> x >> y;
        bank_x[i] = x;
        bank_y[i] = y;
        bankmap_x.insert(make_pair(x, i));
        bankmap_y.insert(make_pair(y, i));
        total_x += x;
        total_y += y;
    }

    for (auto iter = bankmap_x.begin(); iter != bankmap_x.end(); iter++) {
        x = iter->first;

        partial_num_x[iter->second] = num_x;
        partial_sum_x[iter->second] = sum_x;
        num_x++;
        sum_x += x;
    }

    for (auto iter = bankmap_y.begin(); iter != bankmap_y.end(); iter++) {
        y = iter->first;

        partial_num_y[iter->second] = num_y;
        partial_sum_y[iter->second] = sum_y;
        num_y++;
        sum_y += y;
    }

    int min_idx = 0;
    long long min_sum = 0;
    min_sum += (bank_x[0] * partial_num_x[0] - partial_sum_x[0]) + (total_x - partial_sum_x[0] - bank_x[0] * (n - partial_num_x[0]));
    min_sum += (bank_y[0] * partial_num_y[0] - partial_sum_y[0]) + (total_y - partial_sum_y[0] - bank_y[0] * (n - partial_num_y[0]));

    for (int i = 1; i < n; i++) {
        long long dis_i = 0;
        dis_i += (bank_x[i] * partial_num_x[i] - partial_sum_x[i]) + (total_x - partial_sum_x[i] - bank_x[i] * (n - partial_num_x[i]));
        dis_i += (bank_y[i] * partial_num_y[i] - partial_sum_y[i]) + (total_y - partial_sum_y[i] - bank_y[i] * (n - partial_num_y[i]));
        if (dis_i < min_sum) {
            min_sum = dis_i;
            min_idx = i;
        }
    }

    cout << min_idx + 1;

    return 0;
}
