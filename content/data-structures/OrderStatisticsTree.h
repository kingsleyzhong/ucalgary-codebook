/*
OrderStatistics tree;
tree.insert(1);
tree.order_of_key(1);
*/

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderStatistics;
OrderStatistics tree; // Usage
tree.insert(1);
tree.order_of_key(1);