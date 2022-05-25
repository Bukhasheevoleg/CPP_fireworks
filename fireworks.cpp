// fireworks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
bool u[1111111];
vector <int> q[1111111];
vector <int> v;
int z = 1;
long long d[1111111];
long long ans = 0;
void dfs(int x, long long l, int y) {
	//cout<<x<<endl;

	ans = max(ans, l);

	if (q[x].size() == 1 && y == 1) {

		if (d[z] < l) {
			z = x;
			d[z] = l;
		};
		// cout<<x<<" "<<l<<endl;
	}

	u[x] = true;
	for (int i = 0; i < q[x].size(); i++) {
		if (u[q[x][i]]) continue;
		dfs(q[x][i], l + 1, y);
	}



}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++) {
		int x;
		cin >> x;
		q[x].push_back(i + 1);
		q[i + 1].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (q[i].size() == 1) {
			v.push_back(i);


		}
	}
	//cout<<x<<endl;
	dfs(1, 1, 1);
	for (int i = 1; i <= n; i++) {
		u[i] = false;
	}
	//cout<<z<<endl;
	dfs(z, 1, 2);
	//cout<<d[z]<<endl;
	if (m != 1) {


		for (int i = 1; i <= m - 1; i++) {
			ans += 2 * d[z];
		}
		cout << ans << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}

