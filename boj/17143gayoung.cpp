#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R,C,M;
int map[102][102]={};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

typedef struct{
	int y;
	int x;
	int speed;
	int dir;
	int size;
}S;

vector<S> v;

int shark_sum = 0;

int v_dir(int dir){
	if(dir == 1)
		return 2;
	if(dir == 2)
		return 1;
	if(dir == 3)
		return 4;
	if(dir == 4)
		return 3;
	return -1;
}

void grasp(int x){
	vector<S> temp_v;
	int s_i = -1;
  
	for(int i=1; i<=R; i++){
		if(map[i][x] != 0){
			s_i = i;
			shark_sum += map[i][x];
			map[i][x] = 0;
			break;
		}
	}
  
	if(s_i == -1){
    // if(x==5) cout << "here\n";
    return;
  }
		
	for(int i=0; i<v.size(); i++){
		if((v[i].y==s_i) && (v[i].x==x))
			continue;
		temp_v.push_back(v[i]);
	}
	v.clear();
	v.assign(temp_v.begin(), temp_v.end());
}

void move(){
	queue<S> q;
	vector<S> temp_v;
	
	int cmap[102][102] = {0,};
  // cout << "move vsize : " << v.size() << "\n";
	for(int k=0; k<v.size(); k++)
		q.push(v[k]);

	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;

		int speed = q.front().speed;
		int dir = q.front().dir;
		int size = q.front().size;
		q.pop();
    // cout << "move qsize : " << q.size() << "\n";
		for(int i=0; i<speed; i++){
      if((y==1) && dir == 1)
				dir = v_dir(dir);
			else if((x==1) && dir == 4)
				dir = v_dir(dir);
			else if((y==R) && dir == 2)
				dir = v_dir(dir);
			else if((x==C) && dir == 3)
				dir = v_dir(dir);

			y += dy[dir-1];
			x += dx[dir-1];
		}

		if(cmap[y][x] == 0){
			cmap[y][x] = size; 
			S shark;
			shark.y = y;
			shark.x = x;
			shark.speed = speed;
			shark.dir = dir;
			shark.size = size;
			temp_v.push_back(shark);
		}
		
		else{
      int vs;
			if(cmap[y][x] < size){
        for(vs=0; vs<temp_v.size(); vs++){
          if(temp_v[vs].y == y && temp_v[vs].x == x) break;
        }
				cmap[y][x] = size;
				// S shark;
				// shark.y = y;
				// shark.x = x;
				// shark.speed = speed;
				// shark.dir = dir;
				// shark.size = size;
				// temp_v.push_back(shark);
        temp_v[vs].y = y;
        temp_v[vs].x = x;
        temp_v[vs].speed = speed;
        temp_v[vs].dir = dir;
        temp_v[vs].size = size;
			}	
		}
	}
	v.clear();
	v.assign(temp_v.begin(), temp_v.end());
	
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			map[i][j] = cmap[i][j];
		}
	}
}

void sol(){
	for(int i=1; i<=C; i++){
    // cout << "i : " << i << " | vsize : "<< v.size() << "\n";
    
		grasp(i);
		move();
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>R>>C>>M;

	for(int i=0; i<M; i++){
		S shark;
		cin>>shark.y>>shark.x>>shark.speed>>shark.dir>>shark.size;
		map[shark.y][shark.x] = shark.size;
		v.push_back(shark);
	}

	sol();

	cout<<shark_sum<<"\n";
	return 0;
}