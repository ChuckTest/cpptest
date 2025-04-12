#include<iostream>
using namespace std;
#include<cmath>

class Converter{
    public:
    static void DecimalToBinary(int number){

    }

    static void BinaryToDecimal(string str){
        int length=str.size();
        int number=0;
        int count=0;
        for(int i=length-1;i>=0;i--){
            if(str[i]=='1'){
                number+=pow(2,count);
            }
            count++;
        }
        cout<<str<<" map to decimal "<<number<<endl;
    }

};

int main(){
    Converter::BinaryToDecimal("11010101");
    Converter::DecimalToBinary(15);
    return 0;
}