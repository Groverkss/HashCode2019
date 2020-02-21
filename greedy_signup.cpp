#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)//remember i is an iterator
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
struct library
{
	ll b,sgup,bkday,id;
};
bool mysort(library a,library b)
{
	if(a.sgup < b.sgup)
	{
		return true;
	}
	if(a.sgup == b.sgup)
	{
		/*if(a.id %2 ==0) return true;
		else*/ return false;
	}
	return false;
}
	ll bscore[200000],flag[200000]={0}/*,nm[300000]={0}*/,flag1[200000]={0};
int main()
{
	ll bks,lbry,days;
	cin>>bks>>lbry>>days;
	for (int i = 0; i < bks; ++i)
	{
		cin>>bscore[i];
	}	
	vector<vector<ll>> adj(lbry);
	vector<library> vlbr(lbry);
	for(int i=0;i<lbry;i++)
	{
		cin>>vlbr[i].b>>vlbr[i].sgup>>vlbr[i].bkday;
		vlbr[i].id=i;
		for(int j=0;j<vlbr[i].b;j++)
		{
			ll tmp1;
			cin>>tmp1;
			adj[i].pb(tmp1);
			// nm[tmp1]++;
		}
		if(i%2!=0)
		{
			if(vlbr[i].b>vlbr[i-1].b)
			{
				vlbr[i-1].b--;
				flag[i-1]=1;
			}
			else
			{
				vlbr[i].b--;
				flag[i]=1;
			}
		}
	}
	sort(all(vlbr),mysort);
	int nl=0;
	pair<ll,ll> pr[200000];
	for(int i=0;i<lbry;i++)
	{
		days-=vlbr[i].sgup;
		pr[i].ff=vlbr[i].id;
		pr[i].ss=min(days*vlbr[i].bkday,vlbr[i].b);
		if(days<0) break;
		nl++;
	}
	cout<<nl<<endl;
	for(int i=0;i<nl;i++)
	{
		cout<<pr[i].ff<<" ";
/*		if(flag[pr[i].ff]==1) cout<<pr[i].ss-1<<endl;
		else*/ cout<<pr[i].ss<<endl;
		// cout<<endl;
		int tmp2=0;
		vi v2;
		for(int j=0;j<adj[pr[i].ff].size();j++)
		{
			// if(flag[pr[i].ff]==1 && j==0) continue;
			if(flag1[adj[pr[i].ff][j]]==0)
			{
				flag1[adj[pr[i].ff][j]]=1;
				cout<<adj[pr[i].ff][j]<<" ";
				tmp2++;
			}
			else
			{
				v2.pb(adj[pr[i].ff][j]);
			 continue;
			}	
			if(tmp2==pr[i].ss) break;

		}
		int tmp3=0;
		while(tmp2<pr[i].ss)
		{
			cout<<v2[tmp3++]<<" ";
			tmp2++;
		}
		cout<<endl;
// 				cout<<pr[i].ff<<" ";
// /*		if(flag[pr[i].ff]==1) cout<<pr[i].ss-1<<endl;
// 		else*/ cout<<pr[i].ss<<endl;
// 		// cout<<endl;
// 		//int tmp2=0;
// 		// vi v2;
// 		for(int j=0;j<pr[i].ss;j++)
// 		{
// 			// if(flag[pr[i].ff]==1 && j==0) continue;
// 			if(flag1[adj[pr[i].ff][j]]==0)
// 			{
// 				flag1[adj[pr[i].ff][j]]=1;
// 				cout<<adj[pr[i].ff][j]<<" ";
// 				tmp2++;
// 			}
// 			else
// 			{
// 				v2.pb(adj[pr[i].ff][j]);
// 			 continue;
// 			}	
// 			if(tmp2==pr[i].ss) break;

// 		}
// 		int tmp3=0;
// 		while(tmp2<pr[i].ss)
// 		{
// 			cout<<v2[tmp3++]<<" ";
// 		}
// 		cout<<endl;

	}
	return 0;
}