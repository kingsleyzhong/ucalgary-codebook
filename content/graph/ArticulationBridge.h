/**
 * Author: Wenli Looi
 * Date: 
 * License: 
 * Description: Find vertex/edge that would disconnect the graph.
 * Time: O(V + E)
 * Status: probably tested
 * Usage: 
// N is number of vertices
cnt = 0;
adj.assign(N, VI()); // fill adj
dfs_num.assign(N, -1);
dfs_low.resize(N); // initialization not necessary
for (int n = 0; n < N; n++) dfs(n, n, -1);
 */
vvi adj;
vi dfs_low, dfs_num;
int cnt;

void dfs(int i, int r, int p) { // (cur, root, parent)
	if (dfs_num[i] != -1) return;
	dfs_low[i] = dfs_num[i] = cnt++;
	int ap = i != r; // number of disconnected
	                 // components if vertex is removed
	for (int j : adj[i])
	if (j != p) { // change cond if parallel edges
		if (dfs_num[j] == -1) {
			dfs(j, r, i);
			if (dfs_low[j] >= dfs_num[i]) ap++;
			if (dfs_low[j] > dfs_num[i]) {
				// (i,j) is a bridge
				// each **UNORDERED** pair
				// will occur exactly once
			}
			dfs_low[i] = min(dfs_low[i], dfs_low[j]);
		} else {
			dfs_low[i] = min(dfs_low[i], dfs_num[j]);
		}
	}
	if (ap >= 2) {
		// i is an articulation point
		// each vertex will only occur once
	}
}