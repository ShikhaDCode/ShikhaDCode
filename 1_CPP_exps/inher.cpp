#include <iostream>

using namespace std;

class Job {
protected:
    int package;
    std::string skill;
    int yearsExp;

public:
    Job(int pack, std::string sk, int exp) : package(pack), skill(sk), yearsExp(exp)
    {}

    virtual bool isEnough();
};

class Doctor : public Job {
public:
    Doctor(int pack, std::string sk, int exp) : Job(pack, sk, exp) {}

    bool isEnough() override;
};

bool Job::isEnough()
{
    cout << "Hello this is Job the bob!!" << endl;
    if(yearsExp >= 8){
        if(package >= 25){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Doctor::isEnough()
{
    cout << "Hello this is doctor!" << endl;
    if(yearsExp >= 8){
        if(package >= 50){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main()
{
    Job jo(10, "programming", 6);

    cout << (jo.isEnough() ? "yes!!" : "No!!!") << endl;
    Doctor doc(60, "surgery", 10);

    cout << (doc.isEnough() ? "yes!!" : "No!!!") << endl;

    return 0;
}
