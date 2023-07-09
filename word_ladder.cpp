//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            string ans=q.front().first;
            int step=q.front().second;
            q.pop();
            if(ans==targetWord) return step;
            for(int i=0;i<ans.size();i++){
                char original=ans[i];
                for(char j='a';j<='z';j++){
                    ans[i]=j;
                    if(st.find(ans)!=st.end()){
                        q.push({ans,step+1});
                        st.erase(ans);
                    }
                }
                ans[i]=original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends