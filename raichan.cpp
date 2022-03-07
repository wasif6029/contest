#include <bits/stdc++.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/

//-----------------------------------------TEMPLATES-----------------------------------------//

#define read freopen("in2.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define file_io read; // write
#define all(container) container.begin(), container.end()
//------------------------------------END OF TEMPLATES------------------------------------//

// All necessary functions go here

class Contributor
{
public:
    string Name;
    map<string, int> Skill;
    bool ready = false;
    void setC(string nn, map<string, int> ss)
    {
        Name = nn;
        Skill = ss;
    }
};

class Project
{
public:
    string Name;
    map<string, int> Skill;
    int duration, best_before, score;
    void setP(string pn, map<string, int> psk, int pd, int pbb, int pss)
    {
        Name = pn;
        Skill = psk;
        duration = pd;
        best_before = pbb;
        score = pss;
    }
};

bool comparefn(Project a, Project b)
{
    return a.best_before <= b.best_before;
}

// end of allotment for necessary functions

int main()
{
    read;
    write;

    // Start code
    int nContributors, nProjects;
    cin >> nContributors >> nProjects;

    vector<Contributor> cc;
    vector<Project> pp;
    vector<string, vector<string>> output;

    for (size_t i = 0; i < nContributors; i++)
    {
        string cname;
        int cskillno;
        map<string, int> cskills;
        cin >> cname >> cskillno;

        while (cskillno--)
        {
            string sname;
            int slevel;
            cin >> sname >> slevel;

            cskills[sname] = slevel;
        }
        Contributor ccc;
        ccc.setC(cname, cskills);

        cc.push_back(ccc);
    }

    for (size_t i = 0; i < nProjects; i++)
    {
        string cname;
        int pduration, pbbefore, pscore, pskillno;
        map<string, int> cskills;
        cin >> cname >> pduration >> pscore >> pbbefore >> pskillno;

        while (pskillno--)
        {
            string sname;
            int slevel;
            cin >> sname >> slevel;

            cskills[sname] = slevel;
        }
        Project ppp;
        ppp.setP(cname, cskills, pduration, pbbefore, pscore);
        pp.push_back(ppp);
    }

    sort(all(pp), comparefn);

    for (size_t i = 0; i < pp.size(); i++)
    {
        cout << pp[i].Name << " " << pp[i].best_before << endl;
    }

    // end code
}
// i
// reset && g++ -DLOCAL -o main main.cpp && ./main
// cls && g++ -DLOCAL -o main main.cpp && main