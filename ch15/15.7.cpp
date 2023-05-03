#include <iostream>

#include <string>

#include <vector>

using namespace std;

class Quote {

    public:
        Quote() = default;
        Quote(const string& book, double price):ISBN(book), price(price){};
        Quote(const Quote& other){
            ISBN = other.ISBN;
            price = other.price;
            cout << "Quote Copy Constructor" << endl;
        }
        Quote(Quote&& other){
            

        }
        std::string isbn() const;
        virtual double net_price(size_t n) const;
        virtual ~Quote() = default;
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
    Bulk_quote() = default;
    Bulk_quote(const string&book, double p, size_t cnt, double discount):
    Quote(book, p),min_qty(cnt),discount(discount){};

        double net_price(std::size_t) const override;
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};
class Little_quote : public Quote{

    public :
    Little_quote () = default;

    Little_quote(const string& book, double price, size_t max_cnt, double discount):
    Quote(book, price),max_qty(max_cnt), discount(discount){};
    
    double net_price(size_t cnt) const override{
        if(cnt <= max_qty) 
            return cnt * price * (1 - discount);
        return cnt * price - max_qty * price * discount;

    }
    private:
        size_t max_qty = 0;
        double discount = 0.;

};

double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty) 
        return cnt * price * (1 - discount);
    return cnt * price;
}


double print_total(Quote& item, size_t n){
    
    double res = item.net_price(n);
    
    cout << "ISBN " << item.isbn() << " # sold " << n << " total value " << res << endl;
    return res;
}

int main(){

    Quote q1("A", 3);
    Bulk_quote q2("A",3, 4, 0.1);
    Little_quote q3("A",3,4,0.1);
    print_total(q1, 5);
    print_total(q2, 5);
    print_total(q3,5);
    getchar();
}