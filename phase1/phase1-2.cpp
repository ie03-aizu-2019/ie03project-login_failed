#include<bits/stdc++.h>
using namespace std;
void search(int,int,int,int,int*,int*);
float xp,yp;
int main(){
  int n,m,p,q,cnt=0;
  int x[200],y[200];
  int b[100],e[100];
  double crossx[100],crossy[100],tmpx,tmpy;
  double point;
  cin>>n>>m>>p>>q;
  for(int i=0;i<n;++i){
    cin>>x[i]>>y[i];
  }
  for(int i=0;i<m;++i){
    cin>>b[i]>>e[i];
    b[i]=b[i]-1;
    e[i]=e[i]-1;
  }
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      search(b[i],e[i],b[j],e[j],x,y);
      if(xp!=10000||yp!=10000){
	crossx[cnt]=xp;
	crossy[cnt]=yp;
	cnt++;
      }
    }
  }
  for(int i=0;i<cnt;i++){
    for(int j=i+1;j<cnt;j++){
      if(crossx[i]>crossx[j]){
	tmpx=crossx[i];
	tmpy=crossy[i];
	crossx[i]=crossx[j];
	crossy[i]=crossy[j];
	crossx[j]=tmpx;
	crossy[j]=tmpy;
      }
    }
    for(i=0;i<cnt;i++)cout<<crossx[i]<<" "<<crossy[i]<<endl;
  }
}

void search(int c1p,int c1q,int c2p,int c2q,int x[200],int y[200]){
  int a1,a2,a3,a4,a5,a6;
  float a,s,t;
  a1 = x[c1q]-x[c1p];
  a2 = y[c2p]-y[c2q];
  a3 = x[c2q]-x[c2p];
  a4 = y[c1q]-y[c1p];
  xp=10000;
  yp=10000;
  //cout<<c1p<<endl<<c1q<<endl<<c2p<<endl<<c2q<<endl;
  a=a1*a2+a3*a4;
  //cout<<a<<endl;
  if(a==0)return;
  //cout<<"B";
  s = ((y[c2p]-y[c2q])*(x[c2p]-x[c1p])+(x[c2q]-x[c2p])*(y[c2p]-y[c1p]))/a;
  t = ((y[c1p]-y[c1q])*(x[c2p]-x[c1p])+(x[c1q]-x[c1p])*(y[c2p]-y[c1p]))/a;
  //cout<<s<<" "<<t<<endl;
  if(s>0&&s<1&&t>0&&t<1){
  //cout<<"C"<<endl;
  xp = x[c1p]+a1*s;
  yp = y[c1p]+a4*s;
  }
  else return;
}
