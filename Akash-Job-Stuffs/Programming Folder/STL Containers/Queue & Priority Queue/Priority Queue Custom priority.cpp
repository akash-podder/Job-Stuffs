#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct Boxer{

    string name;
    int strength;

};

struct comp{

    bool operator()(const Boxer &a ,const Boxer &b)
    {
        //return a.strength>b.strength;  /* Taile jaar strength sobche "kom" taaar name sobar upor takbe */
        return a.strength<b.strength;    /* Taile jaar strength sobche "besi" taaar name sobar upor takbe */
    }

};


int main()
{
    priority_queue<Boxer,vector<Boxer> ,comp>pq;

    Boxer boxer[3];
    boxer[0].name="Neymar", boxer[0].strength=95;
    boxer[1].name="Messi", boxer[1].strength=94;
    boxer[2].name="Ronaldo", boxer[2].strength=93;

    pq.push(boxer[0]);
    pq.push(boxer[1]);
    pq.push(boxer[2]);

    Boxer b = pq.top();
    cout<<b.name;

    return 0;
}
