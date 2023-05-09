#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}


using namespace std;
namespace cxl{
    template<typename T>
    class shared_ptr{
        private:
            T* ptr;
            int* cnt;
        public:
        shared_ptr(T* ptr):ptr(ptr),cnt(new int(1)){
            std::cout << "shared_ptr " << this << " constructed!\n\n";
        }
        shared_ptr(shared_ptr<T>& other){
            ++*other.cnt;
            ptr = other.ptr;
            cnt = other.cnt;
             std::cout << "shared_ptr " << this<< " copied from share_ptr " << &other << std::endl;
        }
        shared_ptr(shared_ptr<T>&& other){
            ptr = other.ptr;
            cnt = other.cnt;
            other.ptr = other.cnt = nullptr;
        }
        ~shared_ptr(){
            if(cnt != nullptr && --(*cnt) == 0) {
                delete ptr;
                delete cnt;
            }
            ptr = nullptr;
            cnt = nullptr;
             std::cout << "shared_ptr " << this << " deconstructed!\n\n";
        }
        shared_ptr<T>& operator =(shared_ptr<T>& other){
            if(this != &other){
                ++ *other.cnt;
                if(cnt != nullptr && --(*cnt) == 0) {
                    delete ptr;
                    delete cnt;
                }
                ptr = other.ptr;
                cnt = other.cnt;
            }
            return *this;
        }
        T& operator *(){
            return *ptr;
        }
        T* operator ->(){
            return ptr;
        }
    public:
        int useCount(){
            return cnt ? *cnt : 0;
        }
        void release(){
            if(cnt != nullptr && --(*cnt) == 0) {
                delete ptr;
                delete cnt;
            }
            ptr = nullptr;
            cnt = nullptr;
             std::cout << "shared_ptr " << this << "  release\n\n";
        }

    };
}

void process(cxl::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.useCount() << "\n";
}
int main()
{
    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p)); // default use the move
    cxl::shared_ptr<int> cxlp(new int(42));
    process(cxl::shared_ptr<int>(cxlp));
    auto q = p;
    process(q);
    /**
    * codes below shows how the reference count change.
    */
    // std::cout << p.use_count() << "\n";
    // auto q = p;
    // std::cout << p.use_count() << "\n";
    // std::cout << "the int p now points to is:" << *p << "\n";
    return 0;
}