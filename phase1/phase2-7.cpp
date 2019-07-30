#include <bits/stdc++.h>
#include <cmath>
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
struct Short{
  double distance=INF;
  Point p;
};
void find(int,int,int,vector<Point>,vector<Link>);
int main(){
  int n,m,p,q;
  cin>>n>>m>>p>>q;
  vector<Point> point(n+p);
  vector<Link> link(m);
  for(int i=0;i<n;i++)cin>>point[i].x>>point[i].y;
  for(int i=0;i<m;i++){
    cin>>link[i].start>>link[i].end;
    link[i].start--;
    link[i].end--;
  }
  for(int i=n;i<n+p;i++)cin>>point[i].x>>point[i].y;
  for(int i=0;i<p;i++)find(m,n,i,point,link);
  return 0;
}
void find(int m,int n,int p,vector<Point> point,vector<Link> link){
  Short s;
  int i;
  double a1,b1,c1,dis,a2,b2,x,y;
  for(i=0;i<m;i++){
    if(point[link[i].start].y==point[link[i].end].y){
      if((point[n+p].x<=point[link[i].start].x&&point[n+p].x>=point[link[i].end].x)||
	 (point[n+p].x>=point[link[i].start].x&&point[n+p].x<=point[link[i].end].x)){
	dis=abs(point[n+p].y-point[link[i].start].y);
	if(s.distance>dis){
	  s.distance=dis;
	  s.p.x=point[n+p].x;
	  s.p.y=point[link[i].start].y;
	}
      }
    
      else{
	if(abs(point[link[i].start].x-point[n+p].x)<abs(point[link[i].end].x-point[n+p].x)){
	  dis=sqrt(pow(point[link[i].start].x-point[n+p].x,2)
		   +pow(point[link[i].start].y-point[n+p].y,2));
	  if(s.distance>dis){
	    s.distance=dis;
	    s.p.x=point[link[i].start].x;
	    s.p.y=point[link[i].start].y;
	  }
	}
	else{
	  dis=sqrt(pow(point[link[i].end].x-point[n+p].x,2)
		   +pow(point[link[i].end].y-point[n+p].y,2));
	  if(s.distance>dis){
	    s.distance=dis;
	    s.p.x=point[link[i].end].x;
	    s.p.y=point[link[i].end].y;
	  }
	}
      }
    }
    else if(point[link[i].start].x==point[link[i].end].x){
      if((point[link[i].start].y<=point[n+p].y&&point[link[i].end].y>=point[n+p].y)||
	 (point[link[i].start].y>=point[n+p].y&&point[link[i].end].y<=point[n+p].y)){
	dis=abs(point[link[i].start].x-point[n+p].x);
	if(s.distance>dis){
	  s.distance=dis;
	  s.p.x=point[link[i].start].x;
	  s.p.y=point[n+p].y;
	}
      }
      else{
	if(abs(point[link[i].start].y-point[n+p].y)
	   <abs(point[link[i].end].y-point[n+p].y)){
	  dis=sqrt(pow(point[link[i].start].x-point[n+p].x,2)
		   +pow(point[link[i].start].y-point[n+p].y,2));
	  if(s.distance>dis){
	    s.distance=dis;
	    x=point[link[i].start].x;
	    y=point[link[i].start].y;
	  }
	}
	else{
	  dis=sqrt(pow(point[link[i].end].x-point[n+p].x,2)
		   +pow(point[link[i].end].y-point[n+p].y,2));
	  if(s.distance>dis){
	    s.distance=dis;
	    x=point[link[i].end].x;
	    y=point[link[i].end].y;
	  }
	}
      }
    }
    else{     
      a1=(point[link[i].start].y-point[link[i].end].y)
	/(point[link[i].start].x-point[link[i].end].x);
      b1=point[link[i].start].y-a1*point[link[i].start].x;
      a2=-1/a1;
      b2=point[n+p].y-a2*point[n+p].x;
      x=-(b1-b2)/(a1-a2);
      y=a1*x+b1;
      if(!((point[link[i].start].x>=x&&point[link[i].end].x>=x)||
	   (point[link[i].start].x<=x&&point[link[i].end].x<=x)||
	   (point[link[i].start].y<=y&&point[link[i].end].y<=y)||
	   (point[link[i].start].y>=y&&point[link[i].end].y>=y))){
	a1*=(point[link[i].start].x-point[link[i].end].x);
	c1=(point[link[i].start].x-point[link[i].end].x);
	b1*=(point[link[i].start].x-point[link[i].end].x);
	dis=abs(a1*point[n+p].x-c1*point[n+p].y+b1)/sqrt(pow(a1,2)+pow(c1,2));
	if(s.distance>dis){
	 
	  s.distance=dis;
	  s.p.x=x;
	  s.p.y=y;
	}
      }
      else{
	if(sqrt(pow(point[link[i].start].x-point[n+p].x,2)
		+pow(point[link[i].start].y-point[n+p].y,2))<
	   sqrt(pow(point[link[i].end].x-point[n+p].x,2)
		+pow(point[link[i].end].y-point[n+p].y,2))){
	  x=point[link[i].start].x;
	  y=point[link[i].start].y;
	  dis=sqrt(pow(x-point[n+p].x,2)+pow(y-point[n+p].y,2));
	  if(s.distance>dis){
	    s.distance=dis;
	    s.p.x=x;
	    s.p.y=y;
	  }
	}
	else{
	  x=point[link[i].end].x;
	  y=point[link[i].end].y;
	  dis=sqrt(pow(x-point[n+p].x,2)+pow(y-point[n+p].y,2));
	  if(s.distance>dis){
	    s.distance=dis;
	    s.p.x=x;
	    s.p.y=y;
	  }
	}
      }
    }
  }
  cout<<s.p.x<<" "<<s.p.y<<endl;
  return;
}
