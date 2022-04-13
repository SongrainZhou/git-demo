#include <iostream>
#include<unordered_map>
#include<string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution
{
private:
    int A(int a){
        int sum = 0;
        while(a){
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }
    int ans = 0;
    int my_m, my_n;
    int my_k;
    vector<vector<int>> visited;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i,int j){
        if(i<0||i>=my_m||j<0||j>=my_n||visited[i][j]||A(i)+A(j)>my_k){
            return;
        }
        visited[i][j] = 1;
        ans++;
        for (int cur = 0; cur < 4;cur++){
            dfs(i + dir[cur][0], j + dir[cur][1]);
        }
    }
public:
    int movingCount(int m, int n, int k)
    {
        my_m = m;
        my_n = n;
        my_k = k;
        vector<vector<int>> v(m, vector<int>(n, 0));
        visited = v;
        dfs(0, 0);
        return ans;
    }
};
int main(){
    Solution sl;
    cout<<sl.movingCount(3, 1, 0);
}
#this is a remote change.
