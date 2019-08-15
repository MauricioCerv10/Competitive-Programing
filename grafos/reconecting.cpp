#include <bits/stdc++.h>
using namespace std;

int caso;

class UnionFind{
	private: vector<int> p;
	private: vector<int> rank;

	public: UnionFind(int N){
		rank.assign(N,0);
		p.assign(N,0);
		for(int i = 0; i<N; i++) 
			 p[i] = i;
	}

	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i), y = findSet(j);
			if( rank[x] > rank[y] ) p[y] = x;
			else{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};



int main(){
	int V;
	while(cin>>V){
		vector< pair< int, pair<int,int> > > EList;
		if(caso++) cout<<"\n";
		int E,K,w,u,v,oc;
		oc = 0;
		for(int i = 0; i < V-1; i++){
			cin>>u>>v>>w;
			oc += w;
		}
		cin>>K;
		for(int i = 0;  i<K; i++){
			cin>>u>>v>>w;
			pair<int,int> e(u,v);
			EList.push_back(make_pair(w,e));
		}
		cin>>E;
		for(int i = 0;  i<E; i++){
                        cin>>u>>v>>w;
                        pair<int,int> e(u,v);
                        EList.push_back(make_pair(w,e));
                }

		sort(EList.begin(), EList.end());

		int mst_cost = 0;
		UnionFind UF(V);
		for(int i = 0; i<E; i++){
			pair<int, pair<int,int>> front = EList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		cout<<oc<<"\n";
		cout<<mst_cost<<"\n";
	}
}
