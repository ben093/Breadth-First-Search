#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <math.h> 
#include <string>
#include <unordered_map>
#include <typeinfo>
#include <queue>
using namespace std;

// g++ -std=c++11 -Wall hw5.cpp
// a < hw5_test.txt

string name1, name2;

unordered_map <string, vector<string>> graph;
unordered_map <string, string> color;
unordered_map <string, int> d;

void BFS(string s)
{	
	vector<string> Q {s};

	vector<string> babyfaces;
	vector<string> heels;
	
	while(!Q.empty())
	{
		string u = Q.front();
		Q.erase(Q.begin());
		
		for(auto v: graph[u])
		{
			if(color[v] == "WHITE")
			{
				color[v] = "GRAY";
				d[v] = d[u] + 1;
				
				Q.push_back(v);	
			}
		}
		color[u] = "BLACK";
	}	
	
	for(auto x:graph)
	{
		for(int i =0; i < (int)x.second.size(); ++i)
		{
			if(d[x.first] % 2 == d[x.second.at(i)] % 2)
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	
	//check if babyface or heel
	for(auto v: graph)
	{
		if(d[v.first] % 2 == 0)
		{
			babyfaces.push_back(v.first);
		}
		else
		{
			heels.push_back(v.first);
		}
	}
	
	
	
	sort(babyfaces.begin(), babyfaces.end());
	sort(heels.begin(), heels.end());
	
	cout << "BABYFACES" << endl;
	for(auto a: babyfaces)
	{
		cout << a << endl;
	}
	
	cout << "HEELS" << endl;
	for(auto a: heels)
	{
		cout << a << endl;
	}
	
	
}	

int main()
{	
	
	vector<string> x;
	
	string start;
	while(cin >> name1 >> name2)
	{
		if(graph.empty())
		{
			start = name1;
		}
		
		if(graph.count(name1) == 0)
		{
			if(graph.count(name2) == 0)
			{ 	//neither are in
				graph.emplace(name1, x);
				color.emplace(name1, "WHITE");
				d.emplace(name1, 0);
				
				graph.emplace(name2, x);
				color.emplace(name2, "WHITE");
				d.emplace(name2, 0);
				
				graph[name1].push_back(name2);
				graph[name2].push_back(name1);
			}
			else
			{ 	//name1 is not in, but name2 is
				graph.emplace(name1, x);
				color.emplace(name1, "WHITE");
				d.emplace(name1, 0);
				
				graph[name1].push_back(name2);
				graph[name2].push_back(name1);
			}
		}
		else if(graph.count(name1) > 0)
		{
			if(graph.count(name2) == 0)
			{ 	//name1 is in, but not name2
				graph.emplace(name2, x);
				color.emplace(name2, "WHITE");
				d.emplace(name2, 0);
				
				graph[name1].push_back(name2);
				graph[name2].push_back(name1);
			}
			else
			{	//both are in
				graph[name1].push_back(name2);
				graph[name2].push_back(name1);
			}
		}
	}
	
	BFS(start);
	
}