#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <istream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Node{
	public:
		int value;
		int freq;
		vector<int> stuff;
};

struct Comp{
	bool operator ()(const Node& a, const Node& b) {
		if(a.freq == b.freq){
			return a.value > b.value;
		}
  		return a.freq > b.freq;
  	}
};

int main(int argc, char* argv[]){
	Node node[5000];
	ifstream fin;
	ofstream fout1;
	ofstream fout2;
	int k=atoi(argv[1]);
	fin.open(argv[2]);
	fout1.open(argv[3]);
	fout2.open(argv[4]);
	int asc=0;
	int freq=0;
	int arr[5000];
	int count=0;
	int fill=128;
	while(fin>>asc){
		fin>>freq;
		arr[asc]=freq;
		count++;
	}	
	while(!(count%(k-1)==1)){
		count++;
		if(count%(k-1)==1){
			break;
		}
		arr[fill]=0;
		fill++;
	}
int l=0;
for (int k = 32; k < count+32; ++k){
		if(k<128 && arr[k]==0){
			count++;
		}
		else{
			node[l].freq=arr[k], node[l].value=k;
			l++;
		}
	}
priority_queue<Node, vector<Node>,Comp>pq;
for(int x=0;x<=l;x++){
	if(node[x].value==0){
		continue;
	}
	pq.push(node[x]);
	}	
	int countera=0;
	int counterb=0;
	int counterc=0;
	int counterd=0;
	int countere=0;
	int counterf=0;
	int counterg=0;
	int stuffa[5000];
	int stuffb[5000];
	int stuffc[5000];
	int stuffd[5000];
	int stuffe[5000];
	int stufff[5000];
	int stuffg[5000];
	int m=0;
	for(int y=0;y<k;y++){
		countera+=pq.top().freq;
		stuffa[y]=pq.top().value;
		pq.pop();
		}
	bool flag=true;
	for (int i = 0; i<k; ++i){
		if (pq.top().freq>countera){
			if(flag==true){
				counterb+=countera;
				stuffb[i]=256+m;
				m++;
				i++;
				counterb+=pq.top().freq;
				stuffb[i]=pq.top().value;
				pq.pop();
				flag=false;
			}
		}
		else{
				counterb+=pq.top().freq;
				stuffb[i]=pq.top().value;
				pq.pop();
		}
	}
	flag=true;
for (int i = 0; i<k; ++i){
	if (pq.top().freq>counterb){
		if(flag==true){
				counterc+=counterb;
				stuffc[i]=256+m;
				m++;
				i++;
				counterc+=pq.top().freq;
				stuffc[i]=pq.top().value;
				pq.pop();
				flag=false;
			}
		}
		else{
				counterc+=pq.top().freq;
				stuffc[i]=pq.top().value;
				pq.pop();
		}
	}	
flag=true;
	for (int i = 0; i<k; ++i){
		if (pq.top().freq>counterc){
			if(flag==true){
				counterd+=counterc;
				stuffd[i]=256+m;
				m++;
				i++;
				counterd+=pq.top().freq;
				stuffd[i]=pq.top().value;
				pq.pop();
				flag=false;
			}
		}
		else{
				counterd+=pq.top().freq;
				stuffd[i]=pq.top().value;
				pq.pop();
		}
	}	
flag=true;
	for (int i = 0; i<k; ++i){
		if (pq.top().freq>counterd){
			if(flag==true){
				countere+=counterd;
				stuffe[i]=256+m;
				m++;
				i++;
				countere+=pq.top().freq;
				stuffe[i]=pq.top().value;
				pq.pop();
				flag=false;
			}
		}
		else{
				countere+=pq.top().freq;
				stuffe[i]=pq.top().value;
				pq.pop();
		}
	}
flag=true;
	for (int i = 0; i<k; ++i){
		if (pq.top().freq>countere){
			if(flag==true){
				counterf+=countere;
				stufff[i]=256+m;
				m++;
				i++;
				counterf+=pq.top().freq;
				stufff[i]=pq.top().value;
				pq.pop();
				flag=false;
			}
		}
		else{
				counterf+=pq.top().freq;
				stufff[i]=pq.top().value;
				pq.pop();
		}
	}
	flag=true;
	for (int i = 0; i<k; ++i){
		if (pq.top().freq>counterf){
			if(flag==true){
				counterg+=counterf;
				stuffg[i]=256+m;
				m++;
				i++;
				counterg+=pq.top().freq;
				stuffg[i]=pq.top().value;
				pq.pop();
				flag=false;
			}
		}
		else{
				counterg+=pq.top().freq;
				stuffg[i]=pq.top().value;
				pq.pop();
		}
	}
						
for(int i=0;i<k;i++){
	fout2<<stuffa[i]<<endl;
	}

for(int i=0;i<k;i++){
	fout2<<stuffb[i]<<endl;
}for(int i=0;i<k;i++){
	fout2<<stuffc[i]<<endl;
}for(int i=0;i<k;i++){
	fout2<<stuffd[i]<<endl;
}for(int i=0;i<k;i++){
	fout2<<stuffe[i]<<endl;
}for(int i=0;i<k;i++){
	fout2<<stufff[i]<<endl;
}for(int i=0;i<k;i++){
	fout2<<stuffg[i]<<endl;
}

	return 0;
}