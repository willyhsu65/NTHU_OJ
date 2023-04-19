#include<iostream>

using namespace std;


class String_Calculator {
    public:
        String_Calculator(){};
        String_Calculator(const string);
        String_Calculator& Add(const string);
        String_Calculator& Subtract(const string);
        String_Calculator& DividedBy(const string);
        void output() const;

    private:
        string s = "";
};

String_Calculator::String_Calculator(const string name)
{
    s = name;
}

String_Calculator &String_Calculator :: Add (const string str)
{
    this->s = this->s + str;
    return *this;
}

String_Calculator &String_Calculator :: Subtract (const string str)
{
    std::size_t found = this->s.find(str);
    if (found == string::npos)
    {
        this->s = "error";
        return *this;
    }
    std::size_t len = str.size();
    s.erase(found,len);
    return *this;
}

int times;
String_Calculator &String_Calculator :: DividedBy (const string str)
{
    std::size_t len = str.size();
    times = 0;
    std::size_t found = this->s.find (str);
    
    while (found != string::npos)
    {
        cout<<"found :"<<found<<"times:"<<times<<endl;
        times++;
        found = this->s.find(str,found + 1);
        cout<<"found :"<<found<<"times:"<<times<<endl;
    }
    return *this;
}

void String_Calculator::output() const
{
    cout<<times<<endl;
    return;
}

int main(){
    int n;
    string x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        String_Calculator a(x), ans;
        ans = a.Subtract(y);
        ans.output();
        ans = ans.Add(y);
        ans.output();
        ans = ans.DividedBy(y);
        ans.output();
    }
}