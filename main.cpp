#include<bits/stdc++.h>
using namespace std;

class HashSet
{
    public:

       int bucket_size=100;
       int size;
       double loadfactor=0.75;
       vector<list<int>>arr;

       HashSet()
       {
           size=0;
           list<int>lt;
           for(int i=0;i<bucket_size;i++)arr.push_back(lt);

       }

       void Resize()
       {
           size=0;

           vector<list<int>>vec(arr.size());
           swap(arr,vec);
           arr.resize(bucket_size);

           for(int i=0;i<vec.size();i++)
           {
               for(auto it:vec[i])
               {
                   Add(it);
               }
           }
       }

       int Hashkey(int key)
       {
           return key%bucket_size;
       }
       list<int>::iterator Search(int key)
       {
           int h=Hashkey(key);
           return find(arr[h].begin(),arr[h].end(),key);
       }


       void Add(int key)
       {
          // size++;
           int h=Hashkey(key);
           auto it=Search(key);
           if(it==arr[h].end())
           {
               size++;
               arr[h].push_back(key);
           }
           
           if((double)size>bucket_size*loadfactor)
           {
               bucket_size*=2;
               Resize();
           }
       }
       void Remove(int key)
       {
           int h=Hashkey(key);
           auto it=Search(key);
           if(it!=arr[h].end())
           {
               size--;
               arr[h].erase(it);
           }

           if((double)size<0.5*loadfactor*bucket_size)
           {
               bucket_size/=2;
               Resize();
           }
       }

       bool IsPresent(int key)
       {
           int h=Hashkey(key);
           auto it=Search(key);
           if(it!=arr[h].end())return 1;

           return 0;
       }

};

int main()
{
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout<<"Hello world"<<endl;

    HashSet h1;
    h1.Add(1);
    h1.Add(2);
    h1.Add(3);
    cout<<h1.IsPresent(2)<<endl;

}