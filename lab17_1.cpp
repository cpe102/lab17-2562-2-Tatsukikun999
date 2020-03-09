#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<vector>

using namespace std;

string lower(string x){

  for(int i=0;i<x.size();i++)        
         {
             
             x[i]=tolower(x[i]);
         
         }

         return x;
}

int main()
{
    ifstream fin("name_score.txt");
    vector<string> v_name,v_grade;
    string s;
    int score,a,b,c;
        char name[100];
        while(getline(fin,s))
    {
       
        sscanf(s.c_str(),"%[^:]:%d %d %d",name,&a,&b,&c);
        score=a+b+c;
       
        v_name.push_back(name);
        string grade = (score >= 80 ? "A": score >= 70 ? "B" : score >= 60? "C" : score >= 50 ? "D":"F");
       v_grade.push_back(grade);
    }
    string n;
    while(true)
    {
        bool ch=0;
        int j=0;
        
        cout << "Please input your command : ";
         getline(cin,s);
         
        int  idx = s.find_first_of(" ");
        
         string s1 = lower(s.substr(0,idx));
         string s2 = lower(s.substr(idx+1,s1.size()));
        
        if(s1=="exit")
        {
            break;
        }

         else if(s1=="name"){
             
               for(int i=0;i<v_name.size();i++)
               {
                   
                   if(s2==lower(v_name[i]))
                   {
                       cout << v_name[i] << "'s = " << v_grade[i] << "\n";
                       ch=1;
                   }
                   else if (ch!=1 && i+1>v_name.size())
                   {
                       cout << "Cannot found\n";
                   }
               } 

                
                 

         } 
          else if(s1=="grade")
        {
            
            for(int i=0;i<v_name.size();i++)
               {
                 
                   int j;
                
                   if(s2==lower(v_grade[i]))
                   {
                       cout << v_name[i] <<"\n";
                       ch=1;
                   }
                   
                else if(ch!=1 && i+1==v_name.size())
                   {
                       cout << "Cannot found\n";
                   }
               } 
       
        }    
         else{
             cout << "Invalid Command\n";
         }
       

    
    }
   
    





}
