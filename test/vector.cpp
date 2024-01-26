#include <iostream>
#include <vector>
class car {
    public:
};
int main()
{
    std::vector<int>list(3);
       for (auto element :list )
    {
    std::cin>>element;
    }


    std::vector<int>::iterator it;
    for(it = list.begin (); it != list.end() ; ++it)
    {
        std::cout<<*it;
    }
    list.push_back(4);

    for(int i=0 ; i<list.size ;i++)
    {
        std::cout<<list[i];
    }
 return 0;
}