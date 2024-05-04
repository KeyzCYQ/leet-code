#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    vector<int> & people;
    int limit;
    Test(vector<int> & People, int Limit): people(People), limit(Limit){};
};

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 1;
        int n = people.size();

        sort(people.begin(), people.end());
        
        int i = 0, j = n - 1;

        while(i <= j){
            if (people[i] + people[j] <= limit) i++;
            j--;
            boats++;
        }


        return boats;
    }
};

int main(){
    vector<int> people = {2,49,10,7,11,41,47,2,22,6,13,12,33,18,10,26,2,6,50,10};
    Test t = Test(people, 50);
    cout<<Solution().numRescueBoats(t.people, t.limit);
}