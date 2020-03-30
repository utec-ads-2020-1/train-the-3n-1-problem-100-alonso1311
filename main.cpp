#include<iostream>
#include<vector>
#include<string>

#include<boost/algorithm/string.hpp>
#include<boost/algorithm/string/split.hpp>

using namespace std;

int get_Count(int);

int main() {
    vector<string> result;
    string line;
    int i, j;

    while(getline(cin, line) && !line.empty()) {
        int max = 1;
        vector<string> temp_line;
        boost::split(temp_line, line, boost::is_any_of(" "));

        i = stoi(temp_line[0]);
        j = stoi(temp_line[1]);

        for(; i < j; i++) 
            if(max < get_Count(i))
                max = get_Count(i);
        

        result.push_back(to_string(i) + " " + to_string(j) + " " + to_string(max));
    }

    for(auto const& i : result) 
        cout << i << endl;

    return 0;
}

int get_Count(int n) {
    int count = 1;

    while(n != 1){
        if(n%2 == 0){
            n = n/2;
            count++;
        } else {
            n = (3*n)+1;
            count++; 
        }
    }

    return count;
}
