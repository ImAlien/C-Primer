
#include <bits/stdc++.h>

using namespace std;

class StrBlob{
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
    public:
        StrBlob();
        StrBlob(std::initializer_list<std::string> il);
        size_type size() const {return data->size();}
        bool empty() const {return data->empty();}
        void push_back(const std::string& t) {data->push_back(t);}
        void pop_back();

        std::string& front();
        std::string& back();
        const string& front()const ;
        const string& back()const;
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string& msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}


void StrBlob::check(size_type i, const string& msg)const{
    if(i >= data->size()){
        throw out_of_range(msg);
    }
}

std::string& StrBlob::front(){
    check(0,"empty StrBlob");
    return data->front();
}

const string& StrBlob::front()const{
    check(0,"empty StrBlob");
    return data->front();
}

std::string& StrBlob::back(){
    check(0,"empty");
    return data->back();
}

const std::string& StrBlob::back()const {
    check(0,"empty");
    return data->back();
}
void StrBlob::pop_back(){
    check(0,"empty Blob");
    data->pop_back();
}


class StrBlobPtr{
    public:
        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob& a, size_t sz = 0):
            wptr(a.data), curr(sz){}
    private:
        shared_ptr<vector<string>> check(size_t ,const std::string& ) const;
        weak_ptr<vector<string>> wptr;
        size_t curr;
};

int main(){

    
    
    
}