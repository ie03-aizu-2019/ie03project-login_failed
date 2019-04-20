#include<bits/stdc++.h>
using namespace std;
bool search(int*,int*,int*,int*);
double xp,yp;
static const float EPS = 1e-8;
int main(){
  int n,m,p,q;
  int x[4],y[4];
  int c1[2],c2[2];
  double point;
  bool flag = false;
  cin >> n >> m >> p >> q;
  for(int i=0;i<n;++i){
    cin >> x[i] >> y[i];
  }
  for(int i=0;i<m;++i){
    cin >> c1[i] >> c2[i];
    c1[i] = c1[i]-1;
    c2[i] = c2[i]-1;
  }
  flag = search(c1,c2,x,y);
  flag == true ? cout << xp << " " << yp << endl : cout << "NA" << endl;
}
bool search(int c1[2],int c2[2],int x[4],int y[4]){
  int a1,a2,a3,a4,a5,a6;
  float a,s,t;
  a1 = x[c2[0]]-x[c1[0]];
  a2 = y[c1[1]]-y[c2[1]];
  a3 = x[c2[1]]-x[c1[1]];
  a4 = y[c2[0]]-y[c1[0]];
  a5 = x[c1[1]]-x[c1[0]];
  a6 = y[c1[1]]-y[c1[0]];
  a = abs(a1*a2 + a3*a4);
  if(a<=EPS&&a>=-EPS)return false;
  s = (a2*a5+a3*a6)/a;
  t = ((-a4*a5)+(a1*a6))/a;
  if(s>=1||0>=s||t>=1||0>=t)return false;
  xp = x[c1[0]]+a1*s;
  yp = x[c1[1]]+a3*t;
  return true;
}
