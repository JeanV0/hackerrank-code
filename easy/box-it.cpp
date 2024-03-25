#include<bits/stdc++.h>

using namespace std;

class Box {
    private:
        int length = 0;
        int breadth = 0;
        int height = 0;
    public:
        Box(){

        }
        Box(int lenght , int breadth, int height){
            this->length = lenght;
            this->breadth = breadth;
            this->height = height;
        }

        Box(const Box& box){
            this->length = box.length;
            this->breadth = box.breadth;
            this->height = box.height;
        }

        int getBreadth(){
            return this->breadth;
        }

        int getLength(){
            return this->length;
        }

        int getHeight (){
            return this->height;
        }

        long long CalculateVolume(){
            return (long long)length * breadth * height;
        }

        friend bool operator < ( Box&A,Box& B){
            if( (A.length < B.length) || ((A.breadth < B.breadth) && (A.length == B.length)) || ((A.height < B.height) && (A.breadth == B.breadth) && (A.length == B.length)) ){
                return true;
            }
            else{
                return false;
            }
        };

        friend std::ostream& operator<<(std::ostream& out, const Box& B) {
            out << B.length << " " << B.breadth << " " << B.height;
            return out;
        }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}