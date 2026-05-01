#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, vector<string>> mapa;
map<string, vector<string>> mapaInv;
map<string, bool> vis;
bool achou;

void dfs(string inicio, string fim)
{
    if (inicio == fim)
        achou = true;
    if (achou)
        return;

    vis[inicio] = true;

    for (int i = 0; i < mapa[inicio].size(); i++)
    {
        string k = mapa[inicio][i];
        if (!vis[k])
        {
            dfs(k, fim);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    map<string, bool> cleanMapa;
    map<string, bool> cleanMapaInv;

    string line, country;
    for (int i = 0; i < n; i++)
    {
        vector<string> words;
        for (int j = 0; j < 5; j++)
        {
            cin >> country;
            words.push_back(country);
        }

        mapa[words.front()].push_back(words.back());
        mapaInv[words.back()].push_back(words.front());

        cleanMapa[words.front()] = false;
        cleanMapa[words.back()] = false;
        cleanMapaInv[words.front()] = false;
        cleanMapaInv[words.back()] = false;
    }

    for (int i = 0; i < m; i++)
    {
        vector<string> words;
        for (int j = 0; j < 5; j++)
        {
            cin >> country;
            words.push_back(country);
        }

        achou = false;
        vis = cleanMapa;
        dfs(words.front(), words.back());

        if (achou)
        {
            cout << "Fact\n";
            continue;
        }

        vis = cleanMapaInv;
        dfs(words.back(), words.front());

        if (achou)
        {
            cout << "Alternative Fact\n";
            continue;
        }
        cout << "Pants on Fire\n";
    }
}
