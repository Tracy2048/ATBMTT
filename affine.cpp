#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int oclitMoRong(int r0, int r1){
    int r[100],q[100],s[100],t[100];
    r[0]=r0;
    r[1]=r1;
    s[0]=1;t[0]=0;
    s[1]=0;t[1]=1;
    int i=0;
    while(true){
        q[i+1]=r[i]/r[i+1];
        r[i+2]=r[i]%r[i+1];
        if(i>1){
            s[i]=s[i-2]-q[i-1]*s[i-1];
            t[i]=t[i-2]-q[i-1]*t[i-1];
        }
        if(r[i+2]==0) break;
        i++;
    }
    i++;
    s[i]=s[i-2]-q[i-1]*s[i-1];
    t[i]=t[i-2]-q[i-1]*t[i-1];
    return t[i]>0 ? t[i] : t[i]+r0;
}
string affine(string s, int a, int b){
    string res="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            res+=(char)(((a*(s[i]-'A')+b)%26)+'A');
        }else{
            res+=(char)(((a*(s[i]-'a')+b)%26)+'a');
        }
    }
    return res;
}
int main(){
    int a,b,a1;
    cout<<"Nhap a = ";
    cin>>a;
    while(gcd(a,26)!=1){
        cout<<"Khoa a khong hop le, nhap lai a = ";
        cin>>a;
    }
    cout<<"Nhap b = ";
    cin>>b;
    a1 = oclitMoRong(26,a);
    cout<<"Khoa giai ma (a^-1, b) = ("<<a1<<", "<<b<<")"<<endl;
    //cau2
    string s1, s2;
    cout<<"Nhap xau ki tu 1: ";
    cin>>s1;
    cout<<"Nhap xau ki tu 2: ";
    cin>>s2;
    if(affine(s1,a,b)==s2){
        cout<<"Ban da nhap dung";
    }else{
        cout<<"Ban da nhap sai";
    }
}
