#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Test{
    vector<int> & arr;
    int k;
    Test(vector<int> & Arr, int K): arr(Arr), k(K){};
};

class Solution {
public:
    float fract(vector<vector<int>> & heap, int i){
        return float(heap[i][0])/float(heap[i][1]);
    }

    void h_swap(vector<vector<int>> & heap, int i, int j){
        swap(heap[i][0], heap[j][0]);
        swap(heap[i][1], heap[j][1]);
    }

    void heapifyUp(vector<vector<int>> & heap, int i){
        int p = (i-1)/2;
        while(i > 0 && fract(heap, i) < fract(heap, p)){
            h_swap(heap, i, p);
            i = p;
            p = (i-1)/2;
        }
    }

    void heapifyDown(vector<vector<int>> & heap, int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int small = i;

        if(l < heap.size() && fract(heap, l) < fract(heap, small)) small = l;
        if(r < heap.size() && fract(heap, r) < fract(heap, small)) small = r;

        if (small != i){
            h_swap(heap, i, small);
            heapifyDown(heap, small);
        }
    }

    void h_insert(vector<vector<int>> & heap, int v0, int v1){
        vector<int> v = {v0, v1};
        heap.push_back(v);
        heapifyUp(heap, heap.size() - 1);
    }

    vector<int> extract(vector<vector<int>> & heap){
        vector<int> min = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(heap, 0);
        
        return min;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> heap;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                h_insert(heap, arr[i], arr[j]);
            }
        }

        for (int i = 0; i < k-1; i++){
            extract(heap);
        }

        return extract(heap);
    }
};

int main(){
    vector<int> arr = {1,29,47};
    Test t = Test(arr, 1);
    vector<int> sol = Solution().kthSmallestPrimeFraction(t.arr, t.k);
    cout<<sol[0]<<" "<<sol[1];
}