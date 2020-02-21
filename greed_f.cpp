//ltc.groverkss (Kunwar Shaanjeet Singh Grover)
//IIIT Hyderabad
// Mehul Mathur randi hain

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef pair<ll,ll> ii;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<ii> vii;                 // Vector of pairs
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll myrandom (ll i) { return rand()%i;}

struct Library 
{
        ll N, T, M;
        vi books;
};

vector<pair<ii, ll>> lib_check;     // ff.ff = lib id, ff.ss = end time of signup, ss = number of books which can be chosen from that lib

bool myCmp(pair<ii, ll> &a, pair<ii, ll> &b) 
{ 
    return a.ss < b.ss;
}



vi bookScore;
ll B, L, D;
vector<Library> Lib;

bool myGreedBook (ll &a, ll &b)
{
    return bookScore[a] > bookScore[b];
}

bool mySign(ll &a, ll &b)
{
    return Lib[a].M < Lib[b].M;
}

int main(void)
{
    cin >> B >> L >> D;
    bookScore.resize(B);
    Lib.resize(L);
    for (int i = 0; i < B; i++)
        cin >> bookScore[i];

    // Store input in the library
    for (int i = 0; i < L; i++)
    {
        ll N, T, M;
        cin >> N >> T >> M;
        Library temp;
        temp.N = N, temp.T = T, temp.M = M;
        temp.books.resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> temp.books[j];
        }
        Lib[i] = temp;
    }

    for (int i = 0; i < L; i++)
        sort(all(Lib[i].books), myGreedBook);
    
    // Get a random permutation of birary ids
    vi permutation(L);
    for (int i = 0; i < L; i++)
        permutation[i] = i;
    sort(all(permutation), mySign);

    ll time = 0, curr_lib = 0;

    // Greedily select library from the random permutation
    while(curr_lib != L)
    {
        if (time + Lib[permutation[curr_lib]].T >= D)
            curr_lib++;
        else
        {
            time += Lib[permutation[curr_lib]].T;
            lib_check.pb({{permutation[curr_lib], time}, 0});
            curr_lib++;
        }
    }

    // How many books can i get from each library from the random permutation?
    for (int i = 0; i < lib_check.size(); i++)
        lib_check[i].ss = min((D - lib_check[i].ff.ss) * Lib[lib_check[i].ff.ff].M, Lib[lib_check[i].ff.ff].N);

    sort(all(lib_check), myCmp);

    set<ll> found;

    vvi taken(lib_check.size());

    for (int i = 0; i < lib_check.size(); i++)
    {
        ll curr_count = 0;
        for (int j = 0; j < Lib[lib_check[i].ff.ff].N; j++)
        {
            if (found.find(Lib[lib_check[i].ff.ff].books[j]) == found.end())
            {
                found.insert(Lib[lib_check[i].ff.ff].books[j]);
                curr_count++;
                taken[i].pb(Lib[lib_check[i].ff.ff].books[j]);
            }

            if (curr_count > lib_check[i].ss)
                break;
        }
    }

    ll size_ans = lib_check.size();
    for (int i = 0; i < lib_check.size(); i++)
        if (taken[i].empty())
            size_ans--;

    cout << size_ans << "\n";

    for (int i = 0; i < lib_check.size(); i++)
    {
        if (taken[i].empty())
            continue;

        cout << lib_check[i].ff.ff << " " << taken[i].size() << "\n";
        for (auto it: taken[i])
            cout << it << " ";
        cout << "\n";
    }
}