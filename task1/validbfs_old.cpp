#include <bits/stdc++.h>
using namespace std;
const int max_num_of_nodes = 2e5 + 1;
vector<int> graph[max_num_of_nodes];

int main()
{
  int number_of_Nodes;
  cin >> number_of_Nodes;
  int num_of_given_edges = number_of_Nodes - 1;
  while (num_of_given_edges--)
  {
    int node1, node2;
    cin >> node1 >> node2;
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
  }

  vector<int> given_bfs(number_of_Nodes);
  for (int i = 0; i < number_of_Nodes; i++)
    cin >> given_bfs[i];

  // as starting point is always 1
  if (given_bfs[0] != 1)
    cout << "NO";
  else
  {
    bool flag = true;
    int flag2 = 0;
    int start, end;
    vector<int> isVisited(max_num_of_nodes, 0);
    isVisited[1] = 1;
    for (int i = 0; i < number_of_Nodes; i++)
    {

      int num_of_ele_of_node_in_graph = graph[given_bfs[i]].size();

      for (auto it : graph[given_bfs[i]])
      {
        if (isVisited[it] == 1)
        {
          num_of_ele_of_node_in_graph--;
        }
      }

      if (flag2 == 0)
      {
        start = i + 1;
        flag2 = 1;
      }
      else if (flag2 == 1)
      {
        start = end + 1;
      }

      end = start + num_of_ele_of_node_in_graph - 1;

      map<int, int> elements_in_range;
      for (int j = start; j <= end; j++)
      {

        elements_in_range.insert({given_bfs[j], 1});
      }

      for (auto it : graph[given_bfs[i]])
      {
        if (isVisited[it] == 0)
        {
          isVisited[it] = 1;
          if (elements_in_range[it] != 1)
          {
            flag = false;
            break;
          }
        }
      }

      if (flag == false)
        break;
      if (end == number_of_Nodes - 1)
        break;
    }

    if (flag == false)
      cout << "NO";
    else
      cout << "YES";
  }
}
