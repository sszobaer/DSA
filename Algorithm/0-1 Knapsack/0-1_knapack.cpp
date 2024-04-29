#include <iostream>

using namespace std;

int groceries[][2] = {{3,470},{2,230},{3,360},{5,500}};

int solve(int capacity)
{
    if(capacity == 0)
    return 0;

    int ans = 0;
    for(int i=0; i<4; i++)
    {
        if(capacity-groceries[i][0]>=0)
        {
            ans = max(ans, solve(capacity - groceries[i][0]) + groceries[i][1]);
        }
    }
    return ans;
}
int main()
{
    int capacity = 10;
    int total_cost = solve(capacity);

    cout<< "Total cost: "<<total_cost<< endl;
    return 0;
}
