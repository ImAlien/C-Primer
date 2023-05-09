
#include <bits/stdc++.h>
#include <set>
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
            ISBN = other.ISBN;
            price = other.price;
            other.ISBN = nullptr;
        }
        virtual Quote* clone() const& {return new Quote(*this);};
        virtual Quote* clone() && {return new Quote(std::move(*this));}
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

    Bulk_quote* clone() const& {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
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

class Basket {
    public :
        void add_item(const std::shared_ptr<Quote>& sale){
            items.insert(sale);
        }
        void add_item(const Quote& sale){
            items.insert(std::shared_ptr<Quote>(sale.clone()));
        }
        void add_item(Quote&& sale){
            items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
        }
        double total_receipt(std::ostream& )const;
    private:
        static bool compare(const std::shared_ptr<Quote>& lhs,
                            const std::shared_ptr<Quote> &rhs)
        {return lhs->isbn() < rhs->isbn(); }


        std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};

};

double print_total(ostream& os, Quote& item, size_t n){
    
    double res = item.net_price(n);
    
    os << "ISBN " << item.isbn() << " # sold " << n << " total value " << res << endl;
    return res;
}
double Basket::total_receipt(ostream& os)const{
    double sum = 0.;
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale:" << sum << endl;
    return sum;
}
int main(){


}