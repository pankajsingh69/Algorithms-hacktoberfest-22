#include<bits/stdc++.h>
using namespace std;

#define endl            "\n"
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void d_m_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input_dc.txt", "r", stdin);
	freopen("output_dc.txt", "w", stdout);
#endif
}

bool cowPlaced(int *a, int n, int c, int min_sep)
{
	int cnt = 1;
	int last_cow = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] - last_cow >= min_sep)
		{
			cnt++;
			last_cow = a[i];

			if (cnt == c)
				return true;
		}
	}

	return false;
}

int32_t main()
{

	d_m_c();

	w(t)
	{
		int n, c;
		cin >> n >> c;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		int s = a[0];
		int e = a[n - 1] - a[0];

		int ans = 0;

		while (s <= e)
		{
			int mid = s + (e - s) / 2;

			bool cowRakhPaye = cowPlaced(a, n, c, mid);

			if (cowRakhPaye)
			{
				ans = mid;
				s = mid + 1;
			}
			else
				e = mid - 1;
		}

		cout << ans << endl;
	}

	return 0;
}
