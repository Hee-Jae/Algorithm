#include <iostream>
using namespace std;
int in[100001]={}, inPos[100001]={};
int post[100001]={};
void make_tree(int in_start, int in_end, int post_start, int post_end){
  if(in_start > in_end) return;
  if(post_start > post_end) return;
  else{
    cout << post[post_end] << " ";
    int root = inPos[post[post_end]];
    // cout << node*2 << " " << in_start << " " << root-1 << " " << post_start << " " << post_start+root-1-in_start << "\n";
    // cout << node*2+1 << " " << root+1 << " " << in_end << " " << post_start+root-in_start << " " << post_end-1 << "\n";
    // cout << node << " " << in_start << " " << in_end << " " << post_start << " " << post_end << "\n";
    make_tree(in_start, root-1, post_start, post_start+root-1-in_start);
    make_tree(root+1, in_end, post_start+root-in_start, post_end-1);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> in[i];
    inPos[in[i]] = i;
  }
  for(int i=0; i<n; i++){
    cin >> post[i];
  }
  make_tree(0,n-1,0,n-1);
}