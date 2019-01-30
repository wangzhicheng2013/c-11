#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Customer
{
public:
    Customer()
    {
        id = 0;
        service_time = 0;
        wait_time = 0;
    }
    Customer(int id, int t)
    {
        this->id = id;
        service_time = t;
        wait_time = 0;
    }
    inline int GetServiceTime() const 
    {
        return service_time;
    }
    inline void SetWaitTime(int t) 
    {
        wait_time = t;
    }
    inline int GetWaitTime() 
    {
        return wait_time;
    }
private:
    int id;
    int service_time; 
    int wait_time; 
};
class Service
{
public:
    bool Init(int n)
    {
        if (n <= 0 || n > MAX_CUSTOMERS)
        {
            cerr << n << " for customers is invalid...!" << endl;
            return false;
        }
        int t;
        for (int i = 0;i < n;i++)
        {
            cout << "id = " << i << " customer service time = ";
            cin >> t;
            if (!cin.good())
            {
                return false;
            }
            customers.emplace_back(Customer(i, t));
        }
        return true;
    }
    void ComputeAvgWaitTime(double &avg_wait_time)
    {
        sort(begin(customers), end(customers), [] (Customer &a, Customer &b) {
                    return a.GetServiceTime() < b.GetServiceTime();
                    });
        avg_wait_time = 0;
        int size = customers.size();
        for (int i = 1;i < size;i++)
        {
            unsigned char t = customers[i - 1].GetServiceTime();
            customers[i].SetWaitTime(t + customers[i -1].GetWaitTime());
        }
        for (auto &it : customers)
        {
            avg_wait_time += it.GetWaitTime();
        }
        avg_wait_time /= size;
    }
private:
    vector<Customer>customers;
    static const int MAX_CUSTOMERS = 128;
};
int main()
{
    Service service;
    if (!service.Init(10))
    {
        return -1;
    }
    double avg_wait_time = 0;
    service.ComputeAvgWaitTime(avg_wait_time);
    cout << "average wait time = " << avg_wait_time << endl;

    return 0;
}
