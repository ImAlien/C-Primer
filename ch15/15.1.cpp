#include <iostream>

#include <string>

#include <vector>

using namespace std;

class Quote {

    public:
        std::string isbn() const;
        virtual double net_price(size_t n) const;
    private:
        string ISBN;
    protected:
        double price = 0.;
};

double Quote::net_price(size_t cnt) const {
    return cnt * price;
}
string Quote::isbn() const {
    return ISBN;
}




class Bulk_quote : public Quote {
    public:
        double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(size_t cnt) const {
    return cnt * price * 0.9;
}


double print_total(Quote& item, size_t n){
    
    double res = item.net_price(n);
    
    cout << "ISBN " << item.isbn() << " # sold " << n << " total value " << res << endl;
    return res;
}

int main(){

    Quote q1;
    Bulk_quote q2;
    print_total(q1, 5);
    print_total(q2, 5);
    getchar();
}