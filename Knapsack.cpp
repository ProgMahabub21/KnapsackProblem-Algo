//priority_queue in C++

#include <iostream>
#include <queue>
using namespace std;

#define Num 5
#define Attr 3

class Item {

public:
    float weight;
    float profit;
    float Vindex;
    bool operator < (const Item &Q) const
    {
        return Vindex < Q.Vindex;
    }
};

void displayPQ(priority_queue<Item> Items,int limit){
    float maxProfit =0;
    float currentWeight=0;
    Item p;

    while (!Items.empty()) {
        p = Items.top();
        Items.pop();
        cout << "Weight : " << p.weight << ", Profit : " << p.profit << ", Value Index: " << p.Vindex << "\n";

        if (currentWeight + p.weight <= limit) {
            maxProfit += p.profit;
            currentWeight += p.weight;

        } else {
            int rem = limit - currentWeight;
            maxProfit += (rem * p.Vindex);
            currentWeight += rem;
        }
    }
    cout<<"knapsack Weight limit: "<<limit<<endl;
    cout<<"Max profit is: "<<maxProfit<<endl;

}

int main()
{
    priority_queue<Item> Items;
    int value =0;
    float data[Num][Attr] = {
            { 6, 5},
            { 2, 3},
            { 2, 2},
            { 3, 4},
            { 2, 1},
    };

    for (int i = 0; i < Num; ++i) {
        Item p = Item{data[i][0], data[i][1],(data[i][1]/data[i][0])};
        Items.push(p);
    }
    cout<<"//note: weights unit (kg/pound/any), profit unit(any int./local currency), value_index=profit/weight"<<endl;
    cout<<"Enter knapsack value(weight limit) :"<<endl;
    cin>>value;

    displayPQ(Items,value);

    return 0;
}
