#include<bits/stdc++.h>
using namespace std;
#define INF 1e+9
#define EPS 1e-8
#define nuLL -1
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
  vector<double> cost;
  vector<int> to;
};

struct backup{
  bool operator<(const backup& another) const {
    return x == another.x ? y < another.y : x < another.x;
  }
  backup(double x, double y, int a, int b, int c, int d){
    this->x = x;
    this->y = y;
    this->line.push_back(a);
    this->line.push_back(b);
    this->line.push_back(c);
    this->line.push_back(d);
  }
  double x;
  double y;
  vector<int> line;
};

struct num_data{
  int a;
  int b;
  bool C0 = false;
  bool C1 = false;
};

void search(vector<pair<double,double>>&,pair<int,int>,pair<int,int>,vector<pair<double,double>>&,vector<backup>&);
void printCross(vector<pair<double,double>>&,vector<pair<double,double>>&);
void makeGraph(vector<node> &,vector<pair<double,double>> &,pair<int,int>);
void makeGraph(vector<node>& nodes,vector<backup>& backups,vector<pair<double,double>>& inf);
double distance(vector<pair<double,double>>&,pair<int,int>);
double distance(vector<backup>& bu,vector<pair<double,double>>& inf,int i,int counter);
double distance(double,double,double,double);
double dijkstra(vector<node>&,int,int);
bool check(int,int,bool,bool,vector<pair<int,int>>&);
void initializeGraph(vector<node>&);
void fullGraph(vector<backup>&,vector<node>&);
void printPath(vector<node>&,int,int,int);
int main(){
  bool flag = false;
  int n,m,p,q,S,E,est;
  string s,e;
  double results;
  cin >> n >> m >> p >> q;
  vector<pair<double,double>> xy(n);
  vector<pair<int,int>> path(m);
  vector<node> nodes(n);
  vector<backup> backups;
  vector<pair<double,double>> cross;
  vector<pair<int,int>> num_inf; 
  vector<num_data> se(q);
  for(int i=0;i<n;i++){
    cin >> xy[i].first >> xy[i].second;
  }
  for(int i=0;i<m;i++){
    cin >> path[i].first >> path[i].second;
    path[i].first--;
    path[i].second--;
    makeGraph(nodes,xy,path[i]);
  }
  for(int i=0;i<q;i++){
    cin >> s >> e >> est;
    if(s[0] !='C'){
      S = stoi(s)-1;
    }
    if(e[0]!='C'){
      E = stoi(e)-1;
    }
    if(s[0] == 'C'){
      s.erase(s.begin());
      S = n+stoi(s)-1;
      se[i].C0 = true;
    }
    if(e[0] == 'C'){
      e.erase(e.begin());
      E = n+stoi(e)-1;
      se[i].C1 = true;
    }
    se[i].a = S;
    se[i].b = E;
  }
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      search(xy,path[i],path[j],cross,backups);
    }
  } 
  num_inf.push_back(make_pair(xy.size(),cross.size()));
  printCross(xy,cross);
  sort(backups.begin(),backups.end());
  makeGraph(nodes,backups,xy);
  fullGraph(backups,nodes);
  for(int i=0;i<q;i++){
    initializeGraph(nodes);
    flag = check(se[i].a,se[i].b,se[i].C0,se[i].C1,num_inf);
    if(flag){
      results = dijkstra(nodes,se[i].a,se[i].b);
      if(results == nuLL)cout<< "NA" << '\n';
      else cout << results << '\n';
      printPath(nodes,se[i].a,se[i].b,n);
    }
    else cout << "NA" << '\n';
  }
  return 0;
}

void search(vector<pair<double,double>>& nodes,pair<int,int> llnk0,pair<int,int> llnk1,vector<pair<double,double>>& XxxX,vector<backup>& bu){
  int a1,a2,a3,a4,a5,a6;
  double a,s,t;
  double x,y;
  a1 = nodes[llnk0.second].first-nodes[llnk0.first].first; 
  a2 = nodes[llnk1.first].second-nodes[llnk1.second].second;
  a3 = nodes[llnk1.second].first-nodes[llnk1.first].first;
  a4 = nodes[llnk0.second].second-nodes[llnk0.first].second;
  a5 = nodes[llnk1.first].first-nodes[llnk0.first].first;
  a6 = nodes[llnk1.first].second-nodes[llnk0.first].second;
  a = abs(a1*a2 + a3*a4);
  if(a<=EPS&&a>=-EPS)return;
  s = (a2*a5+a3*a6)/a;
  t = ((-a4*a5)+(a1*a6))/a;
  if(s>=1||0>=s||t>=1||0>=t)return;
  x = nodes[llnk0.first].first+a1*s;
  y = nodes[llnk0.first].second+a4*s;
  XxxX.push_back(make_pair(x,y));
  bu.push_back((backup(x,y,llnk0.first,llnk0.second,llnk1.first,llnk1.second)));
  return;
}

void printCross(vector<pair<double,double>>& nodes,vector<pair<double,double>>& cross){
  bool flag = false;
  flag = !cross.empty();  
  if(flag){ 
    sort(cross.begin(),cross.end(),greater<pair<double,double>>());
    while(!cross.empty()){
      cout << cross.back().first << " " << cross.back().second << '\n';
      cross.pop_back();
    }
  }
  if(!flag) cout << "NA" << '\n';
  cross.shrink_to_fit();
}

