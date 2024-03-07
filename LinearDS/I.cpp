    #include<iostream>
    #include<queue>
    using namespace std;
    
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    
    int main()
    {
        int n,i=0;
        cin>>n;
        queue<long long> two,three,five;
        five.push(5);
        three.push(3);
        two.push(2);
        while(i!=n)
        {
            if(two.front()<five.front()&&two.front()<three.front())
            {
                long long x=two.front();
                cout<<x<<" ";
                three.push(x*3);
                five.push(x*5);
                two.push(x*2);
                two.pop();
            }
            else if(three.front()<five.front()&&three.front()<two.front())
            {
                long long x=three.front();
                cout<<x<<" ";
                three.push(x*3);
                five.push(x*5);
                three.pop();
            }
            else
            {
                long long x=five.front();
                cout<<x<<" ";
                five.push(x*5);
                five.pop();
            }
            i++;
        }
 
    }
     
 
