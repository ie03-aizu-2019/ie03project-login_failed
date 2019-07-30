#include<bits/stdc++.h>
using namespace std;

#define INF 1e+9
#define EPS 1e-8
#define nuLL -1

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<pair<double,double>> VPD;
typedef vector<pair<int,int>> VPI;
typedef pair<int,int> PI;
struct node{
  node(double mincost,int from,bool done,double d0,double d1,double d2,double d3,int t0,int t1,int t2,int t3){
    this->mincost = mincost;
    this->from = from;
    this->done = done;
    this->cost.push_back(d0);
    this->cost.push_back(d1);
    this->cost.push_back(d2);
    this->cost.push_back(d3);
    this->to.push_back(t0);
    this->to.push_back(t1);
    this->to.push_back(t2);
    this->to.push_back(t3);
  }
  node() = default;
  double mincost;
  int from;
  bool done;
  VD cost;
  VI to;
};

void makeGraph(vector<node> &,VPD&,PI);
int dfs(int,int,int,vector<node>&,VI&,VI&,VPI&);

int main(){

  bool flag = false;
  int n,m,p,q;

  cin >> n >> m >> p >> q;

  VPD xy(n);
  VPI path(m);
  vector<node> nodes(n);
  VPI bridges;
  VI pre(n,0);
  VI low(n,0);

  for(int i=0;i<n;i++){
    cin >> xy[i].first >> xy[i].second;
  }
  for(int i=0;i<m;i++){
    cin >> path[i].first >> path[i].second;
    path[i].first--;
    path[i].second--;
    makeGraph(nodes,xy,path[i]);
  }

  dfs(0,nodes[0].from,0,nodes,low,pre,bridges);
  for(int i = 0;i<bridges.size();i++){
    cout<<bridges[i].first<<"-"<<bridges[i].second<<endl;
  }
  return 0;
}

void makeGraph(vector<node>& nodes,VPD& inf,PI path){
  nodes[path.first].mincost = nuLL;
  nodes[path.first].from = nuLL;
  nodes[path.first].done = false;
  nodes[path.first].cost.push_back(nuLL);
  nodes[path.first].to.push_back(path.second);

  nodes[path.second].mincost = nuLL;
  nodes[path.second].from = nuLL;
  nodes[path.second].done = false;
  nodes[path.second].cost.push_back(nuLL);
  nodes[path.second].to.push_back(path.first);
}

int dfs(int crr,int from,int cnt,vector<node> &nodes,VI &low,VI &pre,VPI &res){
  low[crr] = pre [crr] = ++cnt;
  for(int i = 0; i<nodes[crr].to.size();i++){
    int to = nodes[crr].to[i];
    if(!pre[to]){
      low[crr] = min(low[crr],dfs(to,crr,cnt,nodes,low,pre,res));
      if(pre[to] == low [to]){
	res.push_back(make_pair(crr+1,to+1));
      }
    }
    else if (from != to){
      low[crr] = min(low[crr],low[to]);
    }
  }
  return low[crr];
}
