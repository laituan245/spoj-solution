// COURIER - The Courier
// http://www.spoj.com/problems/COURIER/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int nbOfOneBits (int nb) {
  if (nb == 0)
    return 0;
  int result = 0;
  while (nb) {
    result ++;
    nb = nb & (nb-1);
  }
  return result;
}

int min (int a, int b) {
  if (a < b)
    return a;
  return b;
}

int main () {
  int t, n, m, b, nbRequests, nbParcels, nbBitsSet;
  int tmpU, tmpV, tmpD;
  int tempInt;
  int edge[101][101];
  int dist[101][101];
  int requestU[5];
  int requestV[5];
  int requestB[5];
  int dp[5000][5];
  vector <int> requestTypes;
  map <int, vector <int> > requestBits;

  cin >> t;
  for (int z = 0; z < t; z++) {
    cin >> n >> m >> b;

    nbParcels = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        edge[i][j] = 1000000000;
        dist[i][j] = 1000000000;
        if (i == j) {
          edge[i][j] = 0;
          dist[i][j] = 0;
        }
      }

    for (int i = 0; i < m; i++) {
      cin >> tmpU >> tmpV >> tmpD;
      edge[tmpU][tmpV] = tmpD;
      edge[tmpV][tmpU] = tmpD;
      dist[tmpU][tmpV] = tmpD;
      dist[tmpV][tmpU] = tmpD;
    }

    cin >> nbRequests;
    for (int i = 0; i < nbRequests; i++) {
      cin >> requestU[i] >> requestV[i] >> requestB[i];
      nbParcels += requestB[i];
    }

    // Floyd–Warshall algorithm O(n^3)
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (dist[i][j]  > dist[i][k] + dist[k][j])
            dist[i][j] = dist[i][k] + dist[k][j];

    // DP with bitmask
    tempInt = 1 << nbParcels;
    for (int i = 1; i < tempInt; i++) {
      nbBitsSet = 0;
      requestTypes.clear();
      requestBits.clear();
      for (int h = 0; h < nbParcels; h++)
        if (i & (1 << h)) {
          nbBitsSet ++;
          int tempSum = 0;
          for (int requestType = 0; requestType < nbRequests; requestType++)
            if (tempSum + requestB[requestType] > h) {
              requestTypes.push_back(requestType);
              requestBits[requestType].push_back(h);
              break;
            }
            else
              tempSum += requestB[requestType];
      }

      for (int j = 0; j < nbRequests; j++) {
        if (requestBits[j].size() == 0)
          dp[i][j] = 1000000000;
        else {
          dp[i][j] = 1000000000;
          int tempI = i & ~(1 << requestBits[j][0]);
          if (tempI == 0) {
            dp[i][j] = dist[b][requestU[j]] + dist[requestU[j]][requestV[j]];
          }
          else {
            for (int requestType = 0; requestType < nbRequests; requestType++)
              dp[i][j] = min (dp[i][j], dp[tempI][requestType] + dist[requestV[requestType]][requestU[j]] + dist[requestU[j]][requestV[j]]);
          }
        }
      }
    }

    int finalRs = 2000000000;
    for (int requestType = 0; requestType < nbRequests; requestType++)
      finalRs = min (finalRs, dp[tempInt-1][requestType] + dist[requestV[requestType]][b]);
    cout << finalRs << "\n";
  }
}
