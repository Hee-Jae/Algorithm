#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  char time[10]={}, doh[10]={};
  cin >> time >> doh;
  int nh, nm, ns;
  int dh, dm, ds;
  nh = (time[0]-'0')*10 + (time[1]-'0');
  nm = (time[3]-'0')*10 + (time[4]-'0');
  ns = (time[6]-'0')*10 + (time[7]-'0');

  dh = (doh[0]-'0')*10 + (doh[1]-'0');
  dm = (doh[3]-'0')*10 + (doh[4]-'0');
  ds = (doh[6]-'0')*10 + (doh[7]-'0');
  // cout << nh << ":" << nm << ":" << ns << "\n";
  // cout << dh << ":" << dm << ":" << ds << "\n";

  int ah, am, as;
  if(ds - ns < 0){
    as = ds+60-ns;
    dm --;
  }
  else as = ds-ns;
  if(dm - nm < 0){
    am = dm+60-nm;
    dh --;
  }
  else am = dm-nm;
  if(dh - nh < 0) ah = dh+24-nh;
  else ah = dh-nh;

  char ans[10]={};
  if(ah<10){
    ans[0]='0';
    ans[1]=(char)(ah+'0');
  }
  else{
    ans[1]=(char)(ah%10+'0');
    ans[0]=(char)(ah/10+'0');
  }
  if(am<10){
    ans[3]='0';
    ans[4]=(char)(am+'0');
  }
  else{
    ans[4]=(char)(am%10+'0');
    ans[3]=(char)(am/10+'0');
  }
  if(as<10){
    ans[6]='0';
    ans[7]=(char)(as+'0');
  }
  else{
    ans[7]=(char)(as%10+'0');
    ans[6]=(char)(as/10+'0');
  }
  ans[2]=':';
  ans[5]=':';
  for(int i=0; i<=7; i++) cout << ans[i];
}