#include <bits/stdc++.h>
using namespace std;
#define INF 1e+9

struct Point{
  double x;
  double y;
};

struct Link{
  int start;
  int end;
};
Point search(vector<Point>,Link,Link);
int main(){
  bool flag=false;
  int n,m,p,q;
  cin>>n>>m>>p>>q;
  vector<Point> point(n);
  vector<Link> link(m);
  Point cross;
  for(int i=0;i<n;i++)cin>>point[i].x>>point[i].y;
  for(int i=0;i<m;i++){
    cin>>link[i].start>>link[i].end;
    link[i].start--;
    link[i].end--;
  }
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      cross=search(point,link[i],link[j]);
    }
  }
  if(cross.x==INF&&cross.y==INF)cout<<"NA"<<endl;
  else cout<<cross.x<<" "<<cross.y<<endl;
  return 0;
}
Point search(vector<Point> point,Link p,Link q){
  int entry[6];
  double a,s,t;
  Point cross;
  entry[0]=point[p.end].x-point[p.start].x;
  entry[1]=point[q.start].y-point[q.end].y;
  entry[2]=point[q.end].x-point[q.start].x;
  entry[3]=point[p.end].y-point[p.start].y;
  entry[4]=point[q.start].x-point[p.start].x;
  entry[5]=point[q.start].y-point[p.start].y;
  a=entry[0]*entry[1]+entry[2]*entry[3];
  if(a==0){
    cross.x=INF;
    cross.y=INF;
    return cross;
  }
  s=((entry[1]*entry[4])+(entry[2]*entry[5]))/a;
  t=((-entry[3]*entry[4])+(entry[0]*entry[5]))/a;
  if(0<s&&s<1&&0<t&&t<1){
    cross.x=point[p.start].x+(point[p.end].x-point[p.start].x)*s;
    cross.y=point[p.start].y+(point[p.end].y-point[p.start].y)*s;
    return cross;
  }
  cross.x=INF;
  cross.y=INF;
  return cross;
}
