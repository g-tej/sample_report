#include <iostream>
#include<fstream>
#include <cstring>
//int display();
int add(int ,int);
int add(int ,int ,int);
float add(float,float);
int max(int,int,int);
using namespace std;

/*int main()/////////////////////Addition of two numbers///////////////////
{
    int a,b,c;
    cout<<"Enter the values of a and b"<<endl;
    cin>>a>>b;
    c=a+b;
    cout << "Adding of two numbers is :"<< c << endl;
    return 0;
}
*///////////////////////////
/*int main()////////////////////Printing the name entered by the user.
{
string name;
cout<<"Enter your name"<<endl;
//cin>>name;
getline(cin,name);//function which is used to take spaces between the strings.
cout<<"Name entered is "<<name<<endl;
return 0;
}*//////////////////////
/*****int main()///////char array using for loop///////
{
char arr[4]={'A',49,'C',52};
for(int i=0;i<4;i++)
{
cout<<arr[i]<<endl;
}
}*/////////////////
/*int main()////////array using for each loop
{
char arr[4]={'A',49,69,97};
for(char x:arr)
{
cout<<x<<endl;
}
}*////////////////
/*int main()///////////Sum of elements in array
{
int n,sum=0;
cout<<"Enter no of elements in array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter elements of array"<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
for(int i=0;i<n;i++)
{
sum=sum+arr[i];
}
cout<<"sum of array of elements is "<<sum;
}*/////////////
/*int main()////////////Maximum element in array
{
int n,max;
cout<<"Enter no of elements in array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter elements of array"<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
max=arr[0];
for(int i=1;i<n;i++)
{
if(arr[i]>max)
{
max=arr[i];
}
}
cout<<"maximum element in arr is "<<max;
}*////////////////
/*int main()/////////////Linear search
{
int n,key;
cout<<"Enter no of elements in array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter elements of array"<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"Enter the key to check"<<endl;
cin>>key;
for(int i=0;i<n;i++)
{
if(arr[i]==key)
{
    cout<<"key is found at "<<i<<" position"<<endl;
    return 0;
}
}
cout<<"Key is not found";
}*////////////////////////
///////////////////////////////////////////////////////////////pointers/////////////////////////////////////////////
/*int main()
{
int x=10;
int *p;
p=&x;
cout<<x<<endl;
cout<<&x<<endl;
cout<<p<<endl;
cout<<&p<<endl;
cout<<*p<<endl;
}*/////////////////////
/*int main()////////
{
int n;
cout<<"Enter the no of elements"<<endl;
cin>>n;
int arr[n];
int *p;
p=arr;
cout<<"Enter the elements of array"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<arr[0]<<endl;
cout<<&arr<<endl;
cout<<*p<<" "<<p<<endl;
cout<<*(p+1)<<" "<<(p+1)<<endl;
cout<<*(p+2)<<" "<<(p+2)<<endl;
}*/////////////////////
/*int main()////////////Distance between two pointers
{
    int arr[6]={1,2,3,4,5,6};
    int *p=arr,*q=&arr[5];
    int distance=q-p;
    cout<<"Distance between two pointers is : "<<distance<<endl;
}*/////////////////////////////////////////////////////
/*int main()////////////////reference
{
int A[]={2,4,6,8,10,12};

int *p=&A[3];

cout<<p[-2];
}*/////////////////////////
/*int main()////////string
{
char str[10]={'h','e','l','l','o','\0'};
cout<<str<<endl;
char *s="hello";
cout<<s<<endl;
string strg ="hiii";
cout<<strg<<endl;
}*//////////////////
/*int main()///////////using get function
{
char s[30],s1[30];
cout<<"Enter the string"<<endl;
cin.get(s,30);
cout<<s<<endl;
cin.ignore();
cout<<"Enter the string"<<endl;
cin.get(s1,30);
cout<<s1;
}*///////////////
/*int main()//////////using getline function
{
char s[30],s1[30];
cout<<"Enter the string"<<endl;
cin.getline(s,30);
cout<<s<<endl;
cin.ignore();
cout<<"Enter the string"<<endl;
cin.getline(s1,30);
cout<<s1;
}*//////////////////////////////////////
/*int main()////////////////////////////
{
char str1[30]="goood";
char str2[20]="morning";
int len1=strlen(str1);
int len2=strlen(str2);
cout<<len1<<" "<<len2<<endl;
strcat(str1,str2);
cout<<str1<<endl;
strncat(str1,str2,4);
cout<<str1<<endl;
strcpy(str1,str2);
cout<<str1<<endl;
strncpy(str1,str2,3);
cout<<str1<<endl;
}*////////////////////////////////////
/*int main()
{
char str1[20]="programming";
char str2[10]="gram";
cout<<strstr(str1,str2)<<endl;
cout<<strchr(str1,'g')<<endl;
cout<<strrchr(str1,'r')<<endl;
}*////////////////////////////////////
/*int main()/////////////////////
{
    string s="welcome";
    char str[20];
    //s.copy(str,s.length());
    //cout<<str<<endl;
    //str.clear();
    s.copy(str,5);
    cout<<str<<endl;
}*///////////////////////////////
/*int main()/////displaying msg using function
{
display();
}
int display()
{
cout<<"Hello World!";
}*////////////////////////////////
/*int main()////////addition of two numbers using function
{
int a,b,c;
cout<<"Enter the values of a and b"<<endl;
cin>>a>>b;
c=add(a,b);
cout<<"addition of two numbers is : "<<c<<endl;
}
int add(int x,int y)
{
int z;
z=x+y;
return z;
}*////////////////////////////////////////
/*int main()/////////////////////
{
int a,b,c;
cout<<"Enter the values of a,b,c"<<endl;
cin>>a>>b>>c;
int d=max(a,b,c);
cout<<"max of numbers is : "<<d<<endl;
}
int max(int x,int y,int z)
{
if(x>y&&x>z)
{
return x;
}
else if(y>z)
{
return y;
}
else
{
return z;
}
}*///////////////////////////////////////////////
/*int main()/////////Function overloading
{
int a,b,c;
cout<<"Enter the values of a,b "<<endl;
cin>>a>>b;
float x,y,z;
cout<<"Enter the values of x,y "<<endl;
cin>>x>>y;
int d,e,f,g;
cout<<"Enter the values of d,e,f "<<endl;
cin>>d>>e>>f;
c=add(a,b);
z=add(x,y);
g=add(d,e,f);
cout<<"addition is :"<<c;
cout<<"addition is :"<<z;
cout<<"addition is :"<<g;
}
int add(int a,int b)
{
    int c=a+b;
    return c;
}
int add(int d,int e,int f)
{
int g= d+e+f;
return g;
}
float add(float x,float y)
{
float z=x+y;
return z;
}*/////////////////////////////
/*template <class T>/////////Function template//////
T Max(T a,T b)
{
if(a>b)
{
return a;
}
else
{
return b;
}
}
int main()
{
int a,b;
float c,d;
cout<<"Enter the values of a,b "<<endl;
cin>>a>>b;
cout<<"Enter the values of c,d"<<endl;
cin>>c>>d;
cout<<Max(a,b)<<endl;
cout<<Max(c,d)<<endl;
}*///////////////////////////////////////////////////
/*class area////////////////using class///////////
{
private :
        int len;
        int breadth;
public:
        void setdata(int a,int b)
        {
        if(len>0||breadth>0)
        {
        len=a;
        breadth=b;
        //cout<<"Enter the values of len and breadth"<<endl;
        //cin>>a>>b;
        }
        else
        {
        len =1;
        breadth=1;
        }
        }
        void getdata(int a,int b)
        {
         return a;
         //return b;
        }
        void display()
        {
        cout<<"Area is :"<<(len*breadth)/2<<endl;
        }
};
int main()
{
area triangle;//giving name to class
area *ptr;//using pointer
area *ptr2;
ptr2=new area;//creating pointer in heap memory
ptr=&triangle;
triangle.data(5,6);// through class
triangle.display();
ptr->data(5,6);//through pointer
ptr->display();
ptr2->data(5,6);//through pointer from heap
ptr2->display();
triangle.setdata(5,6);
triangle.display();
return 0;
}*/////////////////
////////////////////////constructors///////////////////////////
/*class area
{
private:
        int length;
        int breadth;
public:
       area(int l,int b)
       {
          length=l;
          breadth=b;
       }
       area(area &rectangle1)//////deep copy///////
       {
       length=rectangle1.length;
       breadth=rectangle1.breadth;
       }
       void display();
       ~area()
       {
           cout<<"Area is destructed"<<endl;
       }
};
void area::display()
 {
        cout<<"The Area is : "<<(length*breadth)<<endl;
}
int main()
{
    area rectangle(5.6f,7);
    rectangle.display();
    area rectangle1(rectangle);
    rectangle.display();
    return 0;
}*/
/*class area
{
private:
        int length;
        int breadth;
public:
       area()
       {
        cout<<"Enter the values of length and breadth"<<endl;
        cin>>length>>breadth;
       }
      int display();
};
inline int area::display()
{
       cout<<"Area is :"<<(length*breadth)<<endl;
}
int main()
{
    area rectangle;
    rectangle.display();
}*///////////////////////////////////////////
/*class you;///////friend function/////////
class me
{
    public:int a;
    protected:int b;
    private: int c;
    friend you;
};
class you
{
public:
    me m;
    void fun()
    {
        m.a=10;
        m.b=15;
        m.c=20;
        cout<<m.a<<" "<<m.b<<" "<<m.c<<endl;
    }
};
int main()
{
    you y;
    y.fun();
}*////////////////////////////////////////////////////
/*class student
{
public:
    int roll;
    string name;
    static int addNo;
public:
    student(string n)
    {
        addNo++;
        roll=addNo;
        name=n;
    }
    void display()
    {
        cout<<"Name of student is :"<<name<<endl<<"Roll no of student is :"<<roll<<endl;
    }

};
int student::addNo=0;

int main()
{
    student s1("Teja");
    student s2("santosh");
    student s3("sanketh");
    student s4("rohith");
    student s5("neeraj");
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    cout<<"NO of addmissions are:"<<student::addNo<<endl;
}*/////////////
/*int division(int a,int b)
{
    if(b==0)
    {
        throw 1;
    }
    else
    {
      return a/b;
    }
}
int main()
{
    int x,y,z;
    cout<<"Enter the values of x,y "<<endl;
    cin>>x>>y;
    try
    {
     z=division(x,y);
     cout<<"Division is :"<<z<<endl;
    }
    catch(int e)
    {
        cout<<"Division is not possible : "<<e<<endl;
    }
    return 0;
}*//////////////////////////


