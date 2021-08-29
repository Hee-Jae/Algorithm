#include <iostream>
#include <cmath>

using namespace std;

double N, x,y, maxv = -1, dist, mx1, my1, mx2, my2;
double pos[1002][2]={};

double power(double x){
  return x*x;
}
double getdist(double x1, double x2, double y1, double y2){
  double res = 0;
  res = power(x1-x2) + power(y1-y2);
  return sqrt(res);
}

double realdist(double a, double b, double c, double x1, double y1){
  cout << a << " " << b << " " << c << " " << x1 << " " << y1 << "\n";
  double res, m,d;
  m = abs(a*x1+b*y1+c);
  d = sqrt(a*a+b*b);
  cout << "m : " << m << " d : " << d << "\n";
  res = m/d;
  return res;
}

double getx(double a, double b, double c, double d, double e, double f){
  return (f-(c*e)/b)/((a*e)/b-d);
}

double gety(double a, double b, double c, double d, double e, double f){
  return (f-(c*d)/a)/((b*d)/a-e);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> x >> y;
    pos[i][0] = x;
    pos[i][1] = y;
  }

  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      dist = getdist(pos[i][0], pos[j][0], pos[i][1], pos[j][1]);
      if(maxv < dist){
        maxv = dist;
        mx1 = pos[i][0];
        mx2 = pos[j][0];
        my1 = pos[i][1];
        my2 = pos[j][1];
      }
    }
  }
  // cout << mx1 << my1 << mx2 << my2;
  double midx, midy, slope;
  midx = (mx1+mx2)/2;
  midy = (my1+my2)/2;
  // cout << midx << " " << midy;
  slope = -((mx2-mx1)/(my2-my1));
  double b = midy - (slope * midx);
  double reald, min=987654321;
  double minx, miny, resx, resy, f, tx, ty;
  for(int i=0; i<N; i++){
    f = pos[i][1] - ((-1/slope)*pos[i][0]);
    tx = getx(slope,-1,b,-1/slope,-1,f);
    ty = gety(slope,-1,b,-1/slope,-1,f);
    cout << "tx : " << tx << " ty : " << ty << "\n";
    // reald = realdist(slope, -1, b, pos[i][0], pos[i][1]);
    reald = getdist(tx,ty,pos[i][0],pos[i][1]) + getdist(tx,ty,mx1,my1);
    // cout << "reald : " << reald << "\n";
    if(reald < min){
      min = reald;
      minx = tx;
      miny = ty;
    }
  }
  cout <<"res : " << minx << " " << miny;
}