#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

/*
Minimize Cash Flow among a given set of friends
 who have borrowed money from each other
*/

const int N = 3;

void calculate_net(int graph[N][N], int netAmount[N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            // graph[i][j] are i's debts, graph[j][i] are i's credits
            netAmount[i] += graph[j][i] - graph[i][j];
}

void getMaxMin(int netAmount[N], int *max, int *min) {
    int max_ = 0, min_ = 0;
    for (int i = 0; i < N; i++) {
        if (netAmount[i] > netAmount[max_]) max_ = i;
        if (netAmount[i] < netAmount[min_]) min_ = i;
    }

    *max = max_, *min = min_;
}

int minOfTwo(int i1, int i2) {
    return i1 > i2 ? i2 : i1;
}

void minCashFlowRecur(int netAmount[N]) {
    int maxC, maxD;
    getMaxMin(netAmount, &maxC, &maxD);

    if (netAmount[maxC] == 0 && netAmount[maxD] == 0)
        return;

    int min = minOfTwo(abs(netAmount[maxD]), netAmount[maxC]);
    netAmount[maxC] -= min;
    netAmount[maxD] += min;

    cout << "Person " << maxD << " pays " << min
    << " to " << "Person " << maxC << endl;

    minCashFlowRecur(netAmount);
}

void minCashFlow(int graph[N][N]) {
    int netAmount[N];
    memset(netAmount, 0, sizeof(netAmount));

    calculate_net(graph, netAmount);

    minCashFlowRecur(netAmount);
}

int main() {
    int graph[N][N] = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0},
    };

    minCashFlow(graph);
    return 0;
}