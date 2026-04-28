#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int tsp(int mask, int currentCity, const vector<vector<int>> &cost,
        vector<vector<int>> &dp, vector<vector<int>> &nextChoice) {
    int totalCities = cost.size();

    if (mask == (1 << totalCities) - 1) {
        if (cost[currentCity][0] >= INF) {
            return INF;
        }
        return cost[currentCity][0];
    }

    if (dp[mask][currentCity] != -1) {
        return dp[mask][currentCity];
    }

    int minimumCost = INF;
    for (int nextCity = 0; nextCity < totalCities; nextCity++) {
        if ((mask & (1 << nextCity)) != 0 || cost[currentCity][nextCity] >= INF) {
            continue;
        }

        int remainingCost =
            tsp(mask | (1 << nextCity), nextCity, cost, dp, nextChoice);
        if (remainingCost >= INF) {
            continue;
        }

        int currentPathCost = cost[currentCity][nextCity] + remainingCost;
        if (currentPathCost < minimumCost) {
            minimumCost = currentPathCost;
            nextChoice[mask][currentCity] = nextCity;
        }
    }

    dp[mask][currentCity] = minimumCost;
    return minimumCost;
}

vector<int> buildTour(const vector<vector<int>> &nextChoice, int totalCities) {
    vector<int> tour = {0};
    int mask = 1;
    int currentCity = 0;

    while (mask != (1 << totalCities) - 1) {
        int nextCity = nextChoice[mask][currentCity];
        if (nextCity == -1) {
            return {};
        }

        tour.push_back(nextCity);
        mask |= (1 << nextCity);
        currentCity = nextCity;
    }

    tour.push_back(0);
    return tour;
}

int main() {
    int cities;
    cin >> cities;

    vector<vector<int>> cost(cities, vector<int>(cities));
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(1 << cities, vector<int>(cities, -1));
    vector<vector<int>> nextChoice(1 << cities, vector<int>(cities, -1));

    int minimumCost = tsp(1, 0, cost, dp, nextChoice);
    if (minimumCost >= INF) {
        cout << "No Hamiltonian tour exists\n";
        return 0;
    }

    vector<int> tour = buildTour(nextChoice, cities);

    cout << "Minimum tour cost: " << minimumCost << '\n';
    cout << "Tour: ";
    for (int i = 0; i < static_cast<int>(tour.size()); i++) {
        cout << tour[i];
        if (i + 1 < static_cast<int>(tour.size())) {
            cout << " -> ";
        }
    }
    cout << '\n';

    return 0;
}
