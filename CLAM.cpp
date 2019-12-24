#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int,int> ii;
int area_[1002][1002];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		cin>>area_[i][j];
    int t,redline;
    cin>>t>>redline;
    while(t--){
    	int option; cin>>option;
    	if(option==1){
    		int ans=0,kg_;
    		int col1,col2,row1,row2;
    		cin>>kg_>>col1>>row1>>col2>>row2;
    		int k=0;
    		for(int i=row1;i<=row2;i++){
    			if(k%2==0){
    				for(int j=col1;j<=col2;j++){
    					if(area_[i][j]<=redline) continue;
    					if(ans>=kg_) break;
    					int tmp = area_[i][j]-redline;
    					if(ans+tmp<=kg_){
    						ans+=tmp;
    						area_[i][j]=redline;
    					}
    					else if(kg_- ans < tmp){
    						ans+=area_[i][j]-(kg-ans);
    						area_[i][j]-=(kg-ans);
    					}
    				}
    			}
    			else{
    				for(int j=col2;j>=col1;j--){
    					if(area_[i][j]<=redline) continue;
    					if(ans>=kg_) break;
    					int tmp = area_[i][j]-redline;
    					if(ans+tmp<=kg_){
    						ans+=tmp;
    						area_[i][j]=redline;
    					}
    					else if(kg_- ans < tmp){
    						ans+=area_[i][j]-(kg-ans);
    						area_[i][j]-=(kg-ans);
    					}
    				}
    			}
    			k++
    		}
    		cout<<ans<<end;
    	}
    	else{
    		cin>>redline;
    	}
    }
	return 0;
}