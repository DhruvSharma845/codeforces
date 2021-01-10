#include <iostream>
#include <vector>

int main() {
    int T{0}, x{0};
    std::cin>>T;

    for (size_t i = 0; i < T; i++) {
        std::string st;
        std::cin>>st;

        auto plusOp = st.find("++");
        if(plusOp != std::string::npos) {
            x+=1;
        }
        else {
            x-=1;
        }
    }
    std::cout << x << std::endl;
    std::vector<int> v{1, 2, 3};
    std::cout << v[10];
    v[10] = 5;
}