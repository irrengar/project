#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MySingleton{
public:
    static MySingleton* Instance;
    static MySingleton* getInstance();

private:
    MySingleton();
};
MySingleton* MySingleton::Instance= NULL;
MySingleton::MySingleton() {
    cout<<"in Constractor.."<<endl;
}
MySingleton* MySingleton::getInstance() {
    if(Instance==NULL)
        {
        Instance = new MySingleton();
        }
    return Instance;
}


