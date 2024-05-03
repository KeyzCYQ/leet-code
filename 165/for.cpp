#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    string v1;
    string v2;
    Test(string & V1, string & V2): v1(V1), v2(V2){};
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> rev1, rev2;
        int l1 = version1.length(), l2 = version2.length();
        int pow1 = 0, pow2 = 0;
        bool ready1 = false, ready2 = false;
        bool started1 = false, started2 = false;
        int max_length = max(l1, l2);
        int i1 = 0, i2 = 0;
        while(i1 < max_length && i2 < max_length){
            if (i1 < l1 && !ready1){
                if (version1[i1] != '.') {
                    if (version1[i1] > '0' || started1){
                        if (!started1) started1 = true;
                        rev1.push(version1[i1] - '0');
                        pow1++;
                    } 
                }
                if (version1[i1] == '.' || i1 == l1 - 1) ready1 = true;
                i1++;
            } else ready1 = true;
            if (i2 < l2 && !ready2){
                if (version2[i2] != '.') {
                    if (version2[i2] > '0' || started2){
                        if (!started2) started2 = true;
                        rev2.push(version2[i2] - '0');
                        pow2++;
                    }
                } 
                if (version2[i2] == '.' || i2 == l2 - 1) ready2 = true;
                i2++;
            } else ready2 = true;

            if (ready1 && ready2){
                if (pow1 > pow2) return 1;
                else if (pow1 < pow2) return -1;
                else{
                    while(!rev1.empty() || !rev2.empty()){
                        if (rev1.front() * pow(10, pow1) > rev2.front() * pow(10, pow1)) return 1;
                        else if (rev1.front() * pow(10, pow1) < rev2.front() * pow(10, pow1)) return -1;
                        pow1--;
                        rev1.pop(); rev2.pop();
                    }
                }

                pow1 = 0; pow2 = 0; ready1 = false; ready2 = false; started1 = false; started2 = false;
            }
        }

        return 0;
    }
};

int main(){
    string v1 = "1.9.9", v2 = "1.10.0";
    Test t = Test(v1, v2);
    cout<<Solution().compareVersion(t.v1,t.v2);
}