void makeGraph(vector<node>& nodes,vector<pair<double,double>>& inf,pair<int,int> path){
  double dist = distance(inf,path);
  nodes[path.first].mincost = nuLL;
  nodes[path.first].from = nuLL;
  nodes[path.first].done = false;
  nodes[path.first].cost.push_back(dist);
  nodes[path.first].to.push_back(path.second);
  
  nodes[path.second].mincost = nuLL;
  nodes[path.second].from = nuLL;
  nodes[path.second].done = false;
  nodes[path.second].cost.push_back(dist);
  nodes[path.second].to.push_back(path.first);
}

void makeGraph(vector<node>& nodes,vector<backup>& backups,vector<pair<double,double>>& inf){
  int counter = 0;
  int size = inf.size();
  int Size = backups.size();
  for(int i = 0;i<Size;i++){
    double dist0 = distance(backups,inf,backups[i].line[0],i);
    double dist1 = distance(backups,inf,backups[i].line[1],i);
    double dist2 = distance(backups,inf,backups[i].line[2],i);
    double dist3 = distance(backups,inf,backups[i].line[3],i);
    nodes.push_back((node(nuLL,nuLL,false,dist0,dist1,dist2,dist3,backups[i].line[0],backups[i].line[1],backups[i].line[2],backups[i].line[3])));
    nodes[backups[i].line[0]].cost.push_back(dist0);
    nodes[backups[i].line[0]].to.push_back(i+size);
    nodes[backups[i].line[1]].cost.push_back(dist1);
    nodes[backups[i].line[1]].to.push_back(i+size);
    nodes[backups[i].line[2]].cost.push_back(dist2);
    nodes[backups[i].line[2]].to.push_back(i+size);
    nodes[backups[i].line[3]].cost.push_back(dist3);
    nodes[backups[i].line[3]].to.push_back(i+size);
  }
}
double distance(vector<pair<double,double>>& inf,pair<int,int> path){
  return sqrt((pow(inf[path.second].first-inf[path.first].first,2.0)+pow(inf[path.second].second-inf[path.first].second,2.0)));
}
double distance(vector<backup>& bu,vector<pair<double,double>>& inf,int i,int counter){
  return sqrt((pow(inf[i].first-bu[counter].x,2.0)+pow(inf[i].second-bu[counter].y,2.0)));
}
double distance(double x0,double y0,double x1,double y1){
  return sqrt((pow(x1-x0,2.0)+pow(y1-y0,2.0)));
}
double dijkstra(vector<node>& nodes,int start,int goal){
  nodes[start].mincost = 0;
  double cost;
  while(true){
    int doneNode = -1;
    for(int i = 0; i < nodes.size(); i++){
      if(nodes[i].done == true){
        continue;
      }
      if(nodes[i].mincost < 0){
        continue;
      }
      if (doneNode<0 || nodes[i].mincost < nodes[doneNode].mincost){
        doneNode = i;
      }
    }
    if(doneNode==-1)break;
    nodes[doneNode].done = true;
    for(int i = 0;i< nodes[doneNode].to.size();i++){
      int to = nodes[doneNode].to[i];
      cost = nodes[doneNode].mincost + nodes[doneNode].cost[i];
      if(nodes[to].mincost < 0 || cost <= nodes[to].mincost){
        nodes[to].mincost = cost;
        nodes[to].from = doneNode;
      }
    }
  }
  return nodes[goal].mincost;
}
bool check(int start,int goal,bool C0,bool C1,vector<pair<int,int>>& num_inf){
    if(C0==true){
      if(start>=(num_inf[0].first+num_inf[0].second)||start<num_inf[0].first)return false;
    }
    if(C1==true){
      if(goal>=(num_inf[0].first+num_inf[0].second)||goal<num_inf[0].first)return false;
    }
    if(C0==false){
      if(start<0||start>=num_inf[0].first)return false;
    }
    if(C1==false){
      if(goal<0||goal>=num_inf[0].first)return false;
    }
  return true;
}
void initializeGraph(vector<node>& nodes){
  for(int i=0;i<nodes.size();i++){
    nodes[i].mincost = nuLL;
    nodes[i].from = nuLL;
    nodes[i].done = false;
  }
}

void fullGraph(vector<backup>& backups,vector<node>& nodes){
  vector<pair<int,int>> list;
  int a,b,c;
  double dist;
  for(int i=0;i<backups.size();i++){
    for(int j=0;j<backups[i].line.size();j+=2){
      list.push_back(make_pair(backups[i].line[j],backups[i].line[j+1]));
    }
  }
  for(int i=0;i<list.size()-1;i++){
    for(int j=i+1;j<list.size();j++){
      if(list[i].first == list[j].first&&list[i].second == list[j].second){
        a = (int)(i/2);
        b = (int)(j/2);
        c = nodes.size()-backups.size();
        dist = distance(backups[a].x,backups[a].y,backups[b].x,backups[b].y);
        nodes[c+a].cost.push_back(dist);
        nodes[c+a].to.push_back(c+b);
        nodes[c+b].cost.push_back(dist);
        nodes[c+b].to.push_back(c+a);
      }
    }
  }
}
void printPath(vector<node>& nodes,int start,int goal,int n){
  n--;
  vector<int> path;
  for(int i=goal;i!=start;i=nodes[i].from){
    path.push_back(i);
  }
  path.push_back(start);
  for(int i = path.size()-1;i>=0;i--){
    if(path[i]>n){
      cout<<"C"<<path[i]-n<<" ";
    }
    else{
      cout<<path[i]+1<<" ";
    }
  }
  cout<<'\n';
}
