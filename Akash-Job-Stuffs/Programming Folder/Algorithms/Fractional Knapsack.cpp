#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    double weight,price,unitprice;
} object;


double fractionalKnapsack(object obj[],int n, double capacity)
{
    int i,j;
    object t;
    double profit = 0.0;

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(obj[i].unitprice<obj[j].unitprice)
            {
                t=obj[i];
                obj[i]=obj[j];
                obj[j]=t;
            }
        }
    }

    /*for(i=0;i<n;i++){
        cout << "w" << i << "= " << obj[i].weight << ", p" << i << "= " << obj[i].price << endl;
    }*/

    for(i=0; i<n; i++)
    {
        if(obj[i].weight < capacity)
        {
            profit += obj[i].price;
            capacity -= obj[i].weight;
        }

        else
        {
            profit += capacity*obj[i].unitprice;
            capacity = 0.0;
            break;
        }
    }

    return profit;
}


int main()
{
    int n,i;
    double capacity;

    cin>>n;

    object obj[n];

    for(i=0; i<n; i++)
    {
        cin >> obj[i].weight >> obj[i].price;
        obj[i].unitprice = obj[i].price/obj[i].weight;
    }

    cin >> capacity;

    cout << "Maximum Profit: " << fractionalKnapsack(obj,n,capacity) << endl;

    return 0;
}
/*
5
4 8
7 7
6 3
5 15
8 12
15
*/
