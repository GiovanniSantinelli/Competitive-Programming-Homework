#include <iostream>
#include <vector>
#include <unordered_map>
/*
Since we are not actually instered in the values of the "bars" but only on how many towers we have and the height of the largest tower, using a map we can store each number one
at a time using the value as the key and the number it has been repeted as the value. Before inserting the number we check if it's already there so we need to scan the keys,
that costs O(1) in the average case. We also keep track of the max bar height just checking each time we try to insert an element that is already in, if it's "height" is 
larger than the maximum one. At the end we return the  max value and the size of the map, the total cost should be linear.
*/
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
