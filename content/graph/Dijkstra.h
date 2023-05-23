/**
 * Author: Wenli
 * Date: 
 * License: 
 * Description: SSSP Weighted, without negative cycles.
 * Time: $O((E + V) \log V))$
 * Status: probably tested
 */
typedef pair<int,int> pii;
typedef vector<pii> vpi;
vector<vpi> adj;
int dist[N]; // N = number of nodes
priority_queue<pii, vector<pii>, greater<pii>> dja;
dja.emplace(0, START_NODE);
fill(dist, dist+N, INT_MAX);
dist[START_NODE] = 0;
while (!dja.empty()) {
	pii pt = dja.top(); dja.pop();
	if (pt.first != dist[pt.second]) continue;
	for (pii ps : adj[pt.second]) {
		if (pt.first + ps.second < dist[ps.first]) {
			dist[ps.first] = pt.first + ps.second;
			dja.emplace(dist[ps.first], ps.first);
		}
	}
}