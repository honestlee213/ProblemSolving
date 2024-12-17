#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define INF UINT_MAX;

struct Data {
	int node;	// 연결된 다음 노드 번호
	unsigned int weight;	// 간선의 가중치
    Data(int i, unsigned int j) : node(i), weight(j) {}
};

struct cmp {
	bool operator()(Data a, Data b) {
		return a.weight > b.weight;
	}
};

set<int> fan;
vector< vector<Data> > v;	// v[x]: x번 노드에 연결된 다음 노드와 가중치의 정보
vector<unsigned int> Dijk;	// Dijk[x]: x번 노드까지의 최단 경로 값
vector<unsigned int> Dijk_fan;	// Dijk[x]: x번 노드까지의 최단 경로 값
priority_queue<Data, vector<Data>, cmp> pq_fan;

void MakeGraph(int m) {
    int a, b;
    unsigned int t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        v[a - 1].push_back(Data(b - 1, t));
        v[b - 1].push_back(Data(a - 1, t));
    }
}

void MakeFan(int k, int n) {
    int f;
    for (int i = 0; i < k; i++) {
        cin >> f;
        fan.insert(f - 1);
    }
}

void InitDijkArray(int n) {
	for (int i = 0; i < n; i++) {
		Dijk[i] = INF;
        Dijk_fan[i] = INF;
    }
}

void InitQueue() {
    // 모든 추종자를 queue에 넣고 돌리면 그중 최단거리가 Dijk[i]에 남음
    for (int f : fan) {
        pq_fan.push(Data(f, 0));    // 시작하는 노드 삽입
        Dijk_fan[f] = 0;    // Dijk[시작] = 0으로 갱신
    }
}

void DijkStra() {
    priority_queue<Data, vector<Data>, cmp> pq;
    pq.push(Data(0, 0));
    Dijk[0] = 0;

	// priority_queue가 빌 때 까지 다익스트라 알고리즘 반복 수행
	while (!pq.empty()) {
		// priority_queue 맨 앞 노드 가져오기
		Data nowNode = pq.top();
		pq.pop();

		int node = nowNode.node;
		unsigned int weightSum = nowNode.weight;

		if (Dijk[node] < weightSum)
            continue;	// 이미 이전에 더 적은 가중치로 Dijk[node]를 갱신함

		// nowNode와 연결되어 있는 다른 모든 노드 탐색
		for (int i = 0; i < v[node].size(); i++) {
			int nextNode = v[node][i].node;
			unsigned int weight = v[node][i].weight;

			// ( 다음 노드에 저장된 값 > 다음 노드로 방문하면서 소비할 가중치의 합 ) 일때만 값 갱신, 그리고 pq 삽입
			if (Dijk[nextNode] > weight + weightSum) {
				Dijk[nextNode] = weight + weightSum;
				pq.push(Data(nextNode, Dijk[nextNode]));
			}
		}
	}
}

void DijkStraFan() {
	// priority_queue가 빌 때 까지 다익스트라 알고리즘 반복 수행
	while (!pq_fan.empty()) {
		// priority_queue 맨 앞 노드 가져오기
		Data nowNode = pq_fan.top();
		pq_fan.pop();

		int node = nowNode.node;
		unsigned int weightSum = nowNode.weight;

		if (Dijk_fan[node] < weightSum)
            continue;	// 이미 이전에 더 적은 가중치로 Dijk[node]를 갱신함

		// nowNode와 연결되어 있는 다른 모든 노드 탐색
		for (int i = 0; i < v[node].size(); i++) {
			int nextNode = v[node][i].node;
			unsigned int weight = v[node][i].weight;

			// ( 다음 노드에 저장된 값 > 다음 노드로 방문하면서 소비할 가중치의 합 ) 일때만 값 갱신, 그리고 pq 삽입
			if (Dijk_fan[nextNode] > weight + weightSum) {
				Dijk_fan[nextNode] = weight + weightSum;
				pq_fan.push(Data(nextNode, Dijk_fan[nextNode]));
			}
		}
	}
}

bool Reachable(int n) {
    for (int i = 1; i < n; i++)
        if (Dijk[i] >= Dijk_fan[i])
            return false;

    return true;
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> ans;
    int n, m, k;
    cin >> n >> m >> k;

    v.resize(n);
    Dijk.resize(n);
    Dijk_fan.resize(n);

	MakeGraph(m);
    MakeFan(k, n);

    InitDijkArray(n);
    InitQueue();	// 노드 0을 시작이라고 가정
    DijkStra();
    DijkStraFan();
    for (int i = 1; i < n; i++)
        if (Dijk[i] < Dijk_fan[i])
            ans.push_back(i);

    if (ans.empty())
        cout << 0;
    else {
        cout << ans[0] + 1;
        for (int i = 1; i < ans.size(); i++)
            cout << " " << ans[i] + 1;
    }

    return 0;
}
