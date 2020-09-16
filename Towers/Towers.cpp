#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> tower(vector<int> vec){
    unordered_map<int,int> map;
    int max = 1;
    for(auto &e : vec){
        unordered_map<int,int>::const_iterator got = map.find(e);
        if(got != map.end()) {
            map[e]++;
            if(got->second > max) max = got->second;
    } else {
        map.insert({{e},{1}});
        }
    }

    vector<int> res;
    res.push_back(max);
    res.push_back(map.size());
    return res;
}

int main(int argc, char *argv[]) {

    int dimensione;
    cin >> dimensione;
    vector<int> vec;
    for(int i=0;i<dimensione;++i){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    vector<int> result = tower(vec);

    for(auto &e : result){
        cout << e << " " ;
    }
	cout << endl;

	return 0;   
}
