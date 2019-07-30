#include<bits/stdc++.h>
using namespace std;
#define INF 1e+9
#define EPS 1e-8
struct point{
  int x;
  int y;
};
struct link{
  int f;
  int s;
};
void search(vector<point>&,link,link,vector<pair<float,float>>&);
int main(){
  /*
  ios::sync_with_stdio(false);
  cin.tie(0);
  */
  bool flag = false;
  int n,m,p,q;
  cin >> n >> m >> p >> q;
  vector<point> xy(n);
  vector<link> llnk(m);
  vector<pair<float,float>> cross;
  for(int i=0;i<n;i++){
    cin >> xy[i].x >> xy[i].y;
  }
  for(int i=0;i<m;i++){
    cin >> llnk[i].f >> llnk[i].s;
    llnk[i].f--;
    llnk[i].s--;
  }
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      search(xy,llnk[i],llnk[j],cross);
    }
  }
  flag = !cross.empty();
  if(flag){
    sort(cross.begin(),cross.end(),greater<pair<int,int>>());
    while(!cross.empty()){
      cout << cross.back().first << " " << cross.back().second << '\n';
      cross.pop_back();
    }
  }
  if(!flag) cout << "NA" << '\n';
  return 0;
}
void search(vector<point>& xy,link llnk0,link llnk1,vector<pair<float,float>>& XxxX){
  int a1,a2,a3,a4,a5,a6;
  float a,s,t;
  a1 = xy[llnk0.s].x-xy[llnk0.f].x;
  a2 = xy[llnk1.f].y-xy[llnk1.s].y;
  a3 = xy[llnk1.s].x-xy[llnk1.f].x;
  a4 = xy[llnk0.s].y-xy[llnk0.f].y;
  a5 = xy[llnk1.f].x-xy[llnk0.f].x;
  a6 = xy[llnk1.f].y-xy[llnk0.f].y;
  a = abs(a1*a2 + a3*a4);
  if(a<=EPS&&a>=-EPS)return;
  s = (a2*a5+a3*a6)/a;
  t = ((-a4*a5)+(a1*a6))/a;
  if(s>=1||0>=s||t>=1||0>=t)return;
  XxxX.push_back(make_pair(xy[llnk0.f].x+a1*s,xy[llnk0.f].y+a4*s));
  return;
}
