#include <bits/stdc++.h>

using namespace std;


class StrVec{
    
    public:
        StrVec(initializer_list<string>s){
            auto newdata = alloc_n_copy(s.begin(), s.end());
            elements = newdata.first;
            first_free = cap = newdata.second;
        };
        StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(const StrVec&);
        StrVec& operator= (const StrVec&);
        ~StrVec();
        void push_back(const std::string&);
        void reserve(size_t size);
        void resize(size_t size);
        void resize(size_t new_size, const std::string&);
        size_t size() const{ return first_free - elements;}
        size_t capacity() const { return cap - elements;}
        std::string *begin() const {return elements;}
        std::string *end() const {return first_free;}
    private:
        static std::allocator<std::string> alloc;
        void chk_n_alloc(){
            if(size() == capacity()) reallocate();
        }
        std::pair<std::string*,std::string*> alloc_n_copy(const std::string* , const std::string*);
        void alloc_n_move(size_t sz);
        void free();
        void reallocate();
        std::string *elements;
        std::string* first_free;
        std::string* cap;
};

std::allocator<std::string> StrVec::alloc;

std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string *e){
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

// like reallocate
void StrVec::alloc_n_move(size_t sz)
{
    auto newdata = alloc.allocate(sz);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + sz;
}

void StrVec::reserve(size_t new_cap){
    if(new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}
void StrVec::resize(size_t new_size){
    resize(new_size, std::string());
}

void StrVec::resize(size_t new_size, const string& s){
    if(new_size > size()){
        if(new_size > capacity()){
            reserve(new_size * 2);
        }
        auto end = elements + new_size;
        for (auto i = first_free; i != end; i ++){
            alloc.construct(i, s);
        }
        first_free = end;
    }
    else{
        auto end = elements + new_size;
        while(first_free != end){
            alloc.destroy(--first_free);
        }
    }
}
void StrVec::push_back(const std::string& s){
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

void StrVec::free(){
    if(elements){
        for(auto p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}

StrVec::StrVec(const StrVec& s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec(){
    free();
}

StrVec& StrVec::operator=(const StrVec &other){
    auto data = alloc_n_copy(other.begin(),other.end());
    free();

    elements = data.first;

    first_free = cap = data.second;

    return *this;
}

void StrVec::reallocate(){
    auto newcapacity = size() ? 2*size() : 1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;

    auto elem = elements;
    
    for(size_t i = 0;i != size(); ++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();

    elements = newdata;

    first_free = dest;

    cap = elements + newcapacity;
}




int main(){
    cout << sizeof(StrVec) << endl;
    StrVec m1;
    cout << sizeof(m1) << endl;
    string a;
    a += "aa";
    string b;
    b += "bb";
    m1.push_back(a);
    m1.push_back(b);
    cout << sizeof(m1) << endl;
    StrVec m2 = m1;
    std::cout << m1.begin()->front();
    m1.begin()->front() = 'b';
    std::cout << m1.begin()->front();
    std::cout << m2.begin()->front();
    
    //

}