#include <bits/stdc++.h>

using namespace std;

class Sales_data{

    public:
    Sales_data() = default;
    Sales_data(const Sales_data& );
    Sales_data& operator =(const Sales_data&);
    private:
        string bookNo;
        int units_sold = 0;
        double revenue = 0;
};

Sales_data::Sales_data(const Sales_data& o):
    bookNo(o.bookNo),units_sold(o.units_sold),revenue(o.revenue){};
Sales_data& 
Sales_data::operator=(const Sales_data& other){
    bookNo = other.bookNo;
    units_sold = other.units_sold;
    revenue = other.revenue;
    return *this;
}



int main()
{
   
   system("pause");
   return 0;
}
