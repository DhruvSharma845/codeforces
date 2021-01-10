#include <iostream>

int main() {
    auto T{0};
    std::cin>>T;

    for (size_t i = 0; i < T; i++)
    {
        std::string st;
        std::cin>>st;

        if(st.size() > 10) {
            std::cout << st.at(0) << st.size() - 2 << st.at(st.size() - 1) << std::endl;
        }
        else {
            std::cout << st << std::endl;
        }
    }
    
}