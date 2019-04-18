#include<bits/stdc++.h>
using namespace std;
void search(int*,int*,int*,int*);
double xp,yp;
int main(){
  int n,m,p,q;
  int x[4],y[4];
  int c1[2],c2[2];
  double point;
  cin>>n>>m>>p>>q;
  for(int i=0;i<n;++i){
    cin>>x[i]>>y[i];
  }
  for(int i=0;i<m;++i){
    cin>>c1[i]>>c2[i];
    c1[i]=c1[i]-1;
    c2[i]=c2[i]-1;
  }
  search(c1,c2,x,y);
  cout<<xp<<" "<<yp<<endl;
}
void search(int c1[2],int c2[2],int x[4],int y[4]){
  int a1,a2,a3,a4,a5,a6;
  float a,s,t;
  a1 = x[c2[0]]-x[c1[0]];
  a2 = y[c1[1]]-y[c2[1]];
  a3 = x[c2[1]]-x[c1[1]];
  a4 = y[c2[0]]-y[c1[0]];
  a5 = x[c1[1]]-x[c1[0]];
  a6 = y[c1[1]]-y[c1[0]];
  //cout<<a1<<endl<<a2<<endl<<a3<<endl<<a4<<endl<<a5<<endl<<a6<<endl;
  a=a1*a2+a3*a4;
  //cout<<a<<endl;
  if(a<=0.00000001&&a>=-0.00000001)return;
  //cout<<"B";
  s = 1/a*(a2*a5+a3*a6);
  t = 1/a*((-a4*a5)+(a1*a6));
  //cout<<s<<endl<<t<<endl;
  if(s>1&&t>1&&s<0&&t<0)return;
  //cout<<"C"<<endl;
  xp = x[c1[0]]+a1*s;
  yp = x[c1[1]]+a3*t;
}
