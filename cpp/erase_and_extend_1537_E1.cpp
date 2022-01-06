#include <iostream>
#include <vector>
#include <string>

auto findOutput(const std::string& str, int K) -> std::string {
    std::string result{""};
    for(int i = 0; i < K; ++i) {
        result += str[i % str.length()];
    }
    return result;
}

auto compareStringsLexicographically(const std::string& a, const std::string& b) -> int  {
    for(int i = 0; i < a.length(); ++i) {
        if(a[i] > b[i]) {
            return 1;
        }
        else if(a[i] < b[i]) {
            return -1;
        }
    }
    return -1;
}

auto main() -> int {
    int N, K;
    std::cin >> N >> K;

    std::string s;
    std::cin >> s;

    std::string smallestString = findOutput(s, K);
    //std::cout << smallestString << std::endl;

    for(int i = 1; i <= s.length(); ++i) {
        std::string currentStr = findOutput(s.substr(0, i), K);
        //std::cout << i << std::endl;
        //std::cout << currentStr << std::endl;
        if(compareStringsLexicographically(currentStr, smallestString) < 0) {
            //std::cout << "Replacing" << smallestString << std::endl;
            smallestString = currentStr;
        }
    }
    std::cout << smallestString << std::endl;
}


/*
dbcadab
dbcadabdbcadabdb

dbcadcbc
dbcadcbcdbcadcbc
dbcadbcadbcadbca

407
jgfafdabagaahhiigfdgefbeidcheiigbahadcfabcdcbgfdebebighiieidfbbiggcadgigfaghaaifdaaegfbcghaibibagegecdhifhgfdffedhdagfgiaigecgadcehgiaedihabfdeegdihgbdfeibcbfaaihegcgfaagdhfhbdhgigaibidegdfhiahhdhhcbibaeiccccegbddeabcgdehbhhfaedacbcfhiigbigdggfgebibebgegbfhchgdebiaibhdighdiedcaeifgffadifadeeiahbebbafddfeeeihiacgecbdgdiidhhaehacgidbfeichgccacaabiaihaifghcebaafgigccgdcebiciagbbfhehddidheihbgcahhhhbafdcfkuscqftowcyqcxehwtrnxrbuhcnbtmnfloqhumfynidijhorkuonmqidzvigxljmvsteoaminyakvnfsvyveweouxqcfwieoc
jgfafdabagaahhiigfdgefbeidcheiigbahadcfabcdcbgfdebebighiieidfbbiggcadgigfaghaaifdaaegfbcghaibibagegecdhifhgfdffedhdagfgiaigecgadcehgiaedihabfdeegdihgbdfeibcbfaaihegcgfaagdhfhbdhgigaibidegdfhiahhdhhcbibaeiccccegbddeabcgdehbhhfaedacbcfhiigbigdggfgebibebgegbfhchgdebiaibhdighdiedcaeifgffadifadeeiahbebbafddfeeeihiacgecbdgdiidhhaehacgidbfeichgccacaabiaihaifghcebaafgigccgdcebiciagbbfhehddidheihbgcahhhhbafdcfkuscqftowcyqcxehwtrnxrbuhcnbtmnfloqhumfynidijhorkuonmqidzvigxljmvsteoaminyakvnfsvyveweouxqcfwieocjgfa
*